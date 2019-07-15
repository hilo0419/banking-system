#include "String.h"

//�⺻������
String::String() :str(NULL), len(0)
{}

String::String(const char *s)
{

	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String &s) {

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String& String::operator=(const String &s) {

	if (str != NULL)
		delete[]str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String String::operator+(const String &s) {

	char * tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);
	String temp(tempstr);
	delete[]tempstr;

	return temp;
}

//"+="������ �����ε�
String& String::operator+=(const String &s)
{

	*this = (*this + s);
	return *this;
}

//"=="������ �����ε�
bool String::operator==(const String &s)
{

	if (strcmp(str, s.str) == 0)
		return true;

}

char* String::getStr() const {

	return str;
}

int String::getLen() const {

	return len;
}

//�Ҹ���
String::~String()
{

	if (str != NULL)
		delete[]str;
}


//"<<"������ �����ε�
ostream& operator<<(ostream& os, const String &s)
{
	os << s.str;
	return os;
}

//">>"������ �����ε�
istream& operator>>(istream& is, String &s)
{

	char temp[50];
	is >> temp;
	s = String(temp);
	return is;
}
