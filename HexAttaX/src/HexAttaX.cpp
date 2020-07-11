#include "HexGrid.h"
#include "PlayerManager.h"
#include "Window.h"


int main()
{
	Window::Init();
	HexGrid::Init();

	while (Window::window.isOpen())
	{
		Window::PollEvent();

		HexGrid::Draw();
		PlayerManager::Draw();

		Window::Display();
	}

	return 0;
}