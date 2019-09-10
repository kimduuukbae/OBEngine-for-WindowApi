#pragma once
#include <string>

class OBString {
public:
	OBString(const char* strings) : str{ strings } {}

	OBString& operator=(const OBString& rhs) = default;
	OBString& operator=(const char* s);
	bool operator==(const char* s);
	bool operator==(const OBString& rhs);

	const char* getString();
	void setString(const char*);
	size_t getSize();
private:
	std::string str;
};
OBString makeString(float value);
OBString makeString(int value);