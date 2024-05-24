# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SIMULARE_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SIMULARE_autogen.dir/ParseCache.txt"
  "SIMULARE_autogen"
  )
endif()
