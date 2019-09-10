#include "stdafx.h"
#include "SoundManager.h"
#include "inc/fmod.hpp"

SoundManager* instance_{ nullptr };
SoundManager * SoundManager::instance(){
	if (instance_ == nullptr)
		instance_ = new SoundManager();
	return instance_;
}

void SoundManager::init(int channelCount) {
	FMOD::System_Create(&pfmod);
	pfmod->init(channelCount, FMOD_INIT_NORMAL, NULL);
	ch = new FMOD::Channel*[channelCount];
	sound = new FMOD::Sound*[channelCount];
}

void SoundManager::commit(const char* sv, int loopType) {
	pfmod->createSound(sv, loopType, NULL, &sound[tracknum++]);
}

void SoundManager::playSound(int track) {
	pfmod->playSound(sound[track], 0, false, &ch[track]);
}

void SoundManager::stopSound(int track) {
	ch[track]->stop();
}

void SoundManager::setPause(bool bFlag, int track) {
	ch[track]->setPaused(bFlag);
}

void SoundManager::setVolume(float f, int track) {
	ch[track]->setVolume(f);
}

bool SoundManager::isPlaying(int track)
{
	bool bPlaying;
	ch[track]->isPlaying(&bPlaying);
	return bPlaying;
}

SoundManager::SoundManager() {

}
SoundManager::~SoundManager() {
	delete[] ch;
	delete[] sound;

	pfmod->release();
	pfmod->close();
}