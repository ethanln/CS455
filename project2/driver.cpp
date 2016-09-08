
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
	// MAKE A CONFIG PARSER //////////
	cout << "Setting up shell...";
	IGLAdapter* GL = new GLAdapter(argc, argv);
	GL->setupWindow(400, 400, 100, 100, "hello");
	GL->init();

	cout << "Drawing...";
	GL->draw(new GraphicObject("objects/crayonbox-color.obj"));
	cout << "Loop...";
	GL->loop();

	cout << "stuff";
	return 0;
}
