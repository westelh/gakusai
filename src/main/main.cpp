#include <iostream>
#include "opencv2/opencv.hpp"

int main() {
	cv::Mat mat;
	mat = cv::imread("s", 0);
	if (mat.empty()) {
		std::cout << "reading file failed\n";
		return -1;
	}
}