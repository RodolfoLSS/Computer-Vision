#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    Mat src, src_gray, binary;
    int const max_BINARY_value = 255;
    int threshold_value;
    
    /// Carrega imagem
    src = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");
    
    /// Converte para escala de cinza
    cvtColor( src, src_gray, CV_BGR2GRAY );
    
    while(true)
    {
        cout << "Valor do limiar de binarização entre 0 e 255\n";
        cin >> threshold_value; /// Recebe o limiar de binarização
        
        if(threshold_value > 255)
            threshold_value = 255;
        else if(threshold_value < 0)
            threshold_value = 0;
        
        threshold( src_gray, binary, threshold_value, max_BINARY_value,THRESH_BINARY);
        
        imshow("Binary Gray Scale", binary );
        waitKey(0);
    }
    
}