#ifndef LIBRAS_H
#define LIBRAS_H

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace cv;

int detectAndDraw( Mat& img, CascadeClassifier& cascade, double scale);

#endif //LIBRAS_H