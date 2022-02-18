# bimgui framework 

MacOs : [![Build Status](https://cedricguillemet.visualstudio.com/bimgui/_apis/build/status/CedricGuillemet.bimgui?branchName=main&jobName=macOS)](https://cedricguillemet.visualstudio.com/Imog3n/_build/latest?definitionId=3&branchName=main)

Linux : [![Build Status](https://cedricguillemet.visualstudio.com/bimgui/_apis/build/status/CedricGuillemet.bimgui?branchName=main&jobName=Ubuntu_Clang)](https://cedricguillemet.visualstudio.com/Imog3n/_build/latest?definitionId=3&branchName=main)

Windows : [![Build Status](https://cedricguillemet.visualstudio.com/bimgui/_apis/build/status/CedricGuillemet.bimgui?branchName=main&jobName=win32_x64)](https://cedricguillemet.visualstudio.com/Imog3n/_build/latest?definitionId=3&branchName=main)

Emscripten : [![Build Status](https://cedricguillemet.visualstudio.com/bimgui/_apis/build/status/CedricGuillemet.bimgui?branchName=main&jobName=Ubuntu_Emscripten)](https://cedricguillemet.visualstudio.com/Imog3n/_build/latest?definitionId=3&branchName=main)

A template/framework for experiments using bgfx/dear imgui/imguizmo.
Fork this repo, clone it and start hacking.
Build for Win32/Linux/MacOS and web with 1 repo, 1 codebase.

## Build

Binary output directory is `bin/`

### Clone repo
```
git clone git clone https://github.com/CedricGuillemet/bimgui.git App
cd App
git submodule update --init --recursive
```

### Windows
```
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" -A x64
```
And open .sln with Visual Studio

### Mac
```
mkdir build
cd build
cmake .. -G Xcode
```

And open project with Xcode

### Linux
```
mkdir build
cd build
cmake .. -G Ninja
ninja
```

### Web

Clone and activate emsdk https://github.com/emscripten-core/emsdk
Install your favorite build tool supported by cmake (ninja, make, ...)
```
mkdir build
cd build
emcmake cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja
```