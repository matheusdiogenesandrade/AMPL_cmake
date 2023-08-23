# AMPL CMake

```sh
mkdir build

cd build

conan install .. --profile ../conanprofile.txt --build=missing

cmake ..

make

./bin/main
```
