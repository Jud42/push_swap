# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/sfml-src"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/sfml-build"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/sfml-subbuild/sfml-populate-prefix"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "/Users/rmamison/push_swap/push_swap_visualizer/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/rmamison/push_swap/push_swap_visualizer/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
