#include "Game.h"

void Game::Render()
{
	m_window.BeginDraw();
	m_window.Draw(m_hungryDotSprite);
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