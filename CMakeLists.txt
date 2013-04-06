
# CMakeLists.txt

cmake_minimum_required (VERSION 2.8)
project (PacketDump)

SET (CMAKE_CXX_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb")
SET (CMAKE_C_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb")
SET (CMAKE_BUILD_TYPE Debug)


SET (CMAKE_CXX_COMPILER "ccache")
SET (CMAKE_CXX_COMPILER_ARG1 "g++")


SET (CMAKE_C_COMPILER "ccache")
SET (CMAKE_C_COMPILER_ARG1 "gcc")

INCLUDE_DIRECTORIES (
    .
)

SET (SRC_LIST
    pkt_lock.cpp
    pkt_logger.cpp
    pkt_memman.cpp
    pkt_pool.cpp
    pkt_capture.cpp
    pkt_common.cpp
    main.cpp
)

SET (EXTRA_LIBS
    -lpthread -lrt
)

add_executable (PacketDump ${SRC_LIST})
target_link_libraries (PacketDump ${EXTRA_LIBS})
