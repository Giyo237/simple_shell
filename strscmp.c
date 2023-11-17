#include "main.h"
/**
  * customestrspn - function to handle strcpn
  *@s:string
  *@accept: val
  *Return:count
  */
size_t customstrspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	size_t count = 0;

	for (p = s; *p; p++)
	{
		for (a = accept; *a; a++)
	{
		if (*p == *a)
		{
			break;
		}
	}
	if (!*a)
	{
		return count;
	}
	count++;
    }

    return count;
}
