
#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
	char *s1 = "aaa";
	char *s2 = "aa";
	size_t max = strlen(s2);
	char *i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);
	printf("%s\n", i1);
	printf("%s\n", i2);
}
