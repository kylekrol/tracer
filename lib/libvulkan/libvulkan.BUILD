load("@rules_cc//cc:defs.bzl", "cc_import", "cc_library")

cc_import(
    name = "libvulkan-private",
    hdrs = glob(["include/vulkan/**/*.h", "include/vulkan/**/*hpp"]),
    shared_library = "lib/libvulkan.so",
    visibility = ["//visibility:private"],
)

cc_library(
    name = "libvulkan",
    hdrs = glob(["include/vulkan/**/*.h", "include/vulkan/**/*hpp"]),
    deps = [":libvulkan-private"],
    includes = ["include"],
    visibility = ["//visibility:public"],
)
