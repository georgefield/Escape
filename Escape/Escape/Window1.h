#pragma once
#include "GenericWindow.h"

class Window1 : public GenericWindow
{
public:
	Window1();
	void runWindow();
	void drawWindow();

	void destoryWindow();

private:
	GLuint _vboID = 0;
};

