#ifndef _CGAL_BIND_CONFIG_H
#define _CGAL_BIND_CONFIG_H

// pybind11 check
#include "../3rdparty/pybind11/include/pybind11/pybind11.h"
#ifndef PYBIND11_MODULE
#   error "PYBIND11 is not correctly included"
#endif

#include "../3rdparty/pybind11/include/pybind11/operators.h"

namespace py = pybind11;

/*

Specify the kernel type, since the CGAL is highly templated.

*/

// Kernel selection
#if defined USE_CGAL_KERNEL_EPIC
#   include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
    typedef CGAL::Exact_predicates_inexact_constructions_kernel Epic;
#elif defined USE_CGAL_KERNEL_EPEC
#   include <CGAL/Exact_predicates_exact_constructions_kernel.h>
    typedef CGAL::Exact_predicates_exact_constructions_kernel Epec;
#elif defined USE_CGAL_KERNEL_EPECS
#   include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
    typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt Epeck;
#elif defined USE_CGAL_KERNEL_EPECKR // use occasionally
#   include <CGAL/Exact_predicates_exact_constructions_kernel_with_kth_root.h>
    typedef CGAL::Exact_predicates_exact_constructions_kernel_with_kth_root Epeckr;
#elif defined USE_CGAL_KERNEL_EPECR  // use occasionally
#   include <CGAL/Exact_predicates_exact_constructions_kernel_with_root_of.h>
    typedef CGAL::Exact_predicates_exact_constructions_kernel_with_root_of Epecr;
#else
#   error "Unrecognized CGAL kernel."
#endif

#endif //