#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <GL/glut.h>


using namespace std;

class ObjectParser
{
	private:

		vector<unsigned int> vertexIndices;
		vector<unsigned int> uvIndices;
		vector<unsigned int> normalIndices;

		vector<int> temp_vertices;
		vector<int> temp_uvs;
		vector<int> temp_normals;

	public:

		ObjectParser(){}

		~ObjectParser(){}

		bool parse(string file_path);

		vector<unsigned int> getVertexIndices();

		vector<unsigned int> getUVIndices();

		vector<unsigned int> getnormalIndices();

		vector<int> getTempVertices();

		vector<int> getTempUVs();

		vector<int> getTempNormals();
};