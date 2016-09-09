#ifndef IGLADAPTER_H
#define IGLADAPTER_H

#include <GL/glut.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "GraphicObject.h"
#include <cmath>
#include <iomanip>

using namespace std;

class IGLAdapter
{
	public:
		virtual ~IGLAdapter(){}

		virtual void setupWindow(int, int, int, int, string) = 0;
		
		virtual void init() = 0;

		virtual void draw() = 0;

		virtual void loop() = 0;
};
#endif