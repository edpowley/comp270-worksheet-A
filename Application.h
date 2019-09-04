#pragma once

#include "resource.h"

class Application
{
public:
	bool run();

private:
	bool initSDL();
	void shutdownSDL();

	void processEvent(const SDL_Event &e);
	void render();

	const int c_windowWidth = 800;
	const int c_windowHeight = 600;

	SDL_Window *m_window = nullptr;
	SDL_Renderer *m_renderer = nullptr;

	bool m_quit = false;
};

