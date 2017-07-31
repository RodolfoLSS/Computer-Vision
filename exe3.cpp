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

Canvas cvs(640, 480, "Padrao"); //global canvas object

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
    double angleInc;
    if(((cx == 160 || cx == 480) && cy == 380) || ((cx == 160 || cx == 480) && cy == 60))
        angleInc =   0.5 * 3.14159265 / n;
    else if(((cx == 240 || cx == 320 || cx == 400) && cy == 380) ||
            ((cx == 240 || cx == 320 || cx == 400) && cy == 60) ||
            (cx == 160 && (cy == 300 || cy == 220 || cy == 140)) ||
            (cx == 480 && (cy == 300 || cy == 220 || cy == 140)))
        angleInc =   3.14159265 / n;
    else
        angleInc =  2 * 3.14159265 / n;
    double x, y;
    cvs.moveTo(radius * cos(angle) + cx, radius * sin(angle)+cy);
    for(int k = 0; k < n; k++){
        angle += angleInc;
        x = radius * cos(angle) + cx;
        y = radius * sin(angle) + cy;
        cvs.lineTo(x, y);
    }
}

void drawCircle(Point2 center, float radius){
    const int numVerts = 50;
    int rotAngle;
    if((center.getX() == 160 && center.getY() == 380) ||
       (center.getX() == 160 && (center.getY() == 300 ||
        center.getY() == 220 || center.getY() == 140)))
        rotAngle = 270;
    else if((center.getX() == 480 || center.getX() == 240 ||
             center.getX() == 320 || center.getX() == 400) &&
             center.getY() == 380)
        rotAngle = 180;
    else if ((center.getX() == 480 && center.getY() == 60) ||
             (center.getX() == 480 && (center.getY() == 300 ||
             center.getY() == 220 || center.getY() == 140)))
        rotAngle = 90;
    else
        rotAngle = 0;
        
    ngon(numVerts, center.getX(), center.getY(), radius, rotAngle );
}

void circle(void){
    int a, b = 60;
    for(int i=0; i<5; i++){
        a = 160;
        for(int j=0; j<5; j++){
            Point2 ponto(a, b);
            drawCircle(ponto, 80);
            a = a + 80;
        }
        b = b + 80;
    }
}

void drawSquare(float n, float cx, float cy, float aresta) {
    float rot;
    if (n < 3)
        return;
    rot = 360/n;
    cvs.moveTo(cx, cy);
    for(int k = 0; k < n; k++) {
        cvs.forward(aresta,1);
        cvs.turn(rot);
    }
}

void square(void){
    cvs.setWindow(0,640,0,480);
    glClear(GL_COLOR_BUFFER_BIT);
    int a, b = 60;
    for(int i=0; i<4; i++){
        a = 160;
        for(int j=0; j<4; j++){
            drawSquare(4, a, b, 80.0);
            a = a + 80;
        }
        b = b + 80;
    }
}

void padrao(void){
    square();
    circle();
}


int main(int argc, char** argv){
    myInit();
    glutDisplayFunc(padrao);
    glutMainLoop();
    
}