# AMPL CMake

```sh
mkdir build

conan install . --profile conanprofile.txt --output-folder=build  --build=missing

cd build

cmake .. --preset conan-release

make

./main
```
