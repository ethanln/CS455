#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H


#include <string>
#include <vector>
#include <glm/vec2.hpp> // glm::vec3
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <GL/glut.h>
#include <GL/glfw.h>
#include "ObjectParser.h"
#include "SOIL.h"

using namespace std;

class GraphicObject
{

	public:
		GraphicObject(string _object_uri, string _texture_file);

		~GraphicObject(){}

		void draw();

		GLuint loadBMP_custom(const char * imagepath);
};

#endif