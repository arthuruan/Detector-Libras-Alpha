#include "Libras.h"

int detectAndDraw( Mat& img, CascadeClassifier& cascade, double scale){
    int flag = 0;
    vector<Rect> faces;
    Scalar color = Scalar(255, 0, 0);
    Mat gray, smallImg;

    cvtColor( img, gray, COLOR_BGR2GRAY );
    double fx = 1 / scale;
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    cascade.detectMultiScale( gray, faces, 1.3, 2, 0|CASCADE_SCALE_IMAGE, Size(100, 100) );

    for ( size_t i = 0; i < faces.size(); i++ ){
        
        Rect r = faces[i];
        Point center;

        rectangle( img, Point(cvRound(r.x*scale), cvRound(r.y*scale)),
                   Point(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
                   color, 3, 8, 0);

        flag = 1;

        cv::putText(img, //target image
            "Letra E", //text
            cv::Point(10, img.rows / 2), //top-left position
            cv::FONT_HERSHEY_DUPLEX,
            1.0,
            CV_RGB(255, 0, 0), //font color
            2);

    }

    imshow( "Libras", img );

    return flag;
}