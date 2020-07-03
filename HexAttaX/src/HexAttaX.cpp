#include "HexGrid.h"
#include "Window.h"


int main()
{
	Window::Init();
	HexGrid::Init();

	while (Window::window.isOpen())
	{
		Window::PollEvent();

		Window::window.clear();
		HexGrid::Draw();
		Window::window.display();
	}

	return 0;
}