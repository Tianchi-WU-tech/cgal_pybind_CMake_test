cmake_minimum_required(VERSION 3.20)
project(cgal_pybind11)
set(CMAKE_CXX_STANDARD 14 CACHE “C++ version selection") # or 11, 14, 17, 20
set(CMAKE_CXX_STANDARD_REUIRED on)


# ------------- Find required packages --------------


add_subdirectory(pybind11)

find_package(CGAL REQUIRED COMPONENTS Core)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CGAL_INCLUDE_DIRS})
link_directories(${CGAL_LIBRARY_DIRS})
add_definitions(${CGAL_DEFINITIONS})


# ---------------- Options ----------------


# Available options would be
# C: Cartesian
# EPIC: Exact_predicates_inexact_constructions_kernel
# EPEC: Exact_predicates_exact_constructions_kernel
# EPECR: Exact_predicates_exact_constructions_kernel_with_root_of
# EPECS: Exact_predicates_exact_constructions_kernel_with_sqrt
# EPECKR: Exact_predicates_exact_constructions_kernel_with_kth_root

set(CGAL_KERNEL "EPEC" CACHE STRING "Select Kernel for CGAL instantiation, EPIC/EPEC/EPECR/EPECS/EPECKR")
add_definitions(-DUSE_CGAL_KERNEL_${CGAL_KERNEL})
add_definitions(-DCGAL_VERSION_MAJOR=${CGAL_VERSION_MAJOR})
add_definitions(-DCGAL_VERSION_MINOR=${CGAL_VERSION_MINOR})


# ---------------- Module compilation ----------------


pybind11_add_module(boolean src/_boolean.cpp)
target_link_libraries(boolean PUBLIC CGAL::CGAL CGAL::CGAL_Core)
