#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

Mat nivel_cinza(){
    
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
            //atribui o mesmo valor para o RGB de cada pixel
            imagem.at<Vec3b>(i,j).val[0] = soma;
            imagem.at<Vec3b>(i,j).val[1] = soma;
            imagem.at<Vec3b>(i,j).val[2] = soma;
            
        }
    }
    
    imshow("Input Image", imagem);//exibe a imagem
    waitKey(0);
    return(imagem);
}

Mat aumenta_nivel(Mat imagem){
    
    int largura, altura, i, j, soma;
    largura = imagem.size().width;//pega a largura da imagem
    altura = imagem.size().height;//pega a altura da imagem
    
    //percorrendo a imagem (matriz)
    for(i=0;i<altura;i++){
        
        for(j=0;j<largura;j++){
            
            soma = 0;
            Vec3b bgrPixel = imagem.at<Vec3b>(i,j);//pega o valor em RGB de um pixel
            
            //atribui o mesmo valor para o RGB de cada pixel
            soma = bgrPixel.val[2] + bgrPixel.val[1] + bgrPixel.val[0] + 60;//soma os valores de cada canal(RGB) do pixel
            soma = soma/3;
            if(soma < 256){
                
                imagem.at<Vec3b>(i,j).val[0] = soma;
                imagem.at<Vec3b>(i,j).val[1] = soma;
                imagem.at<Vec3b>(i,j).val[2] = soma;
            }
        }
    }
    
    imshow("Input Image", imagem);//exibi a imagem
    waitKey(0);
    return(imagem);
}

Mat diminui_nivel(Mat imagem){
    
    int largura, altura, i, j, soma;
    largura = imagem.size().width;//pega a largura da imagem
    altura = imagem.size().height;//pega a altura da imagem
    
    //percorre a imagem (matriz)
    for(i=0;i<altura;i++){
        
        for(j=0;j<largura;j++){
            
            soma = 0;
            Vec3b bgrPixel = imagem.at<Vec3b>(i,j);//pega o valor em RGB de um pixel
            //atribuindo o mesmo valor para o RGB de cada pixel
            soma = bgrPixel.val[2] + bgrPixel.val[1] + bgrPixel.val[0] - 60;
            soma = soma/3;
            if(soma > 0){
                imagem.at<Vec3b>(i,j).val[0] = soma;
                imagem.at<Vec3b>(i,j).val[1] = soma;
                imagem.at<Vec3b>(i,j).val[2] = soma;
            }
        }
    }
    
    imshow("Input Image", imagem);//exibe a imagem
    waitKey(0);
    return(imagem);
}

int main(){
    
    Mat imagem = nivel_cinza();
    
    int op = 4;
    
    while(1){
        
        cout << "1 -- Mais claro ?\n2 -- Mais escuro?\n0 -- Sair\n";
        cin >> op;
        if(op == 0)
            break;
        else if(op == 1)
            imagem = aumenta_nivel(imagem);
        else if(op == 2)
            imagem = diminui_nivel(imagem);
    }
    
    return 0;
};
