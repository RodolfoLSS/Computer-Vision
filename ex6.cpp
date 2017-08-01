#include <GLUT/glut.h>
#include "canvas.h"
#include <math.h>
#include <fstream>

using namespace std;

Canvas cvs(640, 480, "Exercicio 6");

void myInit(void){
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glLineWidth(2.0);
}

void gateAnd(int n, float cx, float cy, float radius, float rotAngle){
    if(n < 3){
        return;
    }
    double angle = rotAngle * 3.14159265/180.0;
    double angleInc =  3.14159265 / n;
    cvs.moveTo(radius * cos(angle) + cx, radius * sin(angle)+cy);
    for(int k = 0; k < n; k++){
        angle += angleInc;
        cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle)+cy);
        if(k == 24){
            cvs.forward(20,1);
            cvs.turn(180);
            cvs.forward(20,1);
        }
    }
    cvs.forward(50,1);
    cvs.turn(90);
    
    cvs.forward(10,1);
    cvs.turn(270);
    cvs.forward(20,1);
    cvs.turn(180);
    cvs.forward(20,1);
    cvs.turn(270);
    cvs.forward(40,1);
    cvs.turn(270);
    cvs.forward(20,1);
    cvs.turn(180);
    cvs.forward(20,1);
    cvs.turn(270);
    cvs.forward(10,1);
    
    cvs.turn(90);
    cvs.forward(50,1);
}

void drawAnd(Point2 center, float radius){
    const int numVerts = 50;
    gateAnd(numVerts, center.getX(), center.getY(), radius, 270 );
}

void gate(int n, float cx, float cy, float radius, float rotAngle){
    if(n < 3){
        return;
    }
    double angle = rotAngle * 3.14159265/180.0;
    double angleInc =  2 * 3.14159265 / n;
    cvs.moveTo(radius * cos(angle) + cx, radius * sin(angle)+cy);
    for(int k = 0; k < n; k++){
        angle += angleInc;
        cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle)+cy);
        if(k == 24){
            cvs.turn(90);
            cvs.forward(30,1);
            cvs.turn(180);
            cvs.forward(30,1);
        }
    }
}

void triangle(int n, float cx, float cy, float radius, float rotAngle){
    if(n < 3){
        return;
    }
    double angle = rotAngle * 3.14159265/180.0;
    double angleInc =  2 * 3.14159265 / n;
    cvs.moveTo(radius * cos(angle) + cx, radius * sin(angle)+cy);
    for(int k = 0; k < n; k++){
        angle += angleInc;
        cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle)+cy);
        if(k == 1){
            cvs.turn(90);
            cvs.forward(25,1);
            cvs.turn(90);
            cvs.forward(20,1);
            cvs.turn(180);
            cvs.forward(20,1);
            cvs.turn(270);
            cvs.forward(25,1);
        }
    }
}

void drawGate(Point2 center, float radius){
    int numVerts = 3;
    triangle(numVerts, center.getX(), center.getY(), radius, 0 );
    radius = 4;
    numVerts = 50;
    gate(numVerts, 315, center.getY(), radius, 180 );
}

void exe6(void){
    cvs.setWindow(0,640,0,480);
    glClear(GL_COLOR_BUFFER_BIT);
    Point2 ponto(320,240);
    drawAnd(ponto, 30);
    Point2 ponto2(280,320);
    drawGate(ponto2, 30);
}


int main(int argc, char** argv){
    myInit();
    glutDisplayFunc(exe6);
    glutMainLoop();
}