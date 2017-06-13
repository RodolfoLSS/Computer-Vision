#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

Mat mais_luminancia(Mat imagem){
    
    int largura, altura, i, j;
    double yiq[3], bgr[3];
    largura = imagem.size().width;//pega a largura da imagem
    altura = imagem.size().height;//pega a altura da imagem
    
    //percorrendo a imagem (matriz)
    for(i=0;i<altura;i++){
        for(j=0;j<largura;j++){
            Vec3b bgrPixel = imagem.at<Vec3b>(i,j);//pega o valor em RGB de um pixel
            
            bgr[0] = bgrPixel.val[0];
            bgr[1] = bgrPixel.val[1];
            bgr[2] = bgrPixel.val[2];
            
            yiq[0] = (double)(bgr[0]*0.299 + bgr[1]*0.587 + bgr[2]*0.114); //Y
            yiq[1] = (double)(bgr[0]*0.596 - bgr[1]*0.275 - bgr[2]*0.321); //I
            yiq[2] = (double)(bgr[0]*0.212 - bgr[1]*0.523 + bgr[2]*0.311); //Q
            
            yiq[0] = yiq[0] + 10;
            
            bgr[0] = (double)((yiq[0] + yiq[1]*0.956 + yiq[2]*0.62));// Ajusta R
            bgr[1] = (double)((yiq[0] - yiq[1]*0.272 - yiq[2]*0.647)); //Ajusta G
            bgr[2] = (double)((yiq[0] - yiq[1]*1.108 + yiq[2]*1.705)); //Ajusta B
            
            if(bgr[0] < 0)
                bgr[0] = 0;
            if(bgr[0] > 255)
                bgr[0] = 255;
            if(bgr[1] < 0)
                bgr[1] = 0;
            if(bgr[1] > 255)
                bgr[1] = 255;
            if(bgr[2] < 0)
                bgr[2] = 0;
            if(bgr[2] > 255)
                bgr[2] = 255;
            
            imagem.at<Vec3b>(i,j).val[0] = bgr[0];
            imagem.at<Vec3b>(i,j).val[1] = bgr[1];
            imagem.at<Vec3b>(i,j).val[2] = bgr[2];
        }
    }
    return(imagem);
}

Mat menos_luminancia(Mat imagem){
    
    int largura, altura, i, j;
    double yiq[3], bgr[3];
    largura = imagem.size().width;//pega a largura da imagem
    altura = imagem.size().height;//pega a altura da imagem
    
    //percorrendo a imagem (matriz)
    for(i=0;i<altura;i++){
        for(j=0;j<largura;j++){
            Vec3b bgrPixel = imagem.at<Vec3b>(i,j);//pega o valor em RGB de um pixel
            
            bgr[0] = bgrPixel.val[0];
            bgr[1] = bgrPixel.val[1];
            bgr[2] = bgrPixel.val[2];
            
            yiq[0] = (double)(bgr[0]*0.299 + bgr[1]*0.587 + bgr[2]*0.114); //Y
            yiq[1] = (double)(bgr[0]*0.596 - bgr[1]*0.275 - bgr[2]*0.321); //I
            yiq[2] = (double)(bgr[0]*0.212 - bgr[1]*0.523 + bgr[2]*0.311); //Q
            
            yiq[0] = yiq[0] - 10;
            
            bgr[0] = (double)((yiq[0] + yiq[1]*0.956 + yiq[2]*0.62));// Ajusta R
            bgr[1] = (double)((yiq[0] - yiq[1]*0.272 - yiq[2]*0.647)); //Ajusta G
            bgr[2] = (double)((yiq[0] - yiq[1]*1.108 + yiq[2]*1.705)); //Ajusta B
            
            
            if(bgr[0] < 0)
                bgr[0] = 0;
            if(bgr[0] > 255)
                bgr[0] = 255;
            if(bgr[1] < 0)
                bgr[1] = 0;
            if(bgr[1] > 255)
                bgr[1] = 255;
            if(bgr[2] < 0)
                bgr[2] = 0;
            if(bgr[2] > 255)
                bgr[2] = 255;
            
            imagem.at<Vec3b>(i,j).val[0] = bgr[0];
            imagem.at<Vec3b>(i,j).val[1] = bgr[1];
            imagem.at<Vec3b>(i,j).val[2] = bgr[2];
        }
    }
    return(imagem);
}


int main(){
    
    Mat imagem = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");//passa a imagem para matriz
    imshow("Luminancia", imagem);//exibe a imagem
    waitKey(10);
    int op =-1;
    
    while(1){
        
        cout << "1 -- Mais luminancia?\n2 -- Menos luminancia?\n0 -- Sair\n";
        cin >> op;
        if(op == 0)
            break;
        else if(op == 1)
            imagem = mais_luminancia(imagem);
        else if(op == 2)
            imagem = menos_luminancia(imagem);
        imshow("Luminancia", imagem);//exibe a imagem
        waitKey(10);
    }
    
    return 0;
};
