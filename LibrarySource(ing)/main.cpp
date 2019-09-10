#include "Define.h"
// ��� ������Ʈ�� ���� camel Case �� �ۼ���, �׷��� Class (Base ����) �� Pascal Case �� �ۼ���.
// Scene�� commit �ϰ�, changeScene�� ������ ������, ptr syntax error �� ��
enum E_SOUND {
	E_LOGO,
	E_READY,
	E_GO,
	E_SHOOT
}mySound;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR ,  int )
{
	mySound = E_LOGO;
	D_WORLD->worldInit("Sample World", 1024, 768, hInstance);
	D_WORLD->setFrame(60.0f);

	// Sound Sample
	// ���带 �� 4�� ���� �����̴�, ä���� 4��
	D_SOUND->init(4);	// <- ä�� ����

	D_SOUND->commit("data/Sound/Logo.mp3",2);
	D_SOUND->commit("data/Sound/Ready.mp3", 0);
	D_SOUND->commit("data/Sound/Go.mp3", 0);
	D_SOUND->commit("data/Sound/shoot.mp3", 0);

	// LOGO ���带 �÷��̽�Ű��, ������ �����մϴ�.
	D_SOUND->playSound(E_LOGO);
	D_SOUND->setVolume(0.15f,E_LOGO);
	// LOGO ���带 ��� ���߰�, �ٽ� �����ŵ�ϴ�.

	D_SOUND->setPause(false, E_LOGO);
	D_SOUND->setPause(true, E_LOGO);

	D_WORLD->runLoop();

	return D_WORLD->GetExitState();
}
