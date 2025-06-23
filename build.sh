set -e  # exit on error
set -x  # verbose mode

# build ts
BUILD_DIR="build"
rm -rf $BUILD_DIR
mkdir $BUILD_DIR
pushd $BUILD_DIR # switch into build dir, but keep prev. dir on stack

# make ts
conan install .. --output-folder=. --build=missing

if [ ! -f conan_toolchain.cmake ]; then
  echo "Error: conan_toolchain.cmake not found!"
  exit 1
fi

cmake .. \
  -DCMAKE_TOOLCHAIN_FILE="$(pwd)/conan_toolchain.cmake" \
  -DCMAKE_BUILD_TYPE=Release
cmake --build .

mv pangolin ..

popd # change back to prev. dir