#pragma once
#include <string>

class OBString {
public:
	OBString(const char* strings) : str{ strings } {}
	OBString& operator=(const OBString& rhs) = default;
	const char* getString();
	void setString(const char*);
private:
	std::string str;
};