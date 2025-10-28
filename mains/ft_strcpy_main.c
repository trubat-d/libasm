#include "libasm.h"

int main(void) {
	char* content = "changeme";
	char* final = malloc(sizeof(char)*20);

	for(int i = 0; i < 19;i++){
		final[i] = 'A';
	}
	final[19] = 0;

	printf("%s\n", final);

	printf("%s\n", ft_strcpy(final, content));

	printf("%s\n", final);

	free(final);
	return 0;
}
