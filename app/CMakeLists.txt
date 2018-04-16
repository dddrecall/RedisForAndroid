# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )

#lua.a
add_library( # Sets the name of the library.
             lua-static

             # Sets the library as a shared library.
             STATIC

             # Provides a relative path to your source file(s).
             src/main/cpp/lua-5.3.4/src/lapi.c
             src/main/cpp/lua-5.3.4/src/lauxlib.c
             src/main/cpp/lua-5.3.4/src/lbaselib.c
             src/main/cpp/lua-5.3.4/src/lbitlib.c
             src/main/cpp/lua-5.3.4/src/lcode.c
             src/main/cpp/lua-5.3.4/src/lcorolib.c
             src/main/cpp/lua-5.3.4/src/lctype.c
             src/main/cpp/lua-5.3.4/src/ldblib.c
             src/main/cpp/lua-5.3.4/src/ldebug.c
             src/main/cpp/lua-5.3.4/src/ldo.c
             src/main/cpp/lua-5.3.4/src/ldump.c
             src/main/cpp/lua-5.3.4/src/lfunc.c
             src/main/cpp/lua-5.3.4/src/lgc.c
             src/main/cpp/lua-5.3.4/src/linit.c
             src/main/cpp/lua-5.3.4/src/liolib.c
             src/main/cpp/lua-5.3.4/src/llex.c
             src/main/cpp/lua-5.3.4/src/lmathlib.c
             src/main/cpp/lua-5.3.4/src/lmem.c
             src/main/cpp/lua-5.3.4/src/loadlib.c
             src/main/cpp/lua-5.3.4/src/lobject.c
             src/main/cpp/lua-5.3.4/src/lopcodes.c
             src/main/cpp/lua-5.3.4/src/loslib.c
             src/main/cpp/lua-5.3.4/src/lparser.c
             src/main/cpp/lua-5.3.4/src/lstate.c
             src/main/cpp/lua-5.3.4/src/lstring.c
             src/main/cpp/lua-5.3.4/src/lstrlib.c
             src/main/cpp/lua-5.3.4/src/ltable.c
             src/main/cpp/lua-5.3.4/src/ltablib.c
             src/main/cpp/lua-5.3.4/src/ltm.c
             src/main/cpp/lua-5.3.4/src/lundump.c
             src/main/cpp/lua-5.3.4/src/lutf8lib.c
             src/main/cpp/lua-5.3.4/src/lvm.c
             src/main/cpp/lua-5.3.4/src/lzio.c
              )
#hiredis
add_library( # Sets the name of the library.
             hiredis-static

             # Sets the library as a shared library.
             STATIC

             src/main/cpp/redis-4.0.9/deps/hiredis/net.c
             src/main/cpp/redis-4.0.9/deps/hiredis/hiredis.c
             src/main/cpp/redis-4.0.9/deps/hiredis/sds.c
             src/main/cpp/redis-4.0.9/deps/hiredis/async.c
             src/main/cpp/redis-4.0.9/deps/hiredis/read.c
             )

#linenoise
add_library( # Sets the name of the library.
             linenoise-static

             # Sets the library as a shared library.
             STATIC

             src/main/cpp/redis-4.0.9/deps/linenoise/linenoise.c
             )
# set binary output folder to Android assets folder
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/main/assets/${ANDROID_ABI}")

#redis-cli
add_executable(
                redis-cli
                src/main/cpp/redis-4.0.9/src/anet.c
                src/main/cpp/redis-4.0.9/src/adlist.c
                src/main/cpp/redis-4.0.9/src/redis-cli.c
                src/main/cpp/redis-4.0.9/src/zmalloc.c
                src/main/cpp/redis-4.0.9/src/release.c
                src/main/cpp/redis-4.0.9/src/anet.c
                src/main/cpp/redis-4.0.9/src/ae.c
                src/main/cpp/redis-4.0.9/src/crc64.c
                )
target_link_libraries(redis-cli lua-static hiredis-static linenoise-static)
target_include_directories (redis-cli PUBLIC src/main/cpp/redis-4.0.9/src)
target_include_directories (redis-cli PUBLIC src/main/cpp/redis-4.0.9/deps/hiredis)
target_include_directories (redis-cli PUBLIC src/main/cpp/redis-4.0.9/deps/linenoise)