#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void zoomOutGrey(Mat image){
    
    Mat result;
    int width, height, i=0, j, y, z, canal, halfHeight, halfWidth;
    width = image.size().width;//pega a largura da imagem
    height = image.size().height;//pega a altura da imagem
    uchar pixel1, pixel2, pixel3, pixel4;
    
    halfHeight = height/2;
    halfWidth = width/2;
    
    result.create(halfHeight, halfWidth, CV_8UC3);
    
    //percorre a matriz
    for(y=0; y<halfHeight; y++){
        j = 0;
        for(z=0; z<halfWidth; z++){
            pixel1 = image.at<uchar>(i,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel2 = image.at<uchar>(i,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel3 = image.at<uchar>(i+1,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel4 = image.at<uchar>(i+1,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            
            //interpolação dos pixels
            canal = (int)(pixel1 + pixel2 + pixel3 + pixel4)/4;
            
            result.at<Vec3b>(y,z).val[0] = canal;
            result.at<Vec3b>(y,z).val[1] = canal;
            result.at<Vec3b>(y,z).val[2] = canal;
            
            j = j+2;
        }
        i = i+2;
    }
    imshow("Zoom out", result);//exibe a imagem
    waitKey(0);
}

void zoomInGray(Mat image){
    
    Mat result;
    int width, height, i, j, y=0, z, doubleHeight, doubleWidth;
    width = image.size().width;//pega a largura da imagem
    height = image.size().height;//pega a altura da imagem
    Vec3b pixel1, pixel2, pixel3, pixel4;
    
    doubleHeight = height*2;
    doubleWidth = width*2;
    
    result.create(doubleHeight, doubleWidth, CV_8UC3);
    
    //percorre a matriz
    for(i=0; i<height; i++){
        z = 0;
        for(j=0; j<width; j++){
            uchar pixel = image.at<uchar>(i,j);//pegando o valor RGB de um pixel
            
            //expande 1 para 4 pixels
            result.at<Vec3b>(y,z).val[0] = (int)pixel;
            result.at<Vec3b>(y,z).val[1] = (int)pixel;
            result.at<Vec3b>(y,z).val[2] = (int)pixel;
            
            result.at<Vec3b>(y+1,z).val[0] = (int)pixel;
            result.at<Vec3b>(y+1,z).val[1] = (int)pixel;
            result.at<Vec3b>(y+1,z).val[2] = (int)pixel;
            
            result.at<Vec3b>(y,z+1).val[0] = (int)pixel;
            result.at<Vec3b>(y,z+1).val[1] = (int)pixel;
            result.at<Vec3b>(y,z+1).val[2] = (int)pixel;
            
            result.at<Vec3b>(y+1,z+1).val[0] = (int)pixel;
            result.at<Vec3b>(y+1,z+1).val[1] = (int)pixel;
            result.at<Vec3b>(y+1,z+1).val[2] = (int)pixel;
            
            z = z+2;
        }
        y = y+2;
    }
    imshow("Zoom in", result);//exibe a imagem
    waitKey(0);
}

void zoomInColor(Mat image){
    
    Mat result;
    int width, height, i, j, y=0, z, doubleHeight, doubleWidth;
    width = image.size().width;//pega a largura da imagem
    height = image.size().height;//pega a altura da imagem
    Vec3b pixel1, pixel2, pixel3, pixel4;
    
    doubleHeight = height*2;
    doubleWidth = width*2;
    
    result.create(doubleHeight, doubleWidth, CV_8UC3);
    
    //percorre a matriz
    for(i=0; i<height; i++){
        z = 0;
        for(j=0; j<width; j++){
            Vec3b pixel = image.at<Vec3b>(i,j);//pegando o valor RGB de um pixel
            
            //expande 1 para 4 pixels
            result.at<Vec3b>(y,z).val[0] = pixel.val[0];
            result.at<Vec3b>(y,z).val[1] = pixel.val[1];
            result.at<Vec3b>(y,z).val[2] = pixel.val[2];
            
            result.at<Vec3b>(y+1,z).val[0] = pixel.val[0];
            result.at<Vec3b>(y+1,z).val[1] = pixel.val[1];
            result.at<Vec3b>(y+1,z).val[2] = pixel.val[2];
            
            result.at<Vec3b>(y,z+1).val[0] = pixel.val[0];
            result.at<Vec3b>(y,z+1).val[1] = pixel.val[1];
            result.at<Vec3b>(y,z+1).val[2] = pixel.val[2];
            
            result.at<Vec3b>(y+1,z+1).val[0] = pixel.val[0];
            result.at<Vec3b>(y+1,z+1).val[1] = pixel.val[1];
            result.at<Vec3b>(y+1,z+1).val[2] = pixel.val[2];
            
            z = z+2;
        }
        y = y+2;
    }
    imshow("Zoom in", result);//exibe a imagem
    waitKey(0);
}


void zoomOutColor(Mat image){
    
    Mat result;
    int width, height, i=0, j, y, z, canal1, canal2, canal3, halfHeight, halfWidth;
    width = image.size().width;//pega a largura da imagem
    height = image.size().height;//pega a altura da imagem
    Vec3b pixel1, pixel2, pixel3, pixel4;
    
    halfHeight = height/2;
    halfWidth = width/2;
    
    result.create(halfHeight, halfWidth, CV_8UC3);
    
    //percorre a matriz
    for(y=0; y<halfHeight; y++){
        j = 0;
        for(z=0; z<halfWidth; z++){
            pixel1 = image.at<Vec3b>(i,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel2 = image.at<Vec3b>(i,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel3 = image.at<Vec3b>(i+1,j);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            pixel4 = image.at<Vec3b>(i+1,j+1);//pega o valor em RGB dos 4 pixels que serao transformados em 1
            
            //interpolação dos pixels
            canal1 = (int)(pixel1.val[0] + pixel2.val[0] + pixel3.val[0] + pixel4.val[0])/4;
            canal2 = (int)(pixel1.val[1] + pixel2.val[1] + pixel3.val[1] + pixel4.val[1])/4;
            canal3 = (int)(pixel1.val[2] + pixel2.val[2] + pixel3.val[2] + pixel4.val[2])/4;
            
            result.at<Vec3b>(y,z).val[0] = canal1;
            result.at<Vec3b>(y,z).val[1] = canal2;
            result.at<Vec3b>(y,z).val[2] = canal3;
            
            j = j+2;
        }
        i = i+2;
    }
    imshow("Zoom out", result);//exibe a imagem
    waitKey(0);
}

int main(){
    Mat gray_image, result;
    Mat image = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");//passa a imagem para matriz
    
    if( !image.data ) {
        printf( "No image data \n" );
        return -1;
    }
    
    imshow("Image", image);//exibe a imagem
    waitKey(0);
    
    cvtColor(image, gray_image, CV_BGR2GRAY);
    imshow("Gray image", gray_image);//exibe a imagem
    waitKey(0);
    
    zoomOutColor(image);
    zoomOutGrey(gray_image);
    
    zoomInColor(image);
    zoomInGray(gray_image);
    
    return 0;
};