
using Bloggy.Context;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace Bloggy.Controllers
{
    [Authorize(Roles = "Admin")]
    public class AdminController : Controller
    {
        private readonly BlogDbContext _context;

        public AdminController(BlogDbContext context)
        {
            _context = context;
        }

        public IActionResult Index()
        {
             var blogs = _context.Blogs.ToList();
            return View(blogs);
        }

        public IActionResult Delete(int id)
        {
            var blog = _context.Blogs.FirstOrDefault(x => x.Id == id);
            if (blog != null)
            {
                _context.Blogs.Remove(blog);
                _context.SaveChanges();
            }
            return RedirectToAction("Index");
        }
    }
}
