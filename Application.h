#pragma once

#include "Vector2.h"
#include "Bezier.h"

class Application
{
public:
	Application();

	bool run();

private:
	bool initSDL();
	void shutdownSDL();
	SDL_Texture *loadTexture(const std::string& filename);

	void processEvent(const SDL_Event &e);
	void render();

	const int c_windowWidth = 800;
	const int c_windowHeight = 600;

	SDL_Window *m_window = nullptr;
	SDL_Renderer *m_renderer = nullptr;

	bool m_quit = false;

	SDL_Texture *m_carSprite = nullptr;

	std::vector<Bezier> m_track;
};

