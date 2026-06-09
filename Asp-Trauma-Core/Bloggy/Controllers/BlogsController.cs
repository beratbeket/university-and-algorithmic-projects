using Bloggy.Context;
using Bloggy.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace Bloggy.Controllers
{
    public class BlogsController : Controller
    {
        private readonly BlogDbContext _context;
        public BlogsController(BlogDbContext context)
        {
            _context = context;
        }

        public IActionResult Index()
        {
            var blogs = _context.Blogs.Where(x => x.Status == 1).ToList();
            //veritabanında blogs veritabanının içinde statusu 1 olanları listeye kaydeder
            return View(blogs);
        }
        public IActionResult Details(string id)
        {
            if (string.IsNullOrEmpty(id))
            {
                return NotFound();
            }

            var blog = _context.Blogs.FirstOrDefault(x => x.UrlHandle == id);

            // Fallback to ID look up if not found by UrlHandle (for backward compatibility if needed)
            if (blog == null && int.TryParse(id, out int blogId))
            {
                 blog = _context.Blogs.FirstOrDefault(x => x.Id == blogId);
            }

            if(blog == null)
            {
                return NotFound();
            }

            blog.ViewCount += 1;
            _context.SaveChanges();
            var comment = _context.Comments.Where(x => x.BlogId == blog.Id).ToList();
            ViewBag.Comments = comment.ToList();
            return View(blog);

        }
        [HttpPost]
        [Authorize]
        public IActionResult CreateComment(Comment model)
        {
            model.PublishDate = DateTime.Now;
             // Auto-fill Name from logged in user if available
            if (User.Identity.IsAuthenticated)
            {
                model.Name = User.Identity.Name;
            }
            
            _context.Comments.Add(model);
            
            var blog = _context.Blogs.Where(x => x.Id == model.BlogId).FirstOrDefault();
            if(blog != null)
                blog.CommentCount += 1;

            _context.SaveChanges();
            // Redirect using the UrlHandle if available
            if (blog != null && !string.IsNullOrEmpty(blog.UrlHandle))
            {
                 return RedirectToAction("Details", new { id = blog.UrlHandle });
            }
            return RedirectToAction("Details", new { id = model.BlogId });   
        }

        [Authorize]
        public IActionResult Create()
        {
             return View();
        }

        [HttpPost]
        [Authorize]
        public IActionResult Create(Blog model)
        {
             model.PublishDate = DateTime.Now;
             model.Status = 1; // Active
             model.CreateDate = DateTime.Now;
             model.AuthorName = User.Identity.Name; // Save the author's name
             
             // Generate Slug
             model.UrlHandle = GenerateSlug(model.Name);

             _context.Blogs.Add(model);
             _context.SaveChanges();
             return RedirectToAction("Index");
        }

        [Authorize]
        public IActionResult Edit(int id)
        {
            var blog = _context.Blogs.FirstOrDefault(x => x.Id == id);
            if (blog == null)
                return NotFound();

            // Check if user is the author or an admin
            if (blog.AuthorName != User.Identity.Name && !User.IsInRole("Admin"))
            {
                return Forbid(); // 403 Forbidden
            }

            return View(blog);
        }

        [HttpPost]
        [Authorize]
        public IActionResult Edit(Blog model)
        {
            var blog = _context.Blogs.FirstOrDefault(x => x.Id == model.Id);
            if (blog == null)
                return NotFound();

            // Check if user is the author or an admin
            if (blog.AuthorName != User.Identity.Name && !User.IsInRole("Admin"))
            {
                return Forbid();
            }

            // Update blog properties
            blog.Name = model.Name;
            blog.Description = model.Description;
            blog.ImageUrl = model.ImageUrl;
            blog.Tags = model.Tags;
            
            // Update slug if name changes or if it was empty
            // For simplicity, we can regenerate it always or check if null.
            // Let's regenerate to keep it in sync with title.
            blog.UrlHandle = GenerateSlug(model.Name);

            _context.SaveChanges();
            return RedirectToAction("Details", new { id = blog.UrlHandle });
        }
        
        private string GenerateSlug(string title)
        {
            if (string.IsNullOrEmpty(title))
                return string.Empty;

            string slug = title.ToLower();
            
            // Remove special chars - simple version
            slug = slug.Replace("ş", "s").Replace("ı", "i").Replace("ğ", "g").Replace("ü", "u").Replace("ö", "o").Replace("ç", "c");
            slug = System.Text.RegularExpressions.Regex.Replace(slug, @"[^a-z0-9\s-]", "");
            slug = System.Text.RegularExpressions.Regex.Replace(slug, @"\s+", " ").Trim();
            slug = slug.Replace(" ", "-");

            // Append random string/timestamp if you want uniqueness, but for now simple slug
            return slug;
        }


        public IActionResult About()
        {
            return View();
        }
        public IActionResult Contact()
        {
            return View();
        }
        public IActionResult Support()
        {
            return View();
        }
    }
}
