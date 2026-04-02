# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\op_lab1_on_c_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\op_lab1_on_c_autogen.dir\\ParseCache.txt"
  "op_lab1_on_c_autogen"
  )
endif()
