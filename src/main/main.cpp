#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "utils/utils.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/tracking/tracker.hpp"

int main(int argc, const char* argv[]) {
	auto args = argv_to_vec(argc, argv);

	cv::VideoCapture video;
	try {
		std::cout << "reading video file...\n";
		video.open(args.at(1));
	} catch (std::out_of_range e) {
		std::cout << "please input file name\n";
		exit(1);
	}

	std::cout << "opening file \"" << args.at(1) << "\" ";
	if (!video.isOpened()) {
		std::cout << "failed\n";
		exit(1);
	} else std::cout << "succeeded\n";
}