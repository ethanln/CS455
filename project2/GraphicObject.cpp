#include "GraphicObject.h"

using namespace std;

GraphicObject::GraphicObject(string _object_uri)
{
    this->object_uri = _object_uri;
}

void GraphicObject::draw()
{
    glutDisplayFunc(display);
}

void GraphicObject::display(void)
{
    // IMPLMENT PARSING AND RENDERING HERE
    
	/*  clear all pixels  */
    glClear(GL_COLOR_BUFFER_BIT);

	/*  draw white polygon (rectangle) with corners at
	 *  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)  
	 */
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.75, 0.25, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.25, 0.75, 0.0);
    glEnd();

	/*  don't wait!  
	 *  start processing buffered OpenGL routines 
	 */
    glFlush();
}