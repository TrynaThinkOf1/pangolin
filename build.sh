set -e  # exit on error
set -x  # verbose mode

rm -f ./pangolin

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

mkdir -p Libraries
if [ ! -d "./Libraries/metal-cpp" ]; then
  echo DOWNLOADING METAL LIBRARY FOR MACOS

  TEMP_FILE=$(mktemp).zip

  if ! curl --fail --output $TEMP_FILE https://developer.apple.com/metal/cpp/files/metal-cpp_macOS26_iOS26-beta.zip; then
    echo "Failed to download metal-cpp"
    rm -f $TEMP_FILE
    exit 1
  fi

  TEMP_DIR=$(mktemp -d)

  if ! unzip -q $TEMP_FILE -d $TEMP_DIR; then
    echo "Failed to unzip metal-cpp"
    rm -f $TEMP_FILE
    rm -rf $TEMP_DIR
    exit 1
  fi

  rm -f $TEMP_FILE

  if [ -d "${TEMP_DIR}/metal-cpp" ]; then
    mv "${TEMP_DIR}/metal-cpp" ../Libraries
    echo SUCCESSFULLY DOWNLOADED METAL LIBRARY
  else
    echo "metal-cpp library not found in unzipped archive"
    rm -rf $TEMP_DIR
    exit 1
  fi

  rm -rf $TEMP_DIR
fi

cmake .. \
  -DCMAKE_TOOLCHAIN_FILE="$(pwd)/conan_toolchain.cmake" \
  -DCMAKE_BUILD_TYPE=Release
cmake --build .

mv pangolin ..

popd # change back to prev. dir