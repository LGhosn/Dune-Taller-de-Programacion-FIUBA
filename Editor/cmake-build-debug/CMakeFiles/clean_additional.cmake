# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/editor_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/editor_autogen.dir/ParseCache.txt"
  "editor_autogen"
  )
endif()
