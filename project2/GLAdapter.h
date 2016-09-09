#include "IGLAdapter.h"

using namespace std;

class GLAdapter : public IGLAdapter
{
	private:

	public:

		GLAdapter(int argc, char **argv, GraphicObject* _obj);
		
		~GLAdapter(){}

		void setupWindow(int _window_width, int _window_height,
						 int _window_origin_x, int _window_origin_y, string _message);
		void init();

		void draw();

		void loop();
};