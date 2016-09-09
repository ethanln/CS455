#include "GraphicObject.h"

using namespace std;

vector<glm::vec3> out_vertices;
vector<glm::vec2> out_uvs;
vector<glm::vec3> out_normals;

GraphicObject::GraphicObject(string _object_uri)
{
    ObjectParser* parser = new ObjectParser();
    parser->parse(_object_uri, out_vertices, out_uvs, out_normals);
}

void GraphicObject::draw()
{

	/*  clear all pixels  */
    glClear(GL_COLOR_BUFFER_BIT);

	/*  
	 *  instantiate paint color as white
	 */
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        for(unsigned int i = 0; i < out_vertices.size(); i++){
            glVertex3f(out_vertices.at(i).x, out_vertices.at(i).y, out_vertices.at(i).z);
        }
    glEnd();

	/*  
	 *  start processing buffered OpenGL routines 
	 */
    glFlush();
}