#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(){
    Mat src, equalizada;
    
    /// Carrega imagem
    src = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");
    
    if( !src.data )
    { cout<<"Usage: ./Histogram_Demo <path_to_image>"<<endl;
        return -1;}
    
    /// Converte para grayscale
    cvtColor( src, src, CV_BGR2GRAY );
    
    /// Applica equalização do histograma
    equalizeHist(src, equalizada);
    
    imshow("Grayscale", src );
    imshow("Equalizada", equalizada );
    
    waitKey(0);
    
    return 0;
}