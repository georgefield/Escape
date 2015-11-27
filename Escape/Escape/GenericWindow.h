#pragma once
#include <SDL - 2.0.3\SDL.h>
#include <GLEW - 1.13.0\glew.h>
#include <string>
#include <array>


typedef std::array<GLclampf, 4> RGBA; //Red Green Blue Alpha

struct structWindowInfo { 
							std::string title;
							Sint16 posX;
							Sint16 posY;
							Uint16 width;
							Uint16 height;
							Uint32 flags;

							RGBA BGcolor = { 255, 255, 255, 1 };
							SDL_GLattr winAtt;
};
typedef structWindowInfo windowInfo;
/*title, posX, posY, width, height, flags, <- for create window | other settings -> BGcolor, window attributes*/


class GenericWindow
{
protected:
	void initAll(windowInfo* _winInfo);
	void showError(bool fatal, std::string message = "An unknown error occured");

	SDL_Window* _window = nullptr;
	windowInfo _winInfo;

	SDL_GLContext _glContext;
};

