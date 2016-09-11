#include "GraphicObject.h"

using namespace std;

vector<glm::vec3> out_vertices;
vector<glm::vec2> out_uvs;
vector<glm::vec3> out_normals;

GLuint texName;
int width;
int height;

unsigned char* image;

GraphicObject::GraphicObject(string _object_uri, string _texture_file)
{
    ObjectParser* parser = new ObjectParser();
    parser->parse(_object_uri, out_vertices, out_uvs, out_normals);

    
    //texName = loadBMP_custom(_texture_file.c_str());
    
    image = SOIL_load_image(_texture_file.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
    glEnable(GL_TEXTURE_2D);

    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    SOIL_free_image_data(image);

}

void GraphicObject::draw()
{   
        /*  clear all pixels  */
    glClear(GL_COLOR_BUFFER_BIT);
    cout << texName;
    /* TEXTURES SETUP */
    glEnable(GL_TEXTURE_2D); 
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); 
    glBindTexture(GL_TEXTURE_2D, texName);  

	/*  
	 *  instantiate paint color as white
	 */
    //glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS); 
        for(unsigned int i = 0; i < out_uvs.size(); i++){
            glTexCoord2f (out_uvs[i].x, out_uvs[i].y);
            glVertex3f(out_vertices.at(i).x, out_vertices.at(i).y, out_vertices.at(i).z);
        }

        
    glEnd();   

	/*  
	 *  start processing buffered OpenGL routines 
	 */
    glFlush();

    glDisable (GL_TEXTURE_2D);  
}




GLuint GraphicObject::loadBMP_custom(const char * imagepath)
{

    printf("Reading image %s\n", imagepath);

    // Data read from the header of the BMP file
    unsigned char header[54];
    unsigned int dataPos;
    unsigned int imageSize;
    unsigned int width, height, bpp;
    // Actual RGB data
    unsigned char * data;

    // Open the file
    FILE * file = fopen(imagepath,"rb");
    if (!file)
    {
        printf("Image could not be opened\n"); 
        return 0;
    }

    // Read the header, i.e. the 54 first bytes

    // If less than 54 byes are read, problem
    if ( fread(header, 1, 54, file)!=54 ){ 
        printf("Not a correct BMP file\n");
        return false;
    }

    // A BMP files always begins with "BM"
    if ( header[0]!='B' || header[1]!='M' ){
        printf("Not a correct BMP file\n");
        return 0;
    }
    // Make sure this is a 24bpp file
    if ( *(int*)&(header[0x1E])!=0  )         {printf("Not a correct BMP file\n");    return 0;}
    if ( *(int*)&(header[0x1C])!=24 )         {printf("Not a correct BMP file\n");    return 0;}

    // Read the information about the image
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);
    bpp = 3;

    // Some BMP files are misformatted, guess missing information
    if (imageSize == 0)
    {
        imageSize = width*height*3; // 3 : one byte for each Red, Green and Blue component
    } 

    if (dataPos == 0)
    {
        dataPos = 54;
    }

    // Create a buffer
    data = new unsigned char [imageSize];

    // Read the actual data from the file into the buffer
    fread(data,1,imageSize,file);

    // Everything is in memory now, the file wan be closed
    fclose (file);

    // Swap Red and Blue component for each texel of the image
    unsigned char t;
    for (unsigned int i = 0; i < imageSize; i += 3 )
    {
        t = data[i];
        data[i] = data[i+2];
        data[i+2] = t;
    }

    // Create one OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);
    
    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0,(bpp == 3 ? GL_RGB : GL_RGBA), GL_UNSIGNED_BYTE, data);

    // Poor filtering, or ...
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 

    // ... nice trilinear filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
    //glGenerateMipmap(GL_TEXTURE_2D);

    cout << "STUFF: ";
    cout << sizeof(data);
    cout << "\n";
    // Return the ID of the texture we just created
    return textureID;
}