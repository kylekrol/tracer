# Pulled from the following sources:
#  - https://medium.com/codex/vulkan-in-bazel-projects-part-1-environment-setup-e9fc2ec51b
#  - https://github.com/Morfly/vulkan-bazel-samples/blob/main/third_party/glfw/glfw.BUILD

load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "glfw",
    hdrs = glob(["include/**/*.h"]),
    srcs = [
        "src/internal.h",
        "src/mappings.h",

        "src/context.c",
        "src/init.c",
        "src/input.c",
        "src/monitor.c",
        "src/vulkan.c",
        "src/window.c",

        "src/glx_context.h",
        "src/glx_context.c",

        "src/egl_context.h",
        "src/egl_context.c",

        "src/linux_joystick.h",
        "src/linux_joystick.c",

        "src/posix_thread.h",
        "src/posix_thread.c",
        "src/posix_time.h",
        "src/posix_time.c",

        "src/osmesa_context.h",
        "src/osmesa_context.c",

        "src/x11_platform.h",
        "src/x11_init.c",
        "src/x11_monitor.c",
        "src/x11_window.c",

        "src/xkb_unicode.h",
        "src/xkb_unicode.c",
    ],
    defines = ["_GLFW_X11"],
    deps = ["@rules_vulkan//vulkan:vulkan_cc_library"],
    includes = ["include"],
    linkopts = ["-lX11"],
    linkstatic = True,
    visibility = ["//visibility:public"],
)
