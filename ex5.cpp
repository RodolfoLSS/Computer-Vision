#include <GLUT/glut.h>
#include "canvas.h"
#include <math.h>

Canvas cvs(500, 500, (char*) "Exercicio 5");
const double radius = 14.0;

void myInit(void) {
    cvs.setBackgroundColor(1.0, 1.0, 1.0);
    cvs.setColor(0.0, 0.0, 0.0);
    glPointSize(4.0);                 // ponto 4x4
    glLineWidth(5.0);
}



void drawShape1(int x,int y) {
    cvs.moveTo(x,y);
    cvs.lineTo(x,y+50);
    cvs.lineTo(x+50,y+75);
    cvs.lineTo(x+50,y+125);
    cvs.lineTo(x+100,y+100);
    cvs.lineTo(x+100,y+50);
    cvs.lineTo(x+150,y+25);
    cvs.lineTo(x+100,y);
    cvs.lineTo(x+50,y+25);
    cvs.lineTo(x,y);
    glFlush();
}


void myDisplay(void) {
    cvs.setWindow(0, 800, 0, 800);
    cvs.setViewport(0, 480, 0, 480);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    drawShape1(500, 500);
    drawShape1(650, 525);
    drawShape1(600, 400);
    drawShape1(450, 375);
    drawShape1(350, 475);
    drawShape1(400, 600);
    drawShape1(550, 625);
    
}


int main(int argc, char** argv) {
    myInit();
    glutDisplayFunc(myDisplay);           // register redraw function
    glutDisplayFunc(myDisplay);
    glutMainLoop();                       // go into a perpetual loop
}
