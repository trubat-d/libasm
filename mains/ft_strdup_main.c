#include "libasm.h"


void *alt_malloc(size_t size) {
    (void)size;            
    errno = ENOMEM;        
    return NULL;           
}

int main(void) {
        const char content[9] = "changmee";

        errno = 0;
        char *new_string = ft_strdup(content);

        if (new_string != NULL) {
		printf("Value of string: %s -> pointer %p\n",new_string, new_string);
                free(new_string);
	} else {
		printf("Null pointer with value error %d\n", errno);
	}

        char *empty = ft_strdup("");


        if (empty != NULL) {
        	printf("Value of empty: %s, pointer -> %p\n", empty, empty);
                free(empty);
	} else {
		printf("Null pointer with value error %d\n", errno);
	}
	return 0;
}
