#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

// Binariza a imagem
Mat binarizar(int threshold_value, Mat image){
    
    int width, height, i, j, soma;
    width = image.size().width;// pega a largura da imagem
    height = image.size().height;// pega a altura da imagem
    
    // percorre matriz
    for(i=0; i<height; i++){
        
        for(j=0; j<width; j++){
            
            soma = 0;
            Vec3b bgrPixel = image.at<Vec3b>(i,j);// pega RGB de um pixel
            
            if(bgrPixel.val[0] >= threshold_value)
                image.at<Vec3b>(i,j).val[0] = 255;
            else
                image.at<Vec3b>(i,j).val[0] = 0;
            
        }
    }
    
    return image;
}

int main(void){
    
    Mat image = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");
    int threshold_value;
    
    cvtColor( image, image, CV_BGR2GRAY );
    
    cout << "Valor do limiar de binarização entre 0 e 255\n";
    cin >> threshold_value; /// Recebe o limiar de binarização
        
    if(threshold_value > 255)
        threshold_value = 255;
    else if(threshold_value < 0)
        threshold_value = 0;
        
    image = binarizar(threshold_value, image);
    imshow("Binary", image);
    waitKey(0);
}