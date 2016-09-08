#include "ObjectParser.h"

using namespace std;

bool ObjectParser::parse(string file_path, 
						vector<glm::vec3> &out_vertices, 
						vector<glm::vec2> &out_uvs, 
						vector<glm::vec3> &out_normals)
{
	FILE * file = fopen(file_path.c_str(), "r");

	if(file == NULL)
	{
		printf("File doesn't exists \n");
		return false;
	}
	else
	{
		printf("File does exist");
	}

	while( 1 )
	{
	    char lineHeader[128];
	    // read the first word of the line
	    int res = fscanf(file, "%s", lineHeader);
	    if (res == EOF)
	    {
	        break; // EOF = End Of File. Quit the loop.
	    }
	    
	    if(strcmp(lineHeader, "v") == 0)
	    {
		    glm::vec3 vertex;
		    fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
		    temp_vertices.push_back(vertex);
		}
		else if(strcmp(lineHeader, "vt") == 0)
		{
		    glm::vec2 uv;
		    fscanf(file, "%f %f\n", &uv.x, &uv.y );
		    temp_uvs.push_back(uv);
		}
		else if(strcmp(lineHeader, "vn") == 0)
		{
		    glm::vec3 normal;
		    fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
		    temp_normals.push_back(normal);
		}
		else if ( strcmp( lineHeader, "f" ) == 0 )
		{
		    std::string vertex1;
		    std::string vertex2;
		    std::string vertex3;

		    unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
		    int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
		    if (matches != 9)
		    {
		        printf("File can't be read by our simple parser : ( Try exporting with other options\n");
		        return false;
		    }
		    vertexIndices.push_back(vertexIndex[0]);
		    vertexIndices.push_back(vertexIndex[1]);
		    vertexIndices.push_back(vertexIndex[2]);
		    uvIndices    .push_back(uvIndex[0]);
		    uvIndices    .push_back(uvIndex[1]);
		    uvIndices    .push_back(uvIndex[2]);
		    normalIndices.push_back(normalIndex[0]);
		    normalIndices.push_back(normalIndex[1]);
		    normalIndices.push_back(normalIndex[2]);
		}
	}

	for( unsigned int i = 0; i < vertexIndices.size(); i++ )
	{
		unsigned int vertexIndex = vertexIndices[i];
		glm::vec3 vertex = temp_vertices[vertexIndex - 1];
		out_vertices.push_back(vertex);
		//
		// do normals
		//
		// do uvs
	}

	//glBufferData(GL_ARRAY_BUFFER, out_vertices.size() * sizeof(glm::vec3), &out_vertices[0], GL_STATIC_DRAW);

	return true;
}

vector<unsigned int> ObjectParser::getVertexIndices()
{
	return this->vertexIndices;
}

vector<unsigned int> ObjectParser::getUVIndices()
{
	return this->uvIndices;
}

vector<unsigned int> ObjectParser::getnormalIndices()
{
	return this->normalIndices;
}

vector<glm::vec3> ObjectParser::getTempVertices()
{
	return this->temp_vertices;
}

vector<glm::vec2> ObjectParser::getTempUVs()
{
	return this->temp_uvs;
}

vector<glm::vec3> ObjectParser::getTempNormals()
{
	return this->temp_normals;
}