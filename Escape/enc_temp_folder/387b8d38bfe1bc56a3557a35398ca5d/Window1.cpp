#include "Window1.h"
#include <iostream>


enum class Gamestates { PLAYING, NOTPLAYING };


Window1::Window1() { //set all info

	_winInfo.title = "Game";
	_winInfo.posX = -1;
	_winInfo.posY = -1;
	_winInfo.width = 768;
	_winInfo.height = 576;
	_winInfo.flags = SDL_WINDOW_OPENGL;
	_winInfo.BGcolor = { 255, 255, 255, 1 };
	_winInfo.winAtt = SDL_GL_DOUBLEBUFFER;
	initAll(&_winInfo);
}


void Window1::runWindow() {

	Gamestates gamestate = Gamestates::PLAYING;
	SDL_Event windowInput;

	while (gamestate == Gamestates::PLAYING) {

		while (SDL_PollEvent(&windowInput) == true) {

			switch (windowInput.type) {
			case SDL_QUIT:
				gamestate = Gamestates::NOTPLAYING;
				break;

			case SDL_KEYDOWN:
				if (windowInput.key.keysym.scancode == SDL_SCANCODE_SPACE) {
					glClearColor(0, 0, 1, 1);
				}
				else {
					glClearColor(1, 0, 1, 1);
				}
				break;

			case SDL_KEYUP:
				glClearColor(1, 1, 1, 1);
				break;
			}
		}

		drawWindow();
	}
}


void Window1::drawWindow() {

	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (_vboID == 0) {
		glGenBuffers(1, &_vboID);
	}

	float vertexData[12] = { 0.2, 0.2, -1, 0.2, 0.2, 1, 1, 0.2, 0.2, 1, 1, 1 };


	glBindBuffer(GL_ARRAY_BUFFER, _vboID); //bind
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW); //upload

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); //unbind

	SDL_GL_SwapWindow(_window);
}


void Window1::destoryWindow() {

	glDeleteBuffers(1, &_vboID);
	SDL_DestroyWindow(_window);
}
