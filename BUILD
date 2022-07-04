load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "example",
    srcs = ["src/main.cpp"],
    data = ["imgui.ini"],
    deps = [
        "//lib/glm", "//lib/imgui", "//lib/libglfw", "//lib/libvulkan",
        "//lib/walnut",
    ],
    includes = ["src"],
)
