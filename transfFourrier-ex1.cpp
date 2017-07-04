#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;

void transfFourier(Mat image){
    Mat padded;                            // expande imagem para tamanho ótimo(2,3 ou 5)
    int m = getOptimalDFTSize( image.rows );
    int n = getOptimalDFTSize( image.cols ); // adiciona 0 nas bordas
    copyMakeBorder(image, padded, 0, m - image.rows, 0, n - image.cols, BORDER_CONSTANT, Scalar::all(0));
    
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complexI;
    merge(planes, 2, complexI);         // Adiciona a matriz mais um plano de 0
    
    dft(complexI, complexI);            // Faz com que o resultado caiba na matriz original
    
    // Computa a magnetude e troca para a escala logaritmica
    // => log(1 + sqrt(Re(DFT(image))^2 + image.m(DFT(image))^2))
    split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = image.m(DFT(image))
    magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnetude
    Mat magI = planes[0];
    
    magI += Scalar::all(1);                    // troca para a escala logaritimica
    log(magI, magI);
    
    // recorta o espectro se houver um numero impar de col ou linhas
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
    
    // rearranja os quadrantes da imagem transformada para centralizar a imagem original
    int cx = magI.cols/2;
    int cy = magI.rows/2;
    
    Mat q0(magI, Rect(0, 0, cx, cy));   // Esquerda em cima
    Mat q1(magI, Rect(cx, 0, cx, cy));  // Direita em cima
    Mat q2(magI, Rect(0, cy, cx, cy));  // Esquerda em baixo
    Mat q3(magI, Rect(cx, cy, cx, cy)); // Direita em baixo
    
    Mat tmp;                           // Troca os quadrantes
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    
    q1.copyTo(tmp);                    // Troca os quadrantes
    q2.copyTo(q1);
    tmp.copyTo(q2);
    
    normalize(magI, magI, 0, 1, NORM_MINMAX); // Transforma a matriz de float em imagem com forma - valores entre 0 e 1
    
    imshow("Transformada de Fourier", magI);
    waitKey();
    
    // Calcula a tranformada inversa
    Mat inverseTransform;
    dft(complexI, inverseTransform, DFT_INVERSE|DFT_REAL_OUTPUT);
    normalize(inverseTransform, inverseTransform, 0, 1, CV_MINMAX);
    imshow("Transformada Inversa - Imagem Reconstruida", inverseTransform);
    waitKey();
}

int main(){
    Mat gray_image, result;
    Mat image = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");//passa a imagem para matriz
    
    if( !image.data ) {
        printf( "No image data \n" );
        return -1;
    }
    
    cvtColor(image, gray_image, CV_BGR2GRAY);
    imshow("Original", gray_image);//exibe a imagem
    waitKey(0);
    
    transfFourier(gray_image);
    
    return 0;
};n 0;
};