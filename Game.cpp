#include "Game.h"

void Game::Render()
{
	m_window.BeginDraw();
	m_hungryDot.Render(m_window.GetRenderWindow());
	m_window.EndDraw();
}

void Game::Update()
{
	m_window.Update();
}

Window* Game::GetWindow()
{
	return &m_window;
}