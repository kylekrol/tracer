load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "imgui",
    hdrs = [
        "imgui.h",
        "imstb_rectpack.h",
        "imstb_textedit.h",
        "imstb_truetype.h",
        "backends/imgui_impl_glfw.h",
        "backends/imgui_impl_vulkan.h",
    ],
    srcs = glob(["*.cpp"]) + [
        "imconfig.h",
        "imgui_internal.h",
        "backends/imgui_impl_glfw.cpp",
        "backends/imgui_impl_vulkan.cpp",
    ],
    deps = ["@glfw//:glfw"],
    includes = [".", "backends"],
    linkstatic = True,
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "example",
    srcs = ["examples/example_glfw_vulkan/main.cpp"],
    deps = [":imgui"],
    visibility = ["//visibility:public"],
)
