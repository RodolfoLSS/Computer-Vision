#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

//método que cálcula o histograma de uma imagem em níveis de cinza
void normaliza_histograma(Mat imagem){

	int largura, altura, i, j, posic;
	double N;
	int nk[256], sk[256];
	double soma, aux;
	largura = imagem.size().width;
	altura = imagem.size().height;
	N = largura*altura;//número total de pixels da imagem
	
	//Mat hsv;
	//inicializando o vetor com 0
	for(i=0; i<256; i++){

		nk[i] = 0;
	}

	//percorrendo a matriz
	for(i=0; i<altura; i++){

		for(j=0; j<largura; j++){

			Vec3b pixel = imagem.at<Vec3b>(i,j);
			nk[pixel.val[2]]++;
		}
	}

	//equalizando o histograma da imagem
	for(i=0; i<256; i++){

		soma=0;
		for(j=0;j<=i;j++){

			aux = (double)(nk[j]/N);
			soma=soma+aux;
		}

		soma = soma*255;
		sk[i] = (int)(soma);
	}
	
	//atribui o valor do histograma equalizado para a matriz
	for(i=0; i<altura; i++){

		for(j=0; j<largura; j++){

			Vec3b pixel = imagem.at<Vec3b>(i,j);
			
			//verificando qual o valor de cada canal do pixel 
			for(posic=0; posic<256; posic++){

				if(posic == pixel.val[2])
					break;
			}
			//atribuindo o valor do histograma equalizado
			//imagem.at<Vec3b>(i,j).val[0] = sk[posic];
			//imagem.at<Vec3b>(i,j).val[1] = sk[posic];
			imagem.at<Vec3b>(i,j).val[2] = sk[posic];
		}
	}
	//exibindo a imagem
	Mat fullImageRGB;
	//transforma de HSV para RGB para conseguir mostrar a imagem
	cvtColor(imagem, fullImageRGB, CV_HSV2BGR);
	imshow("equalização", fullImageRGB);
	waitKey(0);
}

int main(void){
	//carrega a imagem
	Mat imagem = imread("/Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/teste.png");
	Mat fullImageHSV;
	//transforma a imagem de RGB para HSV;
	cvtColor(imagem, fullImageHSV, CV_BGR2HSV);
	normaliza_histograma(fullImageHSV);
}