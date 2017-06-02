#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

Mat nivel_cinza(){
    
    Mat imagem = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");//passando a imagem para uma matriz
    int largura, altura, i, j, soma;
    largura = imagem.size().width;//pegando a largura da imagem
    altura = imagem.size().height;//pegando a altura da imagem
    
    //percorrendo a imagem (matriz)
    for(i=0;i<altura;i++){
        
        for(j=0;j<largura;j++){
            
            soma = 0;
            Vec3b bgrPixel = imagem.at<Vec3b>(i,j);//pegando o valor em RGB de um pixel
            soma = bgrPixel.val[2] + bgrPixel.val[1] + bgrPixel.val[0];//somando os valores de cada canal(RGB) do pixel
            soma = soma/3;
            //atribuindo o mesmo valor para o RGB de cada pixel
            imagem.at<Vec3b>(i,j).val[0] = soma;
            imagem.at<Vec3b>(i,j).val[1] = soma;
            imagem.at<Vec3b>(i,j).val[2] = soma;
            
        }
    }
    
    return(imagem);
}

void transformacao(Mat imagem, int L, int H){
    
    int i, j, largura, altura;
    float m = 0;
    float cinza, cor;
    largura = imagem.size().width;//pegando a largura da imagem
    altura = imagem.size().height;//pegando a altura da imagem
    
    for(i=0;i<altura;i++){
        
        for(j=0;j<largura;j++){
            
            Vec3b bgrPixel = imagem.at<Vec3b>(i,j);//pegando o valor em RGB de um pixel
            if(bgrPixel.val[0] < L){
                imagem.at<Vec3b>(i,j).val[0] = 0;
                imagem.at<Vec3b>(i,j).val[1] = 0;
                imagem.at<Vec3b>(i,j).val[2] = 0;
            }
            if(bgrPixel.val[0] > H){
                imagem.at<Vec3b>(i,j).val[0] = 255;
                imagem.at<Vec3b>(i,j).val[1] = 255;
                imagem.at<Vec3b>(i,j).val[2] = 255;
            }
            if(bgrPixel.val[0] <= H && bgrPixel.val[0] >= L){
                cinza = bgrPixel.val[0];
                // descobre o m da equacao fundamental da reta
                m = 255/(H-L);
                // descobre o novo ponto utilizando a equcao fundamental da reta
                cor =  m * (cinza - L);
                //atribui os novos valores
                imagem.at<Vec3b>(i,j).val[0] = cor;
                imagem.at<Vec3b>(i,j).val[1] = cor;
                imagem.at<Vec3b>(i,j).val[2] = cor;
            }
            
        }
    }
    
    imshow("Tranformado", imagem);
    waitKey(0);
}

int main(void){
    
    Mat image = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");
    Mat gray_image;
    
    int l,h, aux1,aux2;
    cout << "Digite um numero entre 0 e 255\n";
    cin >> aux1;
    cout << "Digite outro numero entre 0 e 255\n";;
    cin >> aux2;
    
    if(aux1>=aux2){
        h = aux1;
        l = aux2;
    }
    else{
        l = aux1;
        h = aux2;
    }
    if(aux1 > 255 || aux2 > 255){ 
        printf("Numero digitado maior do que 255\n");
    }
    else{
        cvtColor(image, gray_image, CV_BGR2GRAY);
        imshow("Grayscale", image);
        transformacao(image,l,h);
    }
}