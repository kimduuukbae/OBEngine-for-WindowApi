#pragma once
#include "Event.h"
#include "OBString.h"
#include <vector>
template class __declspec(dllexport) std::vector<Event*>;

class  EventDispatcher {
public:
	EventDispatcher() = default;
	~EventDispatcher() = default;

	/*
		@breif : 이름에 맞는 이벤트를 추가합니다.
		이벤트의 이름을 추가하지 않을 시 이름이 적히지 않은 모든 이벤트에 호출됩니다.
		@args : 이벤트가 포함된 객체, 이벤트의 이름
	*/
	void addEvent(Event& e);
	void addEvent(OBString& s, Event& e);

	/*
		@breif : 이름에 맞는 이벤트를 삭제합니다.
		이벤트의 이름을 추가하지 않을 시 이름이 적히지 않은 모든 이벤트가 삭제됩니다.
		@args : 이벤트가 포함된 객체, 이벤트의 이름
	*/
	void popEvent(Event& e);
	void popEvent(const OBString& s);
	
	/*
		@brief : 이름에 해당하는 이벤트를 호출합니다.
	*/
	void call(const OBString& s);
	void callOnce(const OBString& s);
	/*
		@breif : 이벤트 큐를 초기화합니다. (비웁니다.)
	*/
	void release();
private:
	std::vector<Event*> queue;
};