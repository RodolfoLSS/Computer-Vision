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

Canvas cvs(640, 480, "Exercicio 7");

void myInit(void){
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glLineWidth(2.0);
}
void plot(){
    fstream inStream;
    inStream.open("/Users/RodolfoSaldanha/Downloads/dino.dat", ios ::in);
    if(inStream.fail()){
        return;
    }
    
    GLint numpolys, numLines, x ,y;
    inStream >> numpolys;
    for(int j = 0; j < numpolys; j++){
        inStream >> numLines;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < numLines; i++){
            inStream >> x >> y;
            glVertex2i(x, y);
        }
        glEnd();
    }
    inStream.close();
    glFlush();
}
void plot2(){
    fstream inStream;
    inStream.open("/Users/RodolfoSaldanha/Downloads/dino.dat", ios ::in);
    if(inStream.fail()){
        return;
    }
    GLint numpolys, numLines, x ,y;
    inStream >> numpolys;
    for(int j = 0; j < numpolys; j++){
        inStream >> numLines;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < numLines; i++){
            inStream >> x >> y;
            glVertex2i(x, 480-y);
        }
        glEnd();
    }
    inStream.close();
    glFlush();
}
void plot3(){
    fstream inStream;
    inStream.open("/Users/RodolfoSaldanha/Downloads/dino.dat", ios ::in);
    if(inStream.fail()){
        return;
    }
    GLint numpolys, numLines, x ,y;
    inStream >> numpolys;
    for(int j = 0; j < numpolys; j++){
        inStream >> numLines;
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < numLines; i++){
            inStream >> x >> y;
            glVertex2i(640-x, y);
        }
        glEnd();
    }
    inStream.close();
    glFlush();
}

void exe2(void){
    cvs.setWindow(0,640,0,480);
    glClear(GL_COLOR_BUFFER_BIT);
    
    cvs.setViewport(60,220,240,360);
    plot();
    
    cvs.setViewport(320,640,240,480);
    plot();
    
    cvs.setViewport(320,640,0,240);
    plot2();
    
    cvs.setViewport(0,320,0,240);
    plot3();
}

int main(int argc, char** argv){
    myInit();
    glutDisplayFunc(exe2);
    glutMainLoop();
}
