#define _CRT_SECURE_NO_WARNINGS 1
#include "swap.h"

//∂®“Â
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}