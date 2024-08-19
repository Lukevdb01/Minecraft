#include "window.h"
#include "util.h"

Window::Window(const char* title, int width, int height)
{
	std::wstring m_Title = Util::convertToWideString(title);
	WNDCLASSEX wc = { sizeof(WNDCLASSEX)};
	wc.lpfnWndProc = WinProc;
	wc.hInstance = GetModuleHandle(nullptr);
	wc.lpszClassName = L"WindowClassGame";
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	RegisterClassEx(&wc);

	m_hwnd = CreateWindow(wc.lpszClassName, m_Title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr, wc.hInstance, this);
	if (m_hwnd == nullptr)
	{
		MessageBox(nullptr, L"Failed to create window", L"Error", MB_OK | MB_ICONERROR);
		return;
	}

	m_hdc = GetDC(m_hwnd);
	m_pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1, PFD_DRAW_TO_WINDOW | LPD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA, 32 };
	SetPixelFormat(m_hdc, ChoosePixelFormat(m_hdc, &m_pfd), &m_pfd);

	m_hglrc = wglCreateContext(m_hdc);
	wglMakeCurrent(m_hdc, m_hglrc);

	ShowWindow(m_hwnd, SW_SHOW);
}

Window::~Window()
{

}

void Window::ProcessMessages()
{
	if (PeekMessage(&m_msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&m_msg);
		DispatchMessage(&m_msg);
	}
}

void Window::SwapWindowBuffers()
{
	SwapBuffers(m_hdc);
}


HWND Window::GetWindowHandle()
{
	return m_hwnd;
}

LRESULT Window::WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
