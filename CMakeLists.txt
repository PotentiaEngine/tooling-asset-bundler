cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(PotentiaTools_AssetBundling)

file (GLOB_RECURSE ASSET_BUNDLER_FILES "./src/*/*.h" "./src/*/*.cpp" "./src/*.h" "./src/*.cpp")
add_executable(PotentiaTool_AssetBundler ${ASSET_BUNDLER_FILES})
target_include_directories(PotentiaTool_AssetBundler PUBLIC ./tools/asset-bundler/)
find_package(CLI11 CONFIG REQUIRED)
target_link_libraries(PotentiaTool_AssetBundler PRIVATE CLI11::CLI11)
find_package(assimp CONFIG REQUIRED)
target_link_libraries(PotentiaTool_AssetBundler PRIVATE assimp::assimp)
