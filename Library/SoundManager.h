#pragma once
#pragma comment(lib, "inc/fmod_vc.lib")

namespace FMOD {
	class System;
	class Channel;
	class Sound;
}
class SoundManager {
public:
	/*
		@Breif : 사운드 instance 를 초기화 합니다.
	*/
	static SoundManager* instance();
	/*
		@Brief : 사운드 instance 를 초기화시킵니다.
		@args : channelCount = 채널의 갯수 ( 사운드 양에 맞게 )
	*/
	void init(int channelCount);

	/*
		@Brief : 사운드를 커밋합니다.
		@args : std::string_view : sound 파일 위치, loopType : 루프 방법
		@loopType, 0: 한번만 재생,  2: 반복
	*/
	void commit(const char* sv, int loopType);

	/*
		@Breif : 커밋한 사운드를 플레이시킵니다.
		@args : track : 커밋순서대로 실행시킬 사운드
	*/
	void playSound(int track);

	void stopSound(int track);
	void setPause(bool bFlag, int track);
	/*
		@Breif : 말안해도 알거라 믿음, 0.0 ~ 1.0f
	*/
	void setVolume(float f, int track);
	/*
		@Breif : 현재 track 의 Sound가 플레이 중이라면 true 아니면 false
	*/
	bool isPlaying(int track);
private:
	SoundManager();
	~SoundManager();

	FMOD::System* pfmod;
	FMOD::Channel** ch;
	FMOD::Sound** sound;
	int tracknum{ 0 };
};