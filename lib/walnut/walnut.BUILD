load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "walnut",
    hdrs = glob(["Walnut/src/Walnut/*.h"]) + [
        "vendor/stb_image/stb_image.h",
        "Walnut/src/Walnut/ImGui/Roboto-Regular.embed",
    ],
    srcs = glob(["Walnut/src/Walnut/*.cpp"]),
    deps = ["@glm", "@imgui", "@libglfw", "@libvulkan"],
    defines = ["WL_PLATFORM_WINDOWS"],
    includes = ["Walnut/src", "vendor/stb_image"],
    linkstatic = True,
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "app",
    srcs = ["WalnutApp/src/WalnutApp.cpp"],
    deps = [":walnut"],
    visibility = ["//visibility:public"],
)
