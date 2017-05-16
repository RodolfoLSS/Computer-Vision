#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

void negativo(Mat imagem){
    
    int largura, altura, i, j, r, g, b;
    largura = imagem.size().width;//pega a largura da imagem
    altura = imagem.size().height;//pega a altura da imagem
    
    //percorre a imagem (matriz)
    for(i=0;i<altura;i++){
        
        for(j=0;j<largura;j++){
            
            Vec3b bgrPixel = imagem.at<Vec3b>(i,j);//pega o valor em RGB de um pixel
            
            //atribui o mesmo valor para o RGB de cada pixel
            imagem.at<Vec3b>(i,j).val[0] = 255 - imagem.at<Vec3b>(i,j).val[0];
            imagem.at<Vec3b>(i,j).val[1] = 255 - imagem.at<Vec3b>(i,j).val[1];
            imagem.at<Vec3b>(i,j).val[2] = 255 - imagem.at<Vec3b>(i,j).val[2];
            
            int soma = imagem.at<Vec3b>(i,j).val[0] + imagem.at<Vec3b>(i,j).val[1] + imagem.at<Vec3b>(i,j).val[2];
            soma = soma/3;
            imagem.at<Vec3b>(i,j).val[0] = soma;
            imagem.at<Vec3b>(i,j).val[1] = soma;
            imagem.at<Vec3b>(i,j).val[2] = soma;
            
        }
    }
    
    imshow("Input Image", imagem);//exibe a imagem
    waitKey(0);//
}

int main(){
    
    Mat imagem = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");//passando a imagem para uma matriz
    negativo(imagem);
    
    return 0;
};