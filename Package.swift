// swift-tools-version:5.2

import PackageDescription

let package = Package(
    name: "cglm",
    products: [
        .library(name: "cglm", type: .static, targets: ["cglmHeader"]),
        .library(name: "cglmc", targets: ["cglmCompiled"]),
    ],
    dependencies: [],
    targets: [
        .target(
            name: "cglmCompiled",
            path: "./",
            exclude: [
                "./docs",
                "./dummySrcForSwift",
                "./include",
                "./test",
                "./win",
            ],
            sources: [
                "./src",
            ],
            publicHeadersPath: "./include"
        ),
        .target(
            name: "cglmHeader",
            path: "./",
            exclude: [
                "./docs",
                "./include",
                "./src",
                "./test",
                "./win",
            ],
            sources: [
                "./dummySrcForSwift",
            ],
            publicHeadersPath: "./include"
        ),
    ],
    cLanguageStandard: .c11
)
