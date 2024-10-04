#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Usage: display_image ImageToLoadAndDisplay" << std::endl;
        return -1;
    }

    cv::Mat image;
    image = cv::imread(argv[1], cv::IMREAD_COLOR);

    if(!image.data) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", image);
    cv::waitKey(0);

    return 0;
}

// g++ -o main main.cpp `pkg-config --cflags --libs opencv4`
// to use
// ./main image.jpg
// this will display the image.jpg whole the screen