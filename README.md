# message-broker


## Requirements

- CMake `>= 3.10`
- C++ Compiler `>= C++17`

### Dockerfile

```dockerfile
FROM ubuntu:18.04

RUN apt update -y && apt install -y git build-essential cmake ninja-build 
```

## How to build

1. Retrieve third party modules.

   ```sh
   git submodule update --init --recursive
   ```

2. Build message manager.

   ```sh
   mkdir build
   cd build
   cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ..
   ninja
   ```

   available options:
     - `DCMAKE_INSTALL_PREFIX=<installation directory>` - change install location
     - `DCMAKE_PREFIX_PATH=<installation directory>` - indicate prerequisite installation directory
     - for debugging only
       - `-DENABLE_SANITIZER=OFF` - disable sanitizers (requires `-DCMAKE_BUILD_TYPE=Debug`)
       - `-DENABLE_UB_SANITIZER=ON` - enable undefined behavior sanitizer (requires `-DENABLE_SANITIZER=ON`)
       - `-DENABLE_COVERAGE=ON` - enable code coverage analysis (requires `-DCMAKE_BUILD_TYPE=Debug`)

### install

```sh
ninja install
```

### run tests

T.B.D

## License

[Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0)
