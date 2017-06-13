#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace cv;
using namespace std;

void filtroMedia(Mat image){
    
    Mat result;
    int width, height, i, j;
    float media,soma;
    width = image.size().width;//pega a largura da imagem
    height = image.size().height;//pega a altura da imagem
    uchar pixel[9];
    
    result.create(height, width, CV_8UC3);
    
    //percorre a matriz
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            soma = 0;
            pixel[0] = image.at<uchar>(i,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            soma = soma + (float)pixel[0];
            if(j+1 <= width){
                pixel[1] = image.at<uchar>(i,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                soma = soma + (float)pixel[1];
            }
            if(j-1 >= 0){
                pixel[2] = image.at<uchar>(i,j-1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                soma = soma + (float)pixel[2];
            }
            if(i+1 <= height){
                pixel[3] = image.at<uchar>(i+1,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                soma = soma + (float)pixel[3];
            }
            if(i+1 <= height && j+1 <= width){
                pixel[4] = image.at<uchar>(i+1,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                soma = soma + (float)pixel[4];
            }
            if(i+1 <= height && j-1 >= 0){
                pixel[5] = image.at<uchar>(i+1,j-1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                soma = soma + (float)pixel[5];
            }
            if(i-1 >= 0){
                pixel[6] = image.at<uchar>(i-1,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                soma = soma + (float)pixel[6];
            }
            if(i-1 >= 0 && j+1 <= width){
                pixel[7] = image.at<uchar>(i-1,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                soma = soma + (float)pixel[7];
            }
            if(i-1 >= 0 && j-1 >= 0){
                pixel[8] = image.at<uchar>(i-1,j-1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                soma = soma + (float)pixel[8];
            }
            
            //media dos pixels
            media = soma/9;
            
            result.at<Vec3b>(i,j).val[0] = media;
            result.at<Vec3b>(i,j).val[1] = media;
            result.at<Vec3b>(i,j).val[2] = media;
        }
    }
    imshow("Filtro de Media", result);//exibe a imagem
    waitKey(0);
}

void filtroMediana(Mat image){
    
    Mat result;
    int width, height, i, j, elementos, aux, mediana, aux2;
    width = image.size().width;//pega a largura da imagem
    height = image.size().height;//pega a altura da imagem
    uchar pixel[9];
    
    result.create(height, width, CV_8UC3);
    
    //percorre a matriz
    for(i=1; i<height-1; i++){
        for(j=1; j<width-1; j++){
            elementos = 0;
            pixel[elementos] = image.at<uchar>(i,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            elementos++;
            if(j+1 <= width){
                pixel[elementos] = image.at<uchar>(i,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                elementos++;
            }
            if(j-1 >= 0){
                pixel[elementos] = image.at<uchar>(i,j-1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                elementos++;
            }
            if(i+1 <= height){
                pixel[elementos] = image.at<uchar>(i+1,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                elementos++;
            }
            if(i+1 <= height && j+1 <= width){
                pixel[elementos] = image.at<uchar>(i+1,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                elementos++;
            }
            if(i+1 <= height && j-1 >= 0){
                pixel[elementos] = image.at<uchar>(i+1,j-1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                elementos++;
            }
            if(i-1 >= 0){
                pixel[elementos] = image.at<uchar>(i-1,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                elementos++;
            }
            if(i-1 >= 0 && j+1 <= width){
                pixel[elementos] = image.at<uchar>(i-1,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                elementos++;
            }
            if(i-1 >= 0 && j-1 >= 0){
                pixel[elementos] = image.at<uchar>(i-1,j-1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
                elementos++;
            }
            
            // Ordena os pixels
            aux = 0;
            while(aux < elementos-1){
                if(pixel[aux] <= pixel[aux+1]){
                    aux++;
                }
                else{
                    aux2 = pixel[aux];
                    pixel[aux] = pixel[aux+1];
                    pixel[aux+1] = aux2;
                    aux = 0;
                }
            }
            
            aux2 = (int)(elementos/2);
            mediana = pixel[aux2]; // Acha a mediana
            
            result.at<Vec3b>(i,j).val[0] = mediana;
            result.at<Vec3b>(i,j).val[1] = mediana;
            result.at<Vec3b>(i,j).val[2] = mediana;
        }
    }
    imshow("Filtro de Mediana", result);//exibe a imagem
    waitKey(0);
}

void filtroSobel(Mat image){
    Mat result;
    int width, height, i, j;
    width = image.size().width;//pega a largura da imagem
    height = image.size().height;//pega a altura da imagem
    uchar pixel[9];
    
    result.create(height, width, CV_8UC3);
    
    //percorre a matriz
    for(i=1; i<height-1; i++){
        for(j=1; j<width-1; j++){
            
            pixel[5] = image.at<uchar>(i,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel[3] = image.at<uchar>(i,j-1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel[7] = image.at<uchar>(i+1,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel[8] = image.at<uchar>(i+1,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel[6] = image.at<uchar>(i+1,j-1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel[1] = image.at<uchar>(i-1,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel[2] = image.at<uchar>(i-1,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel[0] = image.at<uchar>(i-1,j-1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            
            //Calcular a mascara Sobel
            int gy = (pixel[6] + (pixel[7] * 2) + pixel[8]) - (pixel[0] + (pixel[1] * 2) + pixel[2]);
            int gx = (pixel[2] + (pixel[5] * 2) + pixel[8]) - (pixel[0] + (pixel[3] * 2) + pixel[6]);
            
            double gradient = sqrt(pow(gy,2) + pow(gx,2));
            
            if(gradient > 255)
                gradient = 255;
            
            result.at<Vec3b>(i,j).val[0] = gradient;
            result.at<Vec3b>(i,j).val[1] = gradient;
            result.at<Vec3b>(i,j).val[2] = gradient;
        }
    }
    
    imshow("Filtro Sobel", result);//exibe a imagem
    waitKey(0);
}

int main(){
    Mat gray_image, result;
    Mat image = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");//passa a imagem para matriz
    
    if( !image.data ) {
        printf( "No image data \n" );
        return -1;
    }
    
    cvtColor(image, gray_image, CV_BGR2GRAY);
    imshow("Gray image", gray_image);//exibe a imagem
    waitKey(0);
    
    filtroMedia(gray_image);
    filtroSobel(gray_image);
    filtroMediana(gray_image);
    
    return 0;
};
