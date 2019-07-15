#include "Array.h"
#include "Account.h"
#include "MiniBankingCommonDecl.h"

template <typename T>
Array<T>::Array(int len) {
	accArr = new T[len];
	arrlen = len;
}

template <typename T>
T& Array<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "배열의 범위를벗어났습니다." << endl;
		exit(1);
	}

	return accArr[idx];
}

template <typename T>
T Array<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "배열의 범위를벗어났습니다." << endl;
		exit(1);
	}

	return accArr[idx];
}

template <typename T>
int Array<T>::GetArrLen() const
{
	return arrlen;
}

template <typename T>
Array<T>::~Array()
{
	delete[]accArr;
}
