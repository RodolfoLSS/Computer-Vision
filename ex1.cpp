//
//  main.cpp
//  openGL
//
//  Created by Rodolfo Saldanha on 7/27/17.
//  Copyright © 2017 Rodolfo Saldanha. All rights reserved.
//

#include <GLUT/glut.h>
#include <math.h>

// coordenadas mundo
void setWindow(float left,float right,float bottom,float top)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left,right,bottom,top);
}
// subjanela de visualiza��o
// considera a janela definida no comando glutInitWindowSize(640,480);
//                                        *** tamanho da Janela ***
void setViewport(int left,int right,int bottom,int top)
{
    glViewport(left,bottom,right-left,top-bottom);
}

void myInit(void)
{
    glClearColor(1.0,1.0,1.0,0.0);        // set white background color
    glColor3f(0.0f, 0.0f, 0.0f);          // set the drawing color
    glPointSize(4.0);                 // a 'dot' is 4 by 4 pixels
    glLineWidth(2.0);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void plotsin()
{
    glBegin(GL_LINE_STRIP); {
        for(GLfloat x = -4.0; x < 4.0; x += 0.1)
        {
            GLfloat y = sin(3.14159 * x) / (3.14159 * x);
            glVertex2f(x, y);
        }
    } glEnd();
    
    glFlush();
}
void myDisplay(void)
{
    setWindow(-5.0,5.0,-0.3,1.0); // coordenada mundo obs:pode-se inverter os eixos para que a figura fique de cabe�a para baixo
    setViewport(0,640,0,480);     // Sub Janela de visualiza��o
    glClear(GL_COLOR_BUFFER_BIT);
    
    int a = 0, b = 384;
    
    for(int i=0; i<5; i++){
        setViewport(a,a+128,b,b+96);
        plotsin();
        a = a + 128;
    }
}
void myDisplay2(void)
{
    setWindow(-5.0,5.0,-0.3,1.0); // coordenada mundo obs:pode-se inverter os eixos para que a figura fique de cabe�a para baixo
    setViewport(0,640,0,480);     // Sub Janela de visualiza��o
    glClear(GL_COLOR_BUFFER_BIT);
    
    int a, b = 0;
    
    for(int i=0; i<5; i++){
        a = 0;
        for(int j=0; j<5; j++){
            setViewport(a,a+128,b,b+96);
            plotsin();
            a = a + 128;
        }
        b = b + 96;
    }
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
    glutInit(&argc, argv);            // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
    glutInitWindowSize(640,480);          // *** tamanho da Janela ***
    glutInitWindowPosition(100, 150);     // set window position on screen
    glutCreateWindow("A"); // open the screen window
    glutDisplayFunc(myDisplay);           // register redraw function
    myInit();
    //glutMainLoop();
    glutCreateWindow("B"); // open the screen window
    glutDisplayFunc(myDisplay2);           // register redraw function
    myInit();
    glutMainLoop();                       // go into a perpetual loop
}