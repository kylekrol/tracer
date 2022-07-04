load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

GLM_VERSION = "0.9.9.8"
http_archive(
    name = "glm",
    build_file = "//lib/glm:glm.BUILD",
    sha256 = "7d508ab72cb5d43227a3711420f06ff99b0a0cb63ee2f93631b162bfe1fe9592",
    strip_prefix = "glm-{}".format(GLM_VERSION),
    urls = ["https://github.com/g-truc/glm/archive/refs/tags/{}.tar.gz".format(GLM_VERSION)],
)

new_git_repository(
    name = "imgui",
    build_file = "//lib/imgui:imgui.BUILD",
    commit = "7b5a8e4f2bbc06eac3b913a7f7df67edff99c538",
    remote = "https://github.com/ocornut/imgui",
)

new_git_repository(
    name = "walnut",
    build_file = "//lib/walnut:walnut.BUILD",
    commit = "cc26ee1cc875db50884fe244e0a3195dd730a1ef",
    remote = "https://github.com/TheCherno/Walnut",
)

new_local_repository(
    name = "libglfw",
    path = "/usr",
    build_file = "//lib/libglfw:libglfw.BUILD",
)

new_local_repository(
    name = "libvulkan",
    path = "/usr",
    build_file = "//lib/libvulkan:libvulkan.BUILD",
)
