#include "main.h"
/**
  *customstrcmp- custom function to handle strcmp
  *@s2: string one
  *@s1:string two
  *return:string
  */
int customstrcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
	    s1++;
	s2++;
	}
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
