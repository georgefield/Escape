#include "GenericWindow.h"
#include <conio.h>


void GenericWindow::initAll(windowInfo* _winInfo) {


	//check _winInfo was initialized in child class
	if (_winInfo->title == "\0") {
		showError(true, "_winInfo has not been initialized");
	}

	SDL_Init(SDL_INIT_EVERYTHING); //init SDL

	//create window and validate it
	_window = SDL_CreateWindow(_winInfo->title.c_str(), (_winInfo->posX < 0 ? SDL_WINDOWPOS_CENTERED : _winInfo->posX), (_winInfo->posY < 0 ? SDL_WINDOWPOS_CENTERED : _winInfo->posY), _winInfo->width, _winInfo->height, _winInfo->flags);
	if (_window == nullptr) {
		showError(true, "_window was not initialized or initialization failed");
	}

	//create glContext and validate it
	_glContext = SDL_GL_CreateContext(_window);
	if (_glContext == nullptr) {
		showError(true, "_glContext was not initialized or initialization failed");
	}

	//initialize glew and 
	GLenum checkError = glewInit();
	if (checkError != GLEW_OK) {
		showError(true, "glewInit() failed or returned an unexpected value");
	}

	//set attributes and clear color
	SDL_GL_SetAttribute(_winInfo->winAtt, 1);
	glClearColor(_winInfo->BGcolor[0] / 255.0, _winInfo->BGcolor[1] / 255.0, _winInfo->BGcolor[2] / 255.0, _winInfo->BGcolor[3]);
}


void GenericWindow::showError(bool fatal, std::string message) {

	printf("%s - %s", (fatal == true ? "FATAL" : "NONFATAL" ), message.c_str());
	_getch();

	if (fatal == true) {
		SDL_Quit();
		exit(1);
	}
}
