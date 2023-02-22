# libQASM

Fork of [QuTech-Delft/libqasm](https://github.com/QuTech-Delft/libqasm), a QuTech/TU Delft library to parse cQASM v1.0 files.

This fork is playing with:
- Conan package manager.
- C++23.
- CMake 3.20.

The following dependencies are still installed as git submodules:
- `tree-gen`.

## Build

```
~/projects/libqasm> conan install . -b=missing
~/projects/libqasm> conan create .
~/projects/libqasm> conan upload libqasm/0.1 -r=rturradocenter
```
