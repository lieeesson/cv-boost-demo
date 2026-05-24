#include <opencv2/opencv.hpp>
#include <boost/version.hpp>

#include <iostream>

int main() {
    std::cout << "Boost version: " << BOOST_VERSION << std::endl;
    std::cout << "Boost minor: " << BOOST_VERSION / 100 % 1000 << std::endl;
    std::cout << "Boost patch: " << BOOST_VERSION % 100 << std::endl;

    cv::Mat img = cv::Mat::eye(3, 3, CV_8UC1);
    std::cout << "\nOpenCV loaded OK, 3x3 identity matrix:\n" << img << std::endl;

    return 0;
}