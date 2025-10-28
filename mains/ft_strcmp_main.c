#include "libasm.h"

int main(void) {
	char* s1 = "b";
	char* s2 = "a";

	printf("Real : %d\n", strcmp(s1, s2));
	printf("Custom : %d\n", ft_strcmp(s1,s2));

	return 0;
}
