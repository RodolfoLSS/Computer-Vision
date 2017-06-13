#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

void equalizaHistograma(Mat image){
    
    int height, width, i, j, posic, histogram[256], equalizedHistogram[256];
    double pixelsImage;
    double soma, aux;
    width = image.size().width;
    height = image.size().height;
    pixelsImage = width * height; // num de pixels da img
    
    // inicializa vetores
    for(i=0; i<256; i++){
        histogram[i] = 0;
        equalizedHistogram[i] = 0;
    }
    
    // percorre a matriz
    for(i=0; i<height; i++){
        
        for(j=0; j<width; j++){
            Vec3b pixel = image.at<Vec3b>(i,j);
            histogram[pixel.val[0]]++;
        }
    }
    
    //equaliza o histograma da imagem
    for(i=0; i<256; i++){
        
        soma=0;
        for(j=0;j<=i;j++){
            
            aux = (double)(histogram[j]/pixelsImage);
            soma=soma+aux;
        }
        
        soma = soma*255;
        equalizedHistogram[i] = (int)(soma);
    }
    
    // atribui o valor do histograma equalizado para a img
    for(i=0; i<height; i++){
        
        for(j=0; j<width; j++){
            
            Vec3b pixel = image.at<Vec3b>(i,j);
            
            // verifica qual o valor de cada canal do pixel
            for(posic=0; posic<256; posic++){
                if(posic == pixel.val[0])
                    break;
            }
            // atribui o valor do histograma equalizado
            // apenas 1 canal que é usado pela conversão CV_BGR2GRAY
            image.at<Vec3b>(i,j).val[0] = equalizedHistogram[posic];
        }
    }
    
    // exibe a imagem
    imshow("Histograma Equalizado", image);
    waitKey(0);
}

int main(void){
    
    Mat imagem = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");
    cvtColor(imagem, imagem, CV_BGR2GRAY);
    imshow("Grayscale", imagem);
    equalizaHistograma(imagem);
}