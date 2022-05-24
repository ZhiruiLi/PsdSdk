# PSD SDK

A C++ library that directly reads Photoshop PSD files. The library supports:

- Groups
- Nested layers
- Smart Objects
- User and vector masks
- Transparency masks and additional alpha channels
- 8-bit, 16-bit, and 32-bit data in grayscale and RGB color mode
- All compression types known to Photoshop

Additionally, limited export functionality is also supported.

## Quick Start

```bash
git clone https://github.com/ZhiruiLi/PsdSdk.git PsdSdk
cd PsdSdk
cmake -DCMAKE_INSTALL_PREFIX="psdsdk" -DBUILD_SHARED_LIBS=ON -S . -B build
cmake --build build --target install
# output files can be found under psdsdk dir
```

## Directory structure

### bin
Contains a Photoshop PSD file used by the sample code.

### src
Contains the library source code as well as a sample application that shows how to use the SDK in order to read and write PSD files.
