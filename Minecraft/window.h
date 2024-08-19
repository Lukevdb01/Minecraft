#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include <Windows.h>

class Window
{
public:
	Window(const char* title, int width, int height);
	~Window();

	void ProcessMessages();
	void SwapWindowBuffers();
	HWND GetWindowHandle();
	bool isRunning() { return m_msg.message != WM_QUIT; }
private:
	HWND m_hwnd;
	static LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HDC m_hdc;
	HGLRC m_hglrc;
	PIXELFORMATDESCRIPTOR m_pfd;
	MSG m_msg;
};

#endif // !WINDOW_CLASS_H
