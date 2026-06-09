using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Bloggy.Migrations
{
    /// <inheritdoc />
    public partial class AddUrlHandleToBlog : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<string>(
                name: "UrlHandle",
                table: "Blogs",
                type: "nvarchar(max)",
                nullable: true);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "UrlHandle",
                table: "Blogs");
        }
    }
}
