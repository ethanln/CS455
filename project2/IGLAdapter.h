#ifndef IGLADAPTER_H
#define IGLADAPTER_H

#include <GL/glut.h>
#include <string>
#include "GraphicObject.h"

using namespace std;

class IGLAdapter
{
	public:
		virtual ~IGLAdapter(){}

		virtual void setupWindow(int, int, int, int, string) = 0;
		
		virtual void init() = 0;

		virtual void draw(GraphicObject*) = 0;

		virtual void loop() = 0;
};
#endif