#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#

cmake_minimum_required(VERSION 3.17)

project(aoc2020 VERSION 1.0.0
                DESCRIPTION "Advent of Code 2020 - C++ with CMake"
                HOMEPAGE_URL "https://github.com/grgrzybek/adventofcode2020")

set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/_install")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -g")

set(commands
    day01
    day02
    day03
    day04
    day05
)

configure_file(config.h.in "${CMAKE_INSTALL_PREFIX}/include/config.h")
include_directories("${CMAKE_INSTALL_PREFIX}/include")
include_directories("${CMAKE_SOURCE_DIR}/include")

add_library(aoc2020 SHARED src/utils/utils.cc)

foreach(cmd ${commands})
    add_executable(${cmd})
    target_sources(${cmd} PUBLIC src/${cmd}.cc)
    target_link_libraries(${cmd} aoc2020)
endforeach(cmd)

install(TARGETS ${commands} RUNTIME DESTINATION bin)
