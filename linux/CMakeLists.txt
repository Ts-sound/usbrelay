#####################################
# head
#####################################
cmake_minimum_required(VERSION 3.10.0)


project(usbrelay)

message("#####################################")
message("PROJECT_NAME = ${PROJECT_NAME}")
message("#####################################")

#####################################
# include
#####################################
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#####################################
# package_inc
#####################################
# file(GLOB_RECURSE PACKAGE_INC
#   "include/*"	
# )

message(STATUS "PACKAGE_INC")
foreach(file ${PACKAGE_INC})
  message(STATUS "${file}")
endforeach(file ${PACKAGE_INC})

#####################################
# package_src
#####################################
file(GLOB_RECURSE PACKAGE_SRC
  "*.c"
)

message(STATUS "PACKAGE_SRC")
foreach(file ${PACKAGE_SRC})
  message(STATUS "${file}")
endforeach(file ${PACKAGE_SRC})


#####################################
# link and compile
#####################################
set(CMAKE_CXX_FLAGS "-std=c++11 -g -O0")
add_compile_options(-rdynamic -fPIC)

add_library(${PROJECT_NAME} STATIC ${PACKAGE_SRC})

#####################################
# install
#####################################
# INSTALL (
#   DIRECTORY include/${PROJECT_NAME}
#   DESTINATION ${install_path}/include
#   PATTERN "config.h" EXCLUDE
#   PATTERN ".svn" EXCLUDE
#   PATTERN "*.am" EXCLUDE
#   PATTERN "*.in" EXCLUDE
# )

# INSTALL (
#   TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${install_path}/lib
# )
