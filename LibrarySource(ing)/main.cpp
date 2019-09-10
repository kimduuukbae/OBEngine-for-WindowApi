#include "Define.h"
// 모든 오브젝트와 씬은 camel Case 로 작성함, 그러나 Class (Base 포함) 는 Pascal Case 로 작성함.
// Scene을 commit 하고, changeScene을 해주지 않으면, ptr syntax error 가 남
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
	// 사운드를 총 4개 넣을 예정이니, 채널은 4개
	D_SOUND->init(4);	// <- 채널 갯수

	D_SOUND->commit("data/Sound/Logo.mp3",2);
	D_SOUND->commit("data/Sound/Ready.mp3", 0);
	D_SOUND->commit("data/Sound/Go.mp3", 0);
	D_SOUND->commit("data/Sound/shoot.mp3", 0);

	// LOGO 사운드를 플레이시키고, 볼륨을 변경합니다.
	D_SOUND->playSound(E_LOGO);
	D_SOUND->setVolume(0.15f,E_LOGO);
	// LOGO 사운드를 잠시 멈추고, 다시 실행시킵니다.

	D_SOUND->setPause(false, E_LOGO);
	D_SOUND->setPause(true, E_LOGO);

	D_WORLD->runLoop();

	return D_WORLD->GetExitState();
}
