#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image;

    // Load Image
    string image_path;
    cout << "Enter image path: ";
    cin >> image_path;
    image = imread(image_path);

    if (image.empty()) {
        cout << "Error loading image!" << endl;
        return -1;
    }

    // Display Original Image
    namedWindow("Original Image", WINDOW_NORMAL);
    imshow("Original Image", image);
    waitKey(0);

    // Print Image Details
    cout << "Image Details:" << endl;
    cout << "Width: " << image.cols << " pixels" << endl;
    cout << "Height: " << image.rows << " pixels" << endl;
    cout << "Number of Channels: " << image.channels() << endl;

    // Get and print the depth of the image
    int depth = image.depth();
    string depth_str;
    switch (depth) {
        case CV_8U: depth_str = "CV_8U (8-bit unsigned)"; break;
        case CV_8S: depth_str = "CV_8S (8-bit signed)"; break;
        case CV_16U: depth_str = "CV_16U (16-bit unsigned)"; break;
        case CV_16S: depth_str = "CV_16S (16-bit signed)"; break;
        case CV_32S: depth_str = "CV_32S (32-bit signed)"; break;
        case CV_32F: depth_str = "CV_32F (32-bit floating point)"; break;
        case CV_64F: depth_str = "CV_64F (64-bit floating point)"; break;
        default: depth_str = "Unknown"; break;
    }
    cout << "Depth: " << depth_str << endl;

    // Print Image Type
    int type = image.type();
    string type_str;
    switch (type) {
        case CV_8UC1: type_str = "CV_8UC1 (8-bit unsigned, 1 channel)"; break;
        case CV_8UC3: type_str = "CV_8UC3 (8-bit unsigned, 3 channels)"; break;
        case CV_16UC1: type_str = "CV_16UC1 (16-bit unsigned, 1 channel)"; break;
        case CV_16UC3: type_str = "CV_16UC3 (16-bit unsigned, 3 channels)"; break;
        case CV_32FC1: type_str = "CV_32FC1 (32-bit float, 1 channel)"; break;
        case CV_32FC3: type_str = "CV_32FC3 (32-bit float, 3 channels)"; break;
        default: type_str = "Unknown"; break;
    }
    cout << "Image Type: " << type_str << endl;

    // Image Filters
    Mat gray_image, blur_image, sharpen_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);
    GaussianBlur(image, blur_image, Size(5, 5), 0);
    addWeighted(image, 1.5, blur_image, -0.5, 0, sharpen_image);

    // Color Adjustment
    Mat adjusted_image;
    image.convertTo(adjusted_image, -1, 1.2, 20);

    // Crop and Resize
    Rect crop_region(100, 100, 300, 300);
    Mat cropped_image = image(crop_region);
    Mat resized_image;
    resize(image, resized_image, Size(), 0.5, 0.5);

    // Save Processed Images
    imwrite("gray_image.jpg", gray_image);
    imwrite("blurred_image.jpg", blur_image);
    imwrite("sharpened_image.jpg", sharpen_image);
    imwrite("adjusted_image.jpg", adjusted_image);
    imwrite("cropped_image.jpg", cropped_image);
    imwrite("resized_image.jpg", resized_image);

    // Display Processed Images
    namedWindow("Grayscale Image", WINDOW_NORMAL);
    imshow("Grayscale Image", gray_image);
    waitKey(0);

    namedWindow("Blurred Image", WINDOW_NORMAL);
    imshow("Blurred Image", blur_image);
    waitKey(0);

    namedWindow("Sharpened Image", WINDOW_NORMAL);
    imshow("Sharpened Image", sharpen_image);
    waitKey(0);

    namedWindow("Adjusted Image", WINDOW_NORMAL);
    imshow("Adjusted Image", adjusted_image);
    waitKey(0);

    namedWindow("Cropped Image", WINDOW_NORMAL);
    imshow("Cropped Image", cropped_image);
    waitKey(0);

    namedWindow("Resized Image", WINDOW_NORMAL);
    imshow("Resized Image", resized_image);
    waitKey(0);

    cout << "Processed images saved!" << endl;

    return 0;
}