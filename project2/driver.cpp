
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdio>
#include "IGLAdapter.h"
#include "GLAdapter.h"
#include "GraphicObject.h"

using namespace std;

void init();
void display(void);

int main(int argc, char **argv)
{
	IGLAdapter* GL = new GLAdapter(argc, argv);
	GL->setupWindow(400, 400, 100, 100, "hello");
	GL->init();
	GL->draw(new GraphicObject("stuff"));
	//glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //glutInitWindowSize(450, 450); 
    //glutInitWindowPosition (100, 100);
    //glutCreateWindow("hello");
    //init ();
    //glutDisplayFunc(display); 
    glutMainLoop();

	cout << "stuff";
	return 0;
}
