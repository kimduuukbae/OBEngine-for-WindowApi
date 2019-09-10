#pragma once
#include <Windows.h>
#include <string_view>

class SceneManager;
class Input;
class Fps;
// WndProc 를 관리하고, WinMain에 종속적임

class World {
public:
	static inline World* instance() {
		static World instance_;
		return &instance_;
	}
	static LRESULT WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	bool worldInit(const std::string& titleName, int xSize, int ySize, HINSTANCE hInstance);
	
	void setFrame(float fFrame);
	void runLoop();
	void stopLoop();
	int GetExitState();
	HWND getWndHandle() { return hWnd; }
	HDC getBackbuffer() { return backbuffer; }
private:
	HWND hWnd;
	MSG Message;
	
	HBITMAP hBit;
	HDC hDC;
	HDC backbuffer;

	int m_exit_state;

	float deltaTime;
	HINSTANCE hInst;

	Fps* fps;
	SceneManager* render;	//그려주는 변수
	Input* input;			//마우스 or 키보드 입출력 처리 변수


	~World();
};

