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
		@Breif : ���� instance �� �ʱ�ȭ �մϴ�.
	*/
	static SoundManager* instance();
	/*
		@Brief : ���� instance �� �ʱ�ȭ��ŵ�ϴ�.
		@args : channelCount = ä���� ���� ( ���� �翡 �°� )
	*/
	void init(int channelCount);

	/*
		@Brief : ���带 Ŀ���մϴ�.
		@args : std::string_view : sound ���� ��ġ, loopType : ���� ���
		@loopType, 0: �ѹ��� ���,  2: �ݺ�
	*/
	void commit(const char* sv, int loopType);

	/*
		@Breif : Ŀ���� ���带 �÷��̽�ŵ�ϴ�.
		@args : track : Ŀ�Լ������ �����ų ����
	*/
	void playSound(int track);

	void stopSound(int track);
	void setPause(bool bFlag, int track);
	/*
		@Breif : �����ص� �˰Ŷ� ����, 0.0 ~ 1.0f
	*/
	void setVolume(float f, int track);
	/*
		@Breif : ���� track �� Sound�� �÷��� ���̶�� true �ƴϸ� false
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