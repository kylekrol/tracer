load("@rules_cc//cc:defs.bzl", "cc_import", "cc_library")

cc_import(
    name = "libglfw-private",
    hdrs = glob(["include/GLFW/**/*.h", "include/GLFW/**/*hpp"]),
    shared_library = "lib/libglfw.so",
    visibility = ["//visibility:private"],
)

cc_library(
    name = "libglfw",
    hdrs = glob(["include/GLFW/**/*.h", "include/GLFW/**/*hpp"]),
    deps = [":libglfw-private"],
    includes = ["include"],
    visibility = ["//visibility:public"],
)
