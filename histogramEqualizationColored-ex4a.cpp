#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

void equalizaHistograma(Mat image){
    
    int height, width, i, j, posic, histogram[256], equalizedHistogram[256], yEqualize;
    double soma, aux, yiq[3], bgr[3], var, y, pixelsImage;
    width = image.size().width;
    height = image.size().height;
    pixelsImage = width * height; // num de pixels da img
    
    // inicializa vetores
    for(i=0; i<256; i++){
        histogram[i] = 0;
        equalizedHistogram[i] = 0;
    }
    
    // percorre a matriz e transforma em YIQ e faz histograma
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            Vec3b bgrPixel = image.at<Vec3b>(i,j);//pega o valor em RGB de um pixel
            bgr[0] = bgrPixel.val[0];
            bgr[1] = bgrPixel.val[1];
            bgr[2] = bgrPixel.val[2];
            
            yiq[0] = (double)(bgr[0]*0.299 + bgr[1]*0.587 + bgr[2]*0.114); //Y
            
            yEqualize = (yiq[0]);
            histogram[yEqualize]++;
        }
    }
    
    //equaliza o histograma da imagem
    for(i=0; i<256; i++){
        
        soma=0;
        for(j=0; j<=i; j++){
            
            aux = (double)(histogram[j]/pixelsImage);
            soma=soma+aux;
        }
        
        soma = soma*255;
        equalizedHistogram[i] = (int)(soma);
    }
    
    // atribui o valor do histograma equalizado para a img
    for(i=0; i<height; i++){
        
        for(j=0; j<width; j++){
            
            Vec3b bgrPixel = image.at<Vec3b>(i,j);//pega o valor em RGB de um pixel
            // Transforma RGB
            bgr[0] = bgrPixel.val[0];
            bgr[1] = bgrPixel.val[1];
            bgr[2] = bgrPixel.val[2];
            
            yiq[0] = (double)(bgr[0]*0.299 + bgr[1]*0.587 + bgr[2]*0.114); //Y
            yiq[1] = (double)(bgr[0]*0.596 - bgr[1]*0.275 - bgr[2]*0.321); //I
            yiq[2] = (double)(bgr[0]*0.212 - bgr[1]*0.523 + bgr[2]*0.311); //Q
            
            var = yiq[0];
            
            // verifica qual o valor de cada canal do pixel
            for(posic=0; posic<256; posic++){
                if(posic == var)
                    break;
            }
            // atribui o valor do histograma equalizado
            y = (equalizedHistogram[posic]);
            
            bgr[0] = (double)((y + yiq[1]*0.956 + yiq[2]*0.62));// Ajusta R
            bgr[1] = (double)((y - yiq[1]*0.272 - yiq[2]*0.647)); //Ajusta G
            bgr[2] = (double)((y - yiq[1]*1.108 + yiq[2]*1.705)); //Ajusta B
            
            //cout<<"r="<<bgr[0]<<" "<<"g="<<bgr[1]<<" "<<"b="<<bgr[2]<<" ";
            
            image.at<Vec3b>(i,j).val[0] = bgr[0];
            image.at<Vec3b>(i,j).val[1] = bgr[1];
            image.at<Vec3b>(i,j).val[2] = bgr[2];
        }
    }
    
    // exibe a imagem
    imshow("Histograma Equalizado", image);
    waitKey(0);
}

int main(void){
    
    Mat image = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste2.jpg");
    imshow("Original", image);
    waitKey(0);
    equalizaHistograma(image);
}