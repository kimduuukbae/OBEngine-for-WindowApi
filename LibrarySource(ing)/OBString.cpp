#include "stdafx.h"
#include "OBString.h"
const char* OBString::getString() {
	return str.c_str();
}

void OBString::setString(const char* strings){
	str = strings;
}
OBString& OBString::operator=(const char* s)
{
	str = s;
	return *this;
}
bool OBString::operator==(const char* s) {
	std::string tmp(s);
	return str == tmp;
}

bool OBString::operator==(const OBString& rhs){
	return str == rhs.str;
}

size_t OBString::getSize() {
	return str.size();
}
OBString makeString(float value) {
	return std::to_string(value).c_str();
}
OBString makeString(int value) {
	return std::to_string(value).c_str();
}