# Copyright 2019-2020 Project Tsurugi.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.10)

project(message-manager
        VERSION 1.0.0
        LANGUAGES CXX
)

# option modules by Nautilus.
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

option(BUILD_TESTS "Build test programs" ON)
option(BUILD_DOCUMENTS "Build documents" OFF)

option(ENABLE_SANITIZER "enable sanitizer on debug build" ON)
option(ENABLE_UB_SANITIZER "enable undefined behavior sanitizer on debug build" OFF)
option(ENABLE_COVERAGE "enable coverage on debug build" OFF)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(metadata-manager REQUIRED)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CompileOptions)
include(InstallOptions)
include(DatabaseOptions)

set(package_name "message-manager")
set(export_name "message-manager")

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${package_name}-config.cmake
  @ONLY
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/${package_name}-config-version.cmake"
  COMPATIBILITY SameMajorVersion
)


install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${package_name}-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${package_name}-config-version.cmake
  DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/${package_name}
)

install(
  EXPORT ${package_name}
  NAMESPACE ${package_name}-
  FILE ${package_name}-targets.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${package_name}
  EXPORT_LINK_INTERFACE_LIBRARIES
)

add_custom_target(format
  COMMAND git ls-files '*.cpp' '*.h' | xargs clang-format -i --style=file -verbose
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(interface INTERFACE)

target_include_directories(interface
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/manager>
)

install_custom(interface ${export_name})

add_subdirectory(src)
#add_subdirectory(example)
