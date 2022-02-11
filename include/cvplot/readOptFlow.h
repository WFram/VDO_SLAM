#include<iostream>
#include<fstream>

#include<opencv2/core/core.hpp>

using namespace std;

cv::Mat readOpticalFlow(const string& path);
cv::Mat denseOpticalFlow(const cv::Mat& img, const cv::Mat& img_prev);