#ifndef ARRAY_H
#define ARRAY_H

#include "Account.h"

#define NumOfUser 100

template <typename T>
class Array {
	T *accArr;
	int arrlen;

	Array(const Array &arr) {}
	Array& operator=(const Array &arr) {}

public:
	Array(int len = NumOfUser);

	T& operator[](int idx);

	T operator[](int idx) const;

	int GetArrLen() const;

	~Array();

};


#endif // !ARRAY_H
