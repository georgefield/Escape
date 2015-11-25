#include <conio.h>
#include <iostream>
#include <SDL - 2.0.3\SDL.h>
#include <GLEW - 1.13.0\glew.h>


typedef double RGBA[4];

void quitGame();
void initGlew(SDL_Window* window, const RGBA BGcol);


int main(int argc, char** argv) {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* mainWindow = nullptr;
	mainWindow = SDL_CreateWindow("Test window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_OPENGL);

	if (mainWindow == nullptr) {
		quitGame();
	}

	enum GAMESTATES { PLAYING, NOTPLAYING };
	GAMESTATES gamestate = PLAYING;

	SDL_Event SDLevnt;

	const RGBA bgRGB = { 0.0, 0.0, 1.0, 1.0 };
	initGlew(mainWindow, bgRGB);

	bool prevMOWval = false;
	bool mouseOnWindow = false;

	int it = 0;

	while (gamestate == PLAYING) {
		while (SDL_PollEvent(&SDLevnt) == true) {

			switch (SDLevnt.type) {
			case SDL_QUIT:
				gamestate = NOTPLAYING;

			default:
				if (SDL_GetMouseFocus() == mainWindow) {
					mouseOnWindow = true;
				}
				else {
					mouseOnWindow = false;
				}
			}

			if (mouseOnWindow != prevMOWval) {
				system("cls");
				std::cout << "Mouse on window: " << std::boolalpha << mouseOnWindow << std::endl;
				prevMOWval = mouseOnWindow;
			}
		}

		glClearDepth(1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnableClientState(GL_COLOR_ARRAY);
		//draw stuff vvv
		glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0, 0);
		glVertex2f(200, 0);
		glVertex2f(200, 200);

		glEnd();
		//draw stuff ^^^

		SDL_GL_SwapWindow(mainWindow); //swap buffer

		it+=1;
	}

	quitGame();
	return 0;
}


void quitGame() {

	SDL_Quit();
	printf("Press any key to exit...");
	getch();
	exit(1);
}


void initGlew(SDL_Window* window, const RGBA BGcol) {

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	if (glContext == nullptr) {
		quitGame();
	}

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		quitGame();
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1.0);
	glClearColor(BGcol[0], BGcol[1], BGcol[2], BGcol[3]);
}