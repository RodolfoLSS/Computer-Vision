//
//  main.cpp
//  openGL
//
//  Created by Rodolfo Saldanha on 7/27/17.
//  Copyright © 2017 Rodolfo Saldanha. All rights reserved.
//

#include <GLUT/glut.h>
#include "canvas.h"
#include <math.h>
#include <fstream>

using namespace std;

Canvas cvs(640, 480, "Exercicio 2");

void myInit(void){
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glLineWidth(2.0);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle){
    if(n < 3){
        return;
    }
    double angle = rotAngle * 3.14159265/180.0;
    double angleInc = 2 * 3.14159265 / n;
    cvs.moveTo(radius * cos(angle) + cx, radius * sin(angle)+cy);
    for(int k = 0; k < n; k++){
        angle += angleInc;
        cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle)+cy);
    }
}

void drawCircle(Point2 center, float radius){
    const int numVerts = 50;
    ngon(numVerts, center.getX(), center.getY(), radius, 0 );
}

void exe2(void){
    cvs.setWindow(0,640,0,480);
    glClear(GL_COLOR_BUFFER_BIT);
    Point2 ponto(320,240);
    drawCircle(ponto, 50);
    Point2 ponto2(420,240);
    drawCircle(ponto2, 50);
    Point2 ponto3(220,240);
    drawCircle(ponto3, 50);
    Point2 ponto4(270,327);
    drawCircle(ponto4, 50);
    Point2 ponto5(370,327);
    drawCircle(ponto5, 50);
    Point2 ponto6(270,154);
    drawCircle(ponto6, 50);
    Point2 ponto7(370,154);
    drawCircle(ponto7, 50);
}


int main(int argc, char** argv){
    myInit();
    glutDisplayFunc(exe2);
    glutMainLoop();
}