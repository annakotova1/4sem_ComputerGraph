#include "../inc/my_functions.h"

bool string_to_int(char *str, qreal ans)
{
	int num = 0;
	int point_pos = 0;
	int cur_pos = 0;
	while (*str != 0)
	{
		switch (*str)
		{
			case '1':
				num = num * 10 + 1;
				break;
			case '2':
				num = num * 10 + 2;
				break;
			case '3':
				num = num * 10 + 3;
				break;
			case '4':
				num = num * 10 + 4;
				break;
			case '5':
				num = num * 10 + 5;
				break;
			case '6':
				num = num * 10 + 6;
				break;
			case '7':
				num = num * 10 + 7;
				break;
			case '8':
				num = num * 10 + 8;
				break;
			case '9':
				num = num * 10 + 9;
				break;
			case '0':
				num = num * 10 + 0;
				break;
			case '.':
				point_pos = cur_pos;
				break;
			default:
				return false;
		}
		cur_pos++;
		str++;
	}
	ans = (qreal)num / pow(10, cur_pos-point_pos);
	return true;
}
/*
qreal getMax3(qreal a1, qreal a2, qreal a3)
{
	if (a1 >= a2) && (a1 >= a3)
	{
		return a1;
	}
	else if (a2 >= a1) && (a2 >= a3)
	{
		return a2;
	}
	return a3;
}

qreal getMin3(qreal a1, qreal a2, qreal a3)
{
	if (a1 < a2) && (a1 < a3)
	{
		return a1;
	}
	else if (a2 < a1) && (a2 < a3)
	{
		return a2;
	}
	return a3;
}

qreal getMin2(qreal a1, qreal a2)
{
	if (a1 < a2)
	{
		return a1;
	}
	return a2;
}*/