#pragma once

class World {
public:
	static inline World* instance() {
		static World instance_;
		return &instance_;
	}
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

	int m_exit_state;

	float deltaTime; // time per frame

	int windowX, windowY;

	~World();
};


