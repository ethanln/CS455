#include "GLAdapter.h"

using namespace std;

void GLAdapter::setupWindow(int _window_width, int _window_height,
						 int _window_origin_x, int _window_origin_y, string _message)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(_window_width, _window_height); 
    glutInitWindowPosition (_window_origin_x, _window_origin_y);
    glutCreateWindow(_message.c_str());
}

void GLAdapter::init()
{
    // probably allow this to be configurable. ////////////
    
	/*  select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);

	/*  initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void GLAdapter::draw(GraphicObject* object)
{
	object->draw();
}

void GLAdapter::loop()
{
    glutMainLoop();
}