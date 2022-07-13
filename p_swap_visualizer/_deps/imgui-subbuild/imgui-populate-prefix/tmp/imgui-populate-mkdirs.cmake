# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/imgui-src"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/imgui-build"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/imgui-subbuild/imgui-populate-prefix"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/imgui-subbuild/imgui-populate-prefix/tmp"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/imgui-subbuild/imgui-populate-prefix/src"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/rmamison/push_swap/push_swap_visualizer/_deps/imgui-subbuild/imgui-populate-prefix/src/imgui-populate-stamp/${subDir}")
endforeach()
