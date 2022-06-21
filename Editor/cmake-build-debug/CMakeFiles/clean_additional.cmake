# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/DuneEditor_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/DuneEditor_autogen.dir/ParseCache.txt"
  "DuneEditor_autogen"
  )
endif()
