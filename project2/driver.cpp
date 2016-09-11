
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdio>
#include "IGLAdapter.h"
#include "GLAdapter.h"
#include "GraphicObject.h"

using namespace std;

int main(int argc, char **argv)
{
	// MAKE A CONFIG PARSER //////////
	printf("Setting up shell...\n");
	IGLAdapter* GL = new GLAdapter(argc, argv, new GraphicObject("objects/crayon-color.obj", "images/greenCrayon.bmp"));
	GL->setupWindow(1000, 1000, 100, 100, "hello");
	GL->init();
	
	printf("Drawing...\n");

	// GraphicObject* obj = new GraphicObject("objects/crayonbox-color.obj");
	GL->draw();
	printf("Loop...\n");
	GL->loop();

	return 0;
}

