#include "Define.h"
#include "sceneLogo.h"
void SceneLogo::init()
{
	startButton.setTexture("data/Logo/startButton.bmp");
	startButton.setPos(456, 300);
	startButton.setShow(true);

	exitButton.setTexture("data/Logo/exitButton.bmp");
	exitButton.setPos(456, 400);
	exitButton.setShow(true);

	m_sprite.setTexture("data/Logo/Title.bmp");
	m_sprite.setSize(1.0f, 1.0f);
	m_sprite.setBlend(0.2f);
	m_sprite.setPos(256, 128);

	backGround.setTexture("data/Logo/background.bmp");
	backGround.setSize(1.0f, 1.0f);
	backGround.setBlend(1.0f);
	backGround.setPos(0, 0);
}

void SceneLogo::update(float dt)
{
	
}

void SceneLogo::draw(HDC hDC)
{
	backGround.draw(hDC);
	Rectangle(hDC, 0, 56, 1024, 578);
	m_sprite.draw(hDC);
	startButton.draw(hDC);
	exitButton.draw(hDC);
}

void SceneLogo::destroy()
{

}

void SceneLogo::mouseDownEvent(const Vector2D & mousePos){
	if (startButton.collision((int)mousePos.getX(), (int)mousePos.getY()))
		D_SCENE->changeSceneFade("Game");
	else if (exitButton.collision((int)mousePos.getX(), (int)mousePos.getY()))
		D_WORLD->stopLoop();
}
