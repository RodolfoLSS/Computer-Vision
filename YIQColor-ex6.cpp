#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

Mat nivel_cor(){
    
    Mat imagem = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");//passa a imagem para matriz
    int largura, altura, i, j, soma;
    largura = imagem.size().width;//pega a largura da imagem
    altura = imagem.size().height;//pega a altura da imagem
    
    //percorrendo a imagem (matriz)
    for(i=0;i<altura;i++){
        
        for(j=0;j<largura;j++){
            
            soma = 0;
            Vec3b bgrPixel = imagem.at<Vec3b>(i,j);//pega o valor em RGB de um pixel
            soma = bgrPixel.val[2] + bgrPixel.val[1] + bgrPixel.val[0];//soma os valores de cada canal(RGB) do pixel
            soma = soma/3;
            //conversao RGB -> YIQ
            imagem.at<Vec3b>(i,j).val[0] = bgrPixel.val[0]*0.299 + bgrPixel.val[1]*0.587 + bgrPixel.val[2]*0.114; //Y
            imagem.at<Vec3b>(i,j).val[1] = 0.74*(bgrPixel.val[0]-imagem.at<Vec3b>(i,j).val[0]) - 0.27*(bgrPixel.val[2]-imagem.at<Vec3b>(i,j).val[0]); //I
            imagem.at<Vec3b>(i,j).val[2] = 0.48*(bgrPixel.val[0]-imagem.at<Vec3b>(i,j).val[0]) - 0.41*(bgrPixel.val[2]-imagem.at<Vec3b>(i,j).val[0]); //Q
            
        }
    }
    return(imagem);
}

Mat mais_escura(Mat imagem){
    
    int largura, altura, i, j;
    largura = imagem.size().width;//pega a largura da imagem
    altura = imagem.size().height;//pega a altura da imagem
    
    //percorrendo a imagem (matriz)
    for(i=0;i<altura;i++){
        
        for(j=0;j<largura;j++){
            if(imagem.at<Vec3b>(i,j).val[0] >= 15)
               imagem.at<Vec3b>(i,j).val[0] -= 15; //deixa mais escuro
        }
    }
    return(imagem);
}

Mat mais_clara(Mat imagem){
    
    int largura, altura, i, j;
    largura = imagem.size().width;//pega a largura da imagem
    altura = imagem.size().height;//pega a altura da imagem
    
    //percorrendo a imagem (matriz)
    for(i=0;i<altura;i++){
        
        for(j=0;j<largura;j++){
            if(imagem.at<Vec3b>(i,j).val[0] <= 240)
                imagem.at<Vec3b>(i,j).val[0] += 15; //deixa mais clara
        }
    }
    return(imagem);
}

int main(){
    
    Mat imagem = nivel_cor();
    int op =-1;
    
    while(1){
        
        imshow("Nivel de cinza", imagem);//exibe a imagem
        waitKey(10);
        cout << "1 -- Mais claro?\n2 -- Mais escuro?\n0 -- Sair\n";
        cin >> op;
        if(op == 0)
            break;
        else if(op == 1)
            imagem = mais_clara(imagem);
        else if(op == 2)
            imagem = mais_escura(imagem);
    }
    
    return 0;
};