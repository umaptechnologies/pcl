#include <boost/python.hpp>
#include <boost/python/def.hpp>
#include <boost/python/exception_translator.hpp>

#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/common/transforms.h>
#include <pcl/common/projection_matrix.h>

using namespace boost::python;
using namespace pcl;

void export_point_cloud_xyz_rgb()
{
    int (*load_ply_file) (const std::string &file_name, pcl::PointCloud<PointXYZRGB> &cloud) = io::loadPLYFile;

    class_< PointCloud<PointXYZRGB> >(
            "PointCloudXYZRGB",
            init<>()
        )
        .def("load_ply_file", load_ply_file)
        .staticmethod("load_ply_file")
    ;
}

BOOST_PYTHON_MODULE(libpcl_python)
{
    export_point_cloud_xyz_rgb();
}
