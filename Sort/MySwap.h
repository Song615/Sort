//#pragma once
#ifndef MYSWAP_H
#define MYSWAP_H

template<typename T>
void MySwap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

#endif // !MYSWAP_H
