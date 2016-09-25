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

	cv::namedWindow("main");

	cv::Mat frame;
	video >> frame;

	auto color1 = cv::Scalar(0, 255, 255);
	auto color2 = cv::Scalar(255, 0, 255);
	auto color3 = cv::Scalar(255, 255, 0);

	auto roi1 = cv::selectROI("main", frame);
	auto roi2 = cv::selectROI("main", frame);
	auto roi3 = cv::selectROI("main", frame);

	cv::Ptr<cv::Tracker> tracker1 = cv::Tracker::create("MIL");
	cv::Ptr<cv::Tracker> tracker2 = cv::Tracker::create("MIL");
	cv::Ptr<cv::Tracker> tracker3 = cv::Tracker::create("MIL");

	tracker1->init(frame, roi1);
	tracker2->init(frame, roi2);
	tracker3->init(frame, roi3);

	double fps = video.get(CV_CAP_PROP_FPS);
    cv::Size size = cv::Size(video.get(CV_CAP_PROP_FRAME_WIDTH), video.get(CV_CAP_PROP_FRAME_HEIGHT));
    const int fourcc = cv::VideoWriter::fourcc('X', 'V', 'I', 'D');
    std::string filename = "output.avi";
    cv::VideoWriter writer(filename, fourcc, fps, size);

	while(video.grab()) {
		tracker1->update(frame, roi1);
		tracker2->update(frame, roi2);
		tracker3->update(frame, roi3);

		cv::rectangle(frame, roi1, color1, 1, 1);
		cv::rectangle(frame, roi2, color2, 1, 1);
		cv::rectangle(frame, roi3, color3, 1, 1);

		cv::imshow("main", frame);
		writer << frame;

		video.retrieve(frame);
	}
}