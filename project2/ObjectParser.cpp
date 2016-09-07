#include "ObjectParser.h"

using namespace std;

bool ObjectParser::parse(string file_path)
{
	FILE * file = fopen(file_path.c_str(), "r");

	if(file == NULL)
	{
		printf("File does exists \n");
		return false;
	}

	// DO PARSING HERE

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

vector<int> ObjectParser::getTempVertices()
{
	return this->temp_vertices;
}

vector<int> ObjectParser::getTempUVs()
{
	return this->temp_uvs;
}

vector<int> ObjectParser::getTempNormals()
{
	return this->temp_normals;
}