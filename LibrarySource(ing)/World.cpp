#include "stdafx.h"
#include "World.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Fps.h"
#include "Input.h"
#include "Camera.h"
 LRESULT World::WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	//case WM_GETMINMAXINFO:
	//	((MINMAXINFO*)lParam)->ptMaxTrackSize.x = instance()->getWindowX();
	//	((MINMAXINFO*)lParam)->ptMaxTrackSize.y = instance()->getWindowY();
	//	((MINMAXINFO*)lParam)->ptMinTrackSize.x = instance()->getWindowX();
	//	((MINMAXINFO*)lParam)->ptMinTrackSize.y = instance()->getWindowY();
	//	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

bool World::worldInit(const char* titleName, int xSize, int ySize, HINSTANCE hInstance) {
	WNDCLASSEX WndClass;
	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = (WNDPROC)WinProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = "Window Class Name";
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&WndClass);
	windowX = xSize;
	windowY = ySize;
	hWnd = CreateWindow(WndClass.lpszClassName, titleName, (WS_OVERLAPPEDWINDOW), 0, 0, xSize, ySize, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	deltaTime = 0;
	fps = new Fps();
	return 1;
}
void World::setFrame(float fFrame) {
	fps->setFrame(fFrame);
}
void World::runLoop() {

	hDC = GetDC(hWnd);
	hBit = CreateCompatibleBitmap(hDC, windowX*10, windowY*10);
	backbuffer = CreateCompatibleDC(hDC);
	ReleaseDC(hWnd, hDC);
	SelectObject(backbuffer, hBit);
	DeleteObject(hBit);
	render = SceneManager::instance();
	input = Input::instance();
	camera = Camera::instance();
	while (Message.message != WM_QUIT) {
		auto start = GetTickCount();
		if (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
			m_exit_state = Message.wParam;
			switch (Message.message) {
			case WM_LBUTTONDOWN:
				render->getCurrentScene()->mouseDownEvent(input->currentMousePos());
				break;
			case WM_MOUSEMOVE:
				render->getCurrentScene()->mouseMoveEvent(input->currentMousePos());
				break;
			}
		}
		hDC = GetDC(hWnd);

		render->update(deltaTime);
		render->draw(backbuffer);	// 현재씬을 그립니다.

		deltaTime = fps->update();
		fps->draw(backbuffer);	// FPS를 그립니다.
		BitBlt(hDC, 0, 0, windowX, windowY, backbuffer, 
			camera->currentCameraX(), camera->currentCameraY(), SRCCOPY);
		ReleaseDC(hWnd, hDC);
	}
}

void World::stopLoop() {
	SendMessage(hWnd, WM_CLOSE, 0, 0);
}

World::~World() {
	ReleaseDC(hWnd, backbuffer);
	if (fps != nullptr)
		delete fps;
	Message.message = WM_QUIT;
	DestroyWindow(hWnd);
}
int World::GetExitState() { return m_exit_state; }

World* instance_{ nullptr };
World* World::instance() {
	if (instance_ == nullptr) instance_ = new World();
	return instance_;
}