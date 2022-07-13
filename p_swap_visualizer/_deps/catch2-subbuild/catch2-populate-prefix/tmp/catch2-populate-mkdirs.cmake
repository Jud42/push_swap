# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/catch2-src"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/catch2-build"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/catch2-subbuild/catch2-populate-prefix"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/catch2-subbuild/catch2-populate-prefix/tmp"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/catch2-subbuild/catch2-populate-prefix/src"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/rmamison/push_swap/push_swap_visualizer/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/${subDir}")
endforeach()
