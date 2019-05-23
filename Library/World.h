#pragma once


class SceneManager;
class Fps;
class Input;

class World {
public:
	static World* instance();
	static LRESULT WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	bool worldInit(const char* titleName, int xSize, int ySize, HINSTANCE hInstance);
	void setFrame(float fFrame);
	void runLoop();
	void stopLoop();
	int GetExitState();
	HWND getWndHandle() { return hWnd; }
	HDC getBackbuffer() { return backbuffer; }

	int getWindowX() { return windowX; }
	int getWindowY() { return windowY; }
private:
	HWND hWnd;
	MSG Message;

	HBITMAP hBit;
	HDC hDC;
	HDC backbuffer;

	SceneManager* render;
	Input*	input;

	Fps* fps;	// FPS ��¿� ���˴ϴ�.
	int m_exit_state;	// ���� message

	float deltaTime; //�����Ӱ� �ð�

	int windowX, windowY;

	~World();
};


