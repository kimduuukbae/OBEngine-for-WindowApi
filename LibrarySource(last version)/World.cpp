#include "World.h"
#include "SceneManager.h"
#include "Input.h"
#include "Fps.h"

LRESULT World::WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

bool World::worldInit(const std::string& titleName, int xSize, int ySize, HINSTANCE hInstance) {
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
	hInst = hInstance;
	RegisterClassEx(&WndClass);

	hWnd = CreateWindow(WndClass.lpszClassName, titleName.c_str(), (WS_OVERLAPPEDWINDOW), 0, 0, xSize, ySize, NULL, (HMENU)NULL, hInstance, NULL);

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
	render = SceneManager::instance();
	input = Input::instance();

	//Create
	hDC = GetDC(hWnd);
	hBit = CreateCompatibleBitmap(hDC, 1024, 768);
	backbuffer = CreateCompatibleDC(hDC);
	ReleaseDC(hWnd, hDC);
	SelectObject(backbuffer, hBit);
	DeleteObject(hBit);

	while (Message.message != WM_QUIT) {
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

		render->draw(backbuffer); // 현재 씬을 그리는 부분 Base : SceneManager
		render->update(deltaTime);
		deltaTime = fps->update();

		fps->draw(backbuffer);
		BitBlt(hDC, 0, 0, 1024, 768, backbuffer, 0, 0, SRCCOPY);

		ReleaseDC(hWnd, hDC);
	}
}

void World::stopLoop(){
	World::~World();
}

World::~World() {
	render->getCurrentScene()->destroy();
	ReleaseDC(hWnd, backbuffer);
	delete fps;
	DestroyWindow(hWnd);
}
int World::GetExitState() { return m_exit_state; }