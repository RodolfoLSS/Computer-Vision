//
//  main.cpp
//  openGL
//
//  Created by Rodolfo Saldanha on 7/27/17.
//  Copyright © 2017 Rodolfo Saldanha. All rights reserved.
//

#include <GLUT/glut.h>
#include <stdio.h>
#include "canvas.h"
#include <math.h>
#include <fstream>

using namespace std;

Canvas cvs(640, 480, "Exercicio 4");

void myInit(void){
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glLineWidth(2.0);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle)
{
    // assumes global Canvas object, cvs
    if(n < 3) return; // bad number of sides
    Point2 pt[n];
    double angle = rotAngle * 3.14159265 / 180; // initial angle
    double angleInc = 2 * 3.14159265 /n; //angle increment
    cvs.moveTo(radius + cx, cy);
    for(int k = 0; k < n; k++) // repeat n times
    {
        angle += angleInc;
        cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle) + cy);
        pt[k].set((radius * cos(angle) + cx), (radius * sin(angle) + cy));
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n ; j++)
        {
            cvs.moveTo(pt[i]); // connect all the vertices
            cvs.lineTo(pt[j]);
        }
    }
}

void pol(void){
    cvs.setWindow(0,640,0,480);
    glClear(GL_COLOR_BUFFER_BIT);
    int vertices;
    printf("Número de arestas do polígono: ");
    scanf("%d", &vertices);
    ngon(vertices, 250, 100, 70, 0);
}


int main(int argc, char** argv){
    myInit();
    glutDisplayFunc(pol);
    glutMainLoop();
}