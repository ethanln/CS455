#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include <string>
#include <vector>
#include <glm/vec2.hpp> // glm::vec3
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <GL/glut.h>
#include "ObjectParser.h"

using namespace std;

class GraphicObject
{
	private:
		ObjectParser* parser;
		
		vector<glm::vec3> out_vertices;
		vector<glm::vec2> out_uvs;
		vector<glm::vec3> out_normals;

	public:
		GraphicObject(string _object_uri);

		~GraphicObject(){}

		void draw();
		
		static void display(void);
};

#endif