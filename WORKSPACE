load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "rules_vulkan",
    remote = "https://github.com/jadarve/rules_vulkan.git",
    tag = "v0.0.6"
)

load("@rules_vulkan//vulkan:repositories.bzl", "vulkan_repositories")
vulkan_repositories()

http_archive(
    name = "glfw",
    build_file = "//lib/glfw:glfw.BUILD",
    sha256 = "e02d956935e5b9fb4abf90e2c2e07c9a0526d7eacae8ee5353484c69a2a76cd0",
    strip_prefix = "glfw-3.3.7",
    urls = ["https://github.com/glfw/glfw/archive/3.3.7.zip"],
)

new_git_repository(
    name = "imgui",
    build_file = "//lib/imgui:imgui.BUILD",
    commit = "7b5a8e4f2bbc06eac3b913a7f7df67edff99c538",
    remote = "https://github.com/ocornut/imgui",
)
