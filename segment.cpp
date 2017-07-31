#include <iostream>
#include <opencv2/opencv.hpp>
#include <stdio.h>


using namespace cv;
using namespace std;

Mat show_result(const Mat& labels, const Mat& centers, int height, int width){
    // A variavel labels indica uma matriz, cada linha dela tem um valor label, Se o numero de cluster e 3, o valor é 0, 1 e 2. A variavel centers e um num_cluster x3 matriz. A cada linha, ela tem uma coordenada de um centro de um cluster. Neste caso, a coordenada correspondente ao vetor de espaco RGB
    assert(labels.type() == CV_32SC1);
    assert(centers.type() == CV_32FC1);
    // Prepara uma matriz RGB na qual a imagem é guardada
    Mat rgb_image(height, width, CV_8UC3);
    MatIterator_<Vec3b> rgb_first = rgb_image.begin<Vec3b>();
    MatIterator_<Vec3b> rgb_last = rgb_image.end<Vec3b>();
    MatConstIterator_<int> label_first = labels.begin<int>();
    
    // A matriz center possui valores float. Esses valores sao convertidos em uint8 com range de 0 á 255.
    Mat centers_u8;
    centers.convertTo(centers_u8, CV_8UC1, 255.0);
    Mat centers_u8c3 = centers_u8.reshape(3);
    
    // A label e trocada pelos (B,G,R) correspondentes para fazer a imagem final rgb_image
    while(rgb_first != rgb_last){
        const Vec3b& rgb = centers_u8c3.ptr<Vec3b>(*label_first)[0];
        *rgb_first = rgb;
        ++rgb_first;
        ++label_first;
    }
    return rgb_image;
}

int main(){
    // Carrega a imagem original a ser trabalhada e exibe na tela
    Mat image = imread("/Users/RodolfoSaldanha/Downloads/vaso.bmp");
    if(image.empty()){
        cout << "unable to load an input image\n";
        return 1;
    }
    imshow("input", image);
    waitKey();
    assert(image.type() == CV_8UC3);
    
    Mat reshaped_image = image.reshape(1, image.cols * image.rows);
    assert(reshaped_image.type() == CV_8UC1);
    
    Mat reshaped_image32f;
    reshaped_image.convertTo(reshaped_image32f, CV_32FC1, 1.0 / 255.0);
    assert(reshaped_image32f.type() == CV_32FC1);
    
    // Apos preparar as duas matrizes para saida (labels e centers) e criado uma instancia de TermCriteria na qual representa as condicoes para sair o algoritmo, nos executamos a funcao kmeans.
    Mat labels;
    int cluster_number = 5; // Numero de clusters (cluster_number == numero de cores da img)
    TermCriteria criteria(TermCriteria::COUNT, 100, 1);
    Mat centers;
    kmeans(reshaped_image32f, cluster_number, labels, criteria, 1, KMEANS_RANDOM_CENTERS, centers);
    Mat image_result = show_result(labels, centers, image.rows, image.cols);
    
    imshow("output", image_result);
    waitKey();
    return 0;
}
