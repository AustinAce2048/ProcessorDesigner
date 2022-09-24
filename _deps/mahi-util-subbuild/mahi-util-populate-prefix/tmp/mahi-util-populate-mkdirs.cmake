# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Projects/ProcessorDesigner/_deps/mahi-util-src"
  "C:/Projects/ProcessorDesigner/_deps/mahi-util-build"
  "C:/Projects/ProcessorDesigner/_deps/mahi-util-subbuild/mahi-util-populate-prefix"
  "C:/Projects/ProcessorDesigner/_deps/mahi-util-subbuild/mahi-util-populate-prefix/tmp"
  "C:/Projects/ProcessorDesigner/_deps/mahi-util-subbuild/mahi-util-populate-prefix/src/mahi-util-populate-stamp"
  "C:/Projects/ProcessorDesigner/_deps/mahi-util-subbuild/mahi-util-populate-prefix/src"
  "C:/Projects/ProcessorDesigner/_deps/mahi-util-subbuild/mahi-util-populate-prefix/src/mahi-util-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Projects/ProcessorDesigner/_deps/mahi-util-subbuild/mahi-util-populate-prefix/src/mahi-util-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Projects/ProcessorDesigner/_deps/mahi-util-subbuild/mahi-util-populate-prefix/src/mahi-util-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
