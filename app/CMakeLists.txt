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
             src/main/cpp/redis-4.0.9/deps/lua/src/fpconv.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lapi.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lauxlib.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lbaselib.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lcode.c
             src/main/cpp/redis-4.0.9/deps/lua/src/ldblib.c
             src/main/cpp/redis-4.0.9/deps/lua/src/ldebug.c
             src/main/cpp/redis-4.0.9/deps/lua/src/ldo.c
             src/main/cpp/redis-4.0.9/deps/lua/src/ldump.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lfunc.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lgc.c
             src/main/cpp/redis-4.0.9/deps/lua/src/linit.c
             src/main/cpp/redis-4.0.9/deps/lua/src/liolib.c
             src/main/cpp/redis-4.0.9/deps/lua/src/llex.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lmathlib.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lmem.c
             src/main/cpp/redis-4.0.9/deps/lua/src/loadlib.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lobject.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lopcodes.c
             src/main/cpp/redis-4.0.9/deps/lua/src/loslib.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lparser.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lstate.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lstring.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lstrlib.c
             src/main/cpp/redis-4.0.9/deps/lua/src/ltable.c
             src/main/cpp/redis-4.0.9/deps/lua/src/ltablib.c
             src/main/cpp/redis-4.0.9/deps/lua/src/ltm.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lua_bit.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lua_cjson.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lua_cmsgpack.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lua_struct.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lundump.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lvm.c
             src/main/cpp/redis-4.0.9/deps/lua/src/lzio.c
             src/main/cpp/redis-4.0.9/deps/lua/src/print.c
             src/main/cpp/redis-4.0.9/deps/lua/src/strbuf.c
              )

add_definitions(-DLUA_COMPAT_5_1)

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

