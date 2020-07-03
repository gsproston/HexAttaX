#include "HexGrid.h"
#include "Window.h"


int main()
{
	Window::Init();
	HexGrid::Init();

	while (Window::window.isOpen())
	{
		Window::PollEvent();
		HexGrid::Draw();
		Window::Display();
	}

	return 0;
}