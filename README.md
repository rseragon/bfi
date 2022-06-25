
# BrainF**k Interpreter

A simple brainf**k interpreter written in C++;

> NOTE: This is not a offical implementation and might not comply to all the complications of a real brainf**k 

## Installation
1. Clone the project
2. Setup CMake build dir 
Eg:
```console
git clone https://github.com/rseragon/bfi.git && cd /path/to/bfi/ && mkdir build/
```
3. Generate CMake build files with required options
Eg:
```console
cmake -Dfoo=bar /path/to/bfi/build 
```
### Few cmake options
##### Colored output
+ ASCII_TERMINAL=on 
##### Build type
+ CMAKE_BUILD_TYPE=Debug
+ CMAKE_BUILD_TYPE=Release

4. Build executable
Eg:
```console
cmake --build /path/to/bfi/build
```
5. Install
Eg:
```console
sudo cmake --install /path/to/bfi/build
```

