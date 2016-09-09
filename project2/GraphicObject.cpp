#include "GraphicObject.h"

using namespace std;

vector<glm::vec3> out_vertices;
vector<glm::vec2> out_uvs;
vector<glm::vec3> out_normals;

string texture_name;

GraphicObject::GraphicObject(string _object_uri, string _texture_file)
{
    ObjectParser* parser = new ObjectParser();
    parser->parse(_object_uri, out_vertices, out_uvs, out_normals);
    texture_name = _texture_file;
}

void GraphicObject::draw()
{
    /* TEXTURES SETUP */
    GLuint texName;

    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
    glTexParameteri(GL_TEXTURE_2D, 
        GL_TEXTURE_WRAP_S, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, 
        GL_TEXTURE_WRAP_T, GL_REPEAT); 

    int width, height;

    unsigned char* image = SOIL_load_image("images/CrayonBox2.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE, image);

    glEnable(GL_TEXTURE_2D); 
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); 
    glBindTexture(GL_TEXTURE_2D, texName);  
    

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

    glBegin(GL_QUADS); 
        for(unsigned int i = 0; i < out_uvs.size(); i++){
            glTexCoord2f (out_uvs[i].x, out_uvs[i].y);  
        }
    glEnd();   

    glutSwapBuffers(); 

	/*  
	 *  start processing buffered OpenGL routines 
	 */
    glFlush();

    glDisable (GL_TEXTURE_2D);  
}