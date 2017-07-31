#include<opencv2/opencv.hpp>
#define RESOLUCAO 800
using namespace cv;
// Deforma...
Mat deformar(Mat input, int V1[], int V2[], int V3[], int W1[], int W2[], int W3[]){
    Mat output;
    output.create(input.rows, input.cols, CV_8UC3);
    
    for(int c1=0; c1<=RESOLUCAO; c1++){
        for(int c2=0; c2<=RESOLUCAO; c2++){
            for(int c3=0; c3<=RESOLUCAO; c3++){
                //printf("> %f\n",c1+c2+c3);
                //float x = c1+c2+c3;
                if((c1+c2+c3) == RESOLUCAO){
                    //printf("> Esta dentro do triangulo de entrada!\n");
                    
                    int V_x = (c1*V1[0] + c2*V2[0] + c3*V3[0])/RESOLUCAO;
                    int V_y = (c2*V1[1] + c2*V2[1] + c3*V3[1])/RESOLUCAO;
                    
                    int W_x = (c1*W1[0] + c2*W2[0] + c3*W3[0])/RESOLUCAO;
                    int W_y = (c2*W1[1] + c2*W2[1] + c3*W3[1])/RESOLUCAO;
                    
                    output.at<Vec3b>(W_x,W_y)[0] = input.at<Vec3b>(V_x,V_y)[0];
                    output.at<Vec3b>(W_x,W_y)[1] = input.at<Vec3b>(V_x,V_y)[1];
                    output.at<Vec3b>(W_x,W_y)[2] = input.at<Vec3b>(V_x,V_y)[2];
                    
                }
            }
        }
    }
    
    return output;
}

int main(){
    Mat input = imread( "//Users/RodolfoSaldanha/Desktop/opencv-3.2.0/OpenCV/OpenCV/lena.png", 1 );
    
    int V1[2] = {0,0};
    int V2[2] = {510,0};                         //Point2f(input.cols,0);
    int V3[2] = {0,510};     //Point2f(input.cols+RESOLUCAO,input.rows+50);
    
    int W1[2] = {0,0};
    int W2[2] = {250,0};                   //Point2f(input.cols-1,0);
    int W3[2] = {250,510};        //Point2f(input.cols-1,input.rows-1);
    
    Mat output = deformar(input, V1, V2, V3, W1, W2, W3);
    
    
    imshow("Input",input);
    waitKey(0);
    imshow("Output",output);
    waitKey(0);
    return 0;
}
