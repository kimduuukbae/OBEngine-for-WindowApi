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
		@breif : �̸��� �´� �̺�Ʈ�� �߰��մϴ�.
		�̺�Ʈ�� �̸��� �߰����� ���� �� �̸��� ������ ���� ��� �̺�Ʈ�� ȣ��˴ϴ�.
		@args : �̺�Ʈ�� ���Ե� ��ü, �̺�Ʈ�� �̸�
	*/
	void addEvent(Event& e);
	void addEvent(OBString& s, Event& e);

	/*
		@breif : �̸��� �´� �̺�Ʈ�� �����մϴ�.
		�̺�Ʈ�� �̸��� �߰����� ���� �� �̸��� ������ ���� ��� �̺�Ʈ�� �����˴ϴ�.
		@args : �̺�Ʈ�� ���Ե� ��ü, �̺�Ʈ�� �̸�
	*/
	void popEvent(Event& e);
	void popEvent(const OBString& s);
	
	/*
		@brief : �̸��� �ش��ϴ� �̺�Ʈ�� ȣ���մϴ�.
	*/
	void call(const OBString& s);
	void callOnce(const OBString& s);
	/*
		@breif : �̺�Ʈ ť�� �ʱ�ȭ�մϴ�. (���ϴ�.)
	*/
	void release();
private:
	std::vector<Event*> queue;
};