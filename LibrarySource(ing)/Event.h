#pragma once
#include "OBString.h"
class Event {
public:
	Event(const char*);
	~Event() = default;
	OBString getEvent();
	void	setEvent(const char*);
	/*
		@Breif : ������ �̺�Ʈ�� ȣ����� �� �ൿ�ϴ� �Լ��Դϴ�.
		@args : None
		@return : None
	*/
	virtual void response() = 0;
private:
	//OBString str;
};