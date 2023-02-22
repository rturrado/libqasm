from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, cmake_layout


class LibqasmConan(ConanFile):
    name = "libqasm"
    license = "Apache-2.0"
    url = "http://localhost:8081/artifactory/api/conan/rturradocenter"
    description = "Library to parse cQASM v1.0 files"
    topics = ("code generation", "parser", "compiler", "quantum compilation", "quantum simulation")
    version = "0.1"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["cqasm"]
