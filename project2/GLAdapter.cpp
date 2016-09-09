#include "GLAdapter.h"

using namespace std;

int orientation;
float camX;
float camY;
float camZ;

GraphicObject* obj;
/**
* EVENT HANDLERS
*/
void GLKeyDown(unsigned char key, int x, int y)
{
    
    if(key == 'w'){
        //camZ += 0.4f;
        camZ += 0.5 * sin((( (orientation + 90) * M_PI ) / 180 ));
        camX += 0.5 * cos((( (orientation + 90) * M_PI ) / 180 ));
        camZ += 0.5 * sin((( 0 * M_PI ) / 180 ));
    }
    else if(key == 's'){
        //camZ -= 0.4f;
        camZ -= 0.5 * sin((( (orientation + 90) * M_PI ) / 180 ));
        camX -= 0.5 * cos((( (orientation + 90) * M_PI ) / 180 ));
        camZ -= 0.5 * sin((( 0 * M_PI ) / 180 ));
    }
    else if(key == 'a'){
        //camX += 0.4f;
        camZ += 0.5 * sin((( orientation * M_PI ) / 180 ));
        camX += 0.5 * cos((( orientation * M_PI ) / 180 ));
    }
    else if(key == 'd'){
        //camX -= 0.4f;
        camZ -= 0.5 * sin((( orientation * M_PI ) / 180 ));
        camX -= 0.5 * cos((( orientation * M_PI ) / 180 ));
    }

    /* intialize camera view*/
    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((( orientation * M_PI ) / 180 ), 0.0f, 1.0f, 0.0f);
        glTranslated(camX, camY, camZ);

    obj->draw();
}

float lastx = 0.0;
float lasty = 0.0;

void GLMouseMovement(int x, int y) 
{

    if(x < lastx)
    {
        orientation -= 70;
    }
    else
    {
        orientation += 70;
    }


    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((( orientation * M_PI ) / 180 ), 0.0f, 1.0f, 0.0f);
        glTranslated(camX, camY, camZ);

    obj->draw();
    lastx = (float)x;
}

/**
* END OF EVENT HANDLERS
*/

GLAdapter::GLAdapter(int argc, char **argv, GraphicObject* _obj)
{
    glutInit(&argc, argv);
    orientation = 0;
    camX = 0.0f;
    camY = 0.0f;
    camZ = 0.0f;
    obj = _obj;
}

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
    gluPerspective(45.0f, 1280.0f/960.0f, 0.000001f, 1000.0f);

    /* intialize camera view*/
    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((( orientation * M_PI ) / 180 ), 0.0f, 1.0f, 0.0f);
        glTranslated(camX, camY, camZ);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    float col[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, col);

    /* initialize event handlers */
    glutKeyboardFunc(GLKeyDown);
    glutMotionFunc(GLMouseMovement);
}

void GLAdapter::draw()
{
	obj->draw();
}

void GLAdapter::loop()
{
    glutMainLoop();
}


