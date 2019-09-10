#pragma once
#include "OBString.h"
class Event {
public:
	Event(const char*);
	~Event() = default;
	OBString getEvent();
	void	setEvent(const char*);
	/*
		@Breif : 실제로 이벤트가 호출됐을 때 행동하는 함수입니다.
		@args : None
		@return : None
	*/
	virtual void response() = 0;
private:
	//OBString str;
};