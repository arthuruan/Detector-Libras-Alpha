#include "Libras.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

int main()
{
    ofstream
        output("number_of_activations.txt", ios::out);
    int 
        cont = 0;
    Scalar 
        color = Scalar(255, 0, 0);

    // Load the cascade classifier
    CascadeClassifier cascade;
    Mat frame;
    VideoCapture capture;
    
    const char * device = "/dev/video0";
    //const char * device = "Hand1-01 d.PNG";

    if(!output.is_open()){
        cout << "Nao foi possivel abrir o arquivo";
        return -1;
    }

    if(!capture.open(device))
		    cout << "Capture from camera #0 didn't work" << endl;

    //cascade.load( "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalcatface.xml" ) ;
    cascade.load( "xml/cascade (e4).xml" ) ;
    double scale = 1;

    if( capture.isOpened() ){

        cout << "Video capturing has been started ..." << endl;

        for(;;){

			try {
	            capture >> frame;
			}
			catch (cv::Exception& e)
			{
				std::cout << " Excecao2 capturada frame: " << e.what() << std::endl;
				usleep(100000);
				continue;
			}
			catch (std::exception& e)
			{
				std::cout << " Excecao3 capturada frame: " << e.what() << std::endl;
				usleep(100000);
				continue;
			}

            if(frame.empty())
                break;

            cont += detectAndDraw( frame, cascade, scale );

            //rectangle( frame, Point( 115, 120 ), Point( 170, 150), color, 3, 8, 0);

            char c = (char)waitKey(10);
            if(c == 27)
                break;
        }

    }

    output << "Quantidade de vezes que o E foi detectado: " << cont;

    output.close();
    return 0;
}