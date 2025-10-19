#include <opencv2/opencv.hpp>
#include <iostream>

// Convert BGR to grayscale manually
cv::Mat rgbToGrayscale(const cv::Mat& img) {
    CV_Assert(img.channels() == 3);
    cv::Mat gray(img.rows, img.cols, CV_32F);

    for (int y = 0; y < img.rows; ++y) {
        for (int x = 0; x < img.cols; ++x) {
            cv::Vec3b bgr = img.at<cv::Vec3b>(y, x);
            float gray_val = 0.114f * bgr[0] + 0.587f * bgr[1] + 0.299f * bgr[2];
            gray.at<float>(y, x) = gray_val;
        }
    }
    return gray;
}

// Normalize to [0, 1]
cv::Mat normalizeImage(const cv::Mat& img) {
    double minVal, maxVal;
    cv::minMaxLoc(img, &minVal, &maxVal);

    cv::Mat norm;
    img.convertTo(norm, CV_32F, 1.0 / (maxVal - minVal), -minVal / (maxVal - minVal));
    return norm;
}

int main() {
    cv::Mat img = cv::imread("edgeflower.jpg");
    if (img.empty()) {
        std::cerr << "Failed to load image\n";
        return -1;
    }

    cv::resize(img, img, cv::Size(256, 256));  // Optional: resize for speed
    cv::Mat gray = rgbToGrayscale(img);  //matrix of floats
    cv::Mat norm = normalizeImage(gray); //normalizing floats

    cv::Mat enlarged;
    int scale = 6; // or 4 for quadruple
    cv::resize(norm, enlarged, cv::Size(), scale, scale, cv::INTER_NEAREST);

    // Display
    cv::imshow("Grayscale Normalized", enlarged);
    cv::waitKey(0);
    return 0;
}

