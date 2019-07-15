#ifndef STRING_H
#define STRING_H

#include "MiniBankingCommonDecl.h"


class String
{
private:
	int len; //문자열 길이 맴버 변수
	char *str; //문자열 배열 주소
public:
	String();
	String(const char *s);
	String(const String &s);
	String & operator=(const String &s);
	String operator+(const String &s);
	String&operator+=(const String &s);
	bool operator==(const String &s);
	char * getStr() const;
	int getLen() const;
	~String();
	friend ostream& operator<<(ostream& os, const String &s);
	friend istream& operator>>(istream& is, String &s);

};
#endif // !STRING_H

