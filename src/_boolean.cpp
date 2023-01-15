#include"_boolean.h"
#include <iostream>
#include <sstream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;


void OutputNefPolyhedron(const Nef_polyhedron& nef, string strOutFilePath)
{
    Surface_mesh output;
    CGAL::convert_nef_polyhedron_to_polygon_mesh(nef, output);
    std::ofstream out;
    out.open(strOutFilePath);
    out << output;
    out.close();
}

void boolean_cgal(const string& boolean_type,const string& file_path_a, const string& file_path_b, const string& output_file)
{
    // assign two objects from input
    Polyhedron object_1, object_2;
    string stl_file_a = file_path_a;
    CGAL::Polygon_mesh_processing::IO::read_polygon_mesh(stl_file_a, object_1);

    string stl_file_b = file_path_b;
    CGAL::Polygon_mesh_processing::IO::read_polygon_mesh(stl_file_b, object_2);

    Nef_polyhedron nef1(object_1);
    Nef_polyhedron nef2(object_2);

    // Boolean manipulation
    switch (boolean_type)
    {
    case "diff":
    {
        Nef_polyhedron nefDifference = nef1 - nef2;
        string diff_name_suffix = "_diff.off";
        string diff_name = output_file + diff_name_suffix;
        OutputNefPolyhedron(nefDifference, diff_name);
        break;
    }
    case "union":
    {
        Nef_polyhedron nefUnion = nef1 + nef2;
        string union_name_suffix = "_union.off";
        string union_name = output_file + union_name_suffix;
        OutputNefPolyhedron(nefUnion, union_name);
        break;
    }
    case "intersect":
    {
        Nef_polyhedron nefIntersect = nef1 * nef2;
        string intersect_name_suffix = "_intersect.off";
        string intersect_name = output_file + intersect_name_suffix;
        OutputNefPolyhedron(nefIntersect, intersect_name);
        break;
    }
    // unavailable boolean type is called
    default:
        cout << "ERROR!" << endl;
    }
}

