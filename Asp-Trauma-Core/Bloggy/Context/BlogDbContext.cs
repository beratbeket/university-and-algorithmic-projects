using Bloggy.Models;
using Microsoft.EntityFrameworkCore;

namespace Bloggy.Context
{
    public class BlogDbContext : DbContext
    {
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer("Data Source=YOUR_SERVER_NAME\\SQLEXPRESS; Database=BloggyDb; Integrated Security=True; TrustServerCertificate=True");
        }
        public DbSet<Blog> Blogs { get; set; }
        public DbSet<Comment> Comments { get; set; }
        public DbSet<User> Users { get; set; }
    }
}
