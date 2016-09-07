#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include <string>
#include <GL/glut.h>
#include "ObjectParser.h"

using namespace std;

class GraphicObject
{
	private:
		ObjectParser* parser;

	public:
		GraphicObject(string _object_uri);

		~GraphicObject(){}

		void draw();
		
		static void display(void);
};

#endif