#redis-server
add_executable(
                redis-server
                src/main/cpp/wait3.c
                src/main/cpp/redis-4.0.9/src/anet.c
                src/main/cpp/redis-4.0.9/src/adlist.c
                src/main/cpp/redis-4.0.9/src/quicklist.c
                src/main/cpp/redis-4.0.9/src/ae.c
                src/main/cpp/redis-4.0.9/src/anet.c
                src/main/cpp/redis-4.0.9/src/dict.c
                src/main/cpp/redis-4.0.9/src/server.c
                src/main/cpp/redis-4.0.9/src/sds.c
                src/main/cpp/redis-4.0.9/src/zmalloc.c
                src/main/cpp/redis-4.0.9/src/lzf_c.c
                src/main/cpp/redis-4.0.9/src/lzf_d.c
                src/main/cpp/redis-4.0.9/src/pqsort.c
                src/main/cpp/redis-4.0.9/src/zipmap.c
                src/main/cpp/redis-4.0.9/src/sha1.c
                src/main/cpp/redis-4.0.9/src/ziplist.c
                src/main/cpp/redis-4.0.9/src/release.c
                src/main/cpp/redis-4.0.9/src/networking.c
                src/main/cpp/redis-4.0.9/src/util.c
                src/main/cpp/redis-4.0.9/src/object.c
                src/main/cpp/redis-4.0.9/src/db.c
                src/main/cpp/redis-4.0.9/src/replication.c
                src/main/cpp/redis-4.0.9/src/rdb.c
                src/main/cpp/redis-4.0.9/src/t_string.c
                src/main/cpp/redis-4.0.9/src/t_list.c
                src/main/cpp/redis-4.0.9/src/t_set.c
                src/main/cpp/redis-4.0.9/src/t_zset.c
                src/main/cpp/redis-4.0.9/src/t_hash.c
                src/main/cpp/redis-4.0.9/src/config.c
                src/main/cpp/redis-4.0.9/src/aof.c
                src/main/cpp/redis-4.0.9/src/pubsub.c
                src/main/cpp/redis-4.0.9/src/multi.c
                src/main/cpp/redis-4.0.9/src/debug.c
                src/main/cpp/redis-4.0.9/src/sort.c
                src/main/cpp/redis-4.0.9/src/intset.c
                src/main/cpp/redis-4.0.9/src/syncio.c
                src/main/cpp/redis-4.0.9/src/cluster.c
                src/main/cpp/redis-4.0.9/src/crc16.c
                src/main/cpp/redis-4.0.9/src/endianconv.c
                src/main/cpp/redis-4.0.9/src/slowlog.c
                src/main/cpp/redis-4.0.9/src/scripting.c
                src/main/cpp/redis-4.0.9/src/bio.c
                src/main/cpp/redis-4.0.9/src/rio.c
                src/main/cpp/redis-4.0.9/src/rand.c
                src/main/cpp/redis-4.0.9/src/memtest.c
                src/main/cpp/redis-4.0.9/src/crc64.c
                src/main/cpp/redis-4.0.9/src/bitops.c
                src/main/cpp/redis-4.0.9/src/sentinel.c
                src/main/cpp/redis-4.0.9/src/notify.c
                src/main/cpp/redis-4.0.9/src/setproctitle.c
                src/main/cpp/redis-4.0.9/src/blocked.c
                src/main/cpp/redis-4.0.9/src/hyperloglog.c
                src/main/cpp/redis-4.0.9/src/latency.c
                src/main/cpp/redis-4.0.9/src/sparkline.c
                src/main/cpp/redis-4.0.9/src/redis-check-rdb.c
                src/main/cpp/redis-4.0.9/src/redis-check-aof.c
                src/main/cpp/redis-4.0.9/src/geo.c
                src/main/cpp/redis-4.0.9/src/lazyfree.c
                src/main/cpp/redis-4.0.9/src/module.c
                src/main/cpp/redis-4.0.9/src/evict.c
                src/main/cpp/redis-4.0.9/src/expire.c
                src/main/cpp/redis-4.0.9/src/geohash.c
                src/main/cpp/redis-4.0.9/src/geohash_helper.c
                src/main/cpp/redis-4.0.9/src/childinfo.c
                src/main/cpp/redis-4.0.9/src/defrag.c
                src/main/cpp/redis-4.0.9/src/siphash.c
                src/main/cpp/redis-4.0.9/src/rax.c
                 )
target_link_libraries(redis-server lua-static hiredis-static linenoise-static)
target_include_directories (redis-server PUBLIC src/main/cpp/redis-4.0.9/src)
target_include_directories (redis-server PUBLIC src/main/cpp/redis-4.0.9/deps/hiredis)
target_include_directories (redis-server PUBLIC src/main/cpp/redis-4.0.9/deps/linenoise)
target_include_directories (redis-server PUBLIC src/main/cpp/redis-4.0.9/deps/lua/src)
target_include_directories (redis-server PUBLIC src/main/cpp)


#redis-benchmark
add_executable(
                redis-benchmark
                src/main/cpp/redis-4.0.9/src/ae.c
                src/main/cpp/redis-4.0.9/src/anet.c
                src/main/cpp/redis-4.0.9/src/redis-benchmark.c
                src/main/cpp/redis-4.0.9/src/adlist.c
                src/main/cpp/redis-4.0.9/src/zmalloc.c
                src/main/cpp/redis-4.0.9/src/redis-benchmark.c
)
target_link_libraries(redis-benchmark hiredis-static)
target_include_directories (redis-benchmark PUBLIC src/main/cpp/redis-4.0.9/deps/hiredis)

#dict-benchmark
add_executable(
                dict-benchmark
                src/main/cpp/redis-4.0.9/src/dict.c
                src/main/cpp/redis-4.0.9/src/zmalloc.c
                src/main/cpp/redis-4.0.9/src/sds.c
                src/main/cpp/redis-4.0.9/src/siphash.c
)
target_compile_definitions(dict-benchmark PUBLIC -DDICT_BENCHMARK_MAIN)