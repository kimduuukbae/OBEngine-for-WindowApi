#include "stdafx.h"
#include "EventDispatcher.h"

void EventDispatcher::addEvent(Event & e){
	e.setEvent("");
	queue.push_back(&e);
}
void EventDispatcher::addEvent(OBString& s, Event& e) {
	queue.push_back(&e);
}

void EventDispatcher::popEvent(Event& e) {
	popEvent(e.getEvent());
}

void EventDispatcher::popEvent(const OBString& s){
	auto it = queue.begin();
	for (int i = 0; i < queue.size(); ++i) {
		if (queue[i]->getEvent() == s) {
			it = it + i;
			break;
		}
	}
	if (it != queue.end())
		queue.erase(it);
}

void EventDispatcher::call(const OBString& s) {
	for (auto& i : queue) {
		if (i->getEvent() == s)
			i->response();
	}
}
void EventDispatcher::callOnce(const OBString& s) {
	for (auto& i : queue) {
		if (i->getEvent() == s) {
			i->response();
			break;
		}
	}
}

void EventDispatcher::release() {
	queue.clear();
}
