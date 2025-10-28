#include "libasm.h"


int main(void) {
	const char content[9] = "changmee";
	ssize_t ret = 0;

	errno = 0;
	int fd = open("classic_write.txt", O_WRONLY | O_CREAT, S_IRWXU);
	ret = write(fd, content, strlen(content));
	printf("Writes value %s in classic_write with default write and returns: %ld -> errno = %d\n", content, ret, errno);
	close(fd);

	errno = 0;
	fd = open("ft_write.txt", O_WRONLY | O_CREAT, S_IRWXU);
	ret = ft_write(fd, content, strlen(content));
	printf("Writes value %s in ft_write.txt and returns: %ld -> errno = %d\n",content, ret, errno);
	close(fd);

	errno = 0;
	fd = open("ft_write_half.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	ret = ft_write(fd, content, strlen(content)/2);
	printf("Prints half of the value %s and returns: %ld -> errno = %d\n", content, ret, errno);
	close(fd);

	errno = 0;
	fd = open("write_error.txt", O_RDONLY | O_CREAT, S_IRWXU);
	ret = write(fd, content, strlen(content));
	printf("Return of write with perm error: %ld -> errno = %d\n", ret, errno);
	close(fd);

	errno = 0;
	fd = open("ft_write_error.txt", O_RDONLY | O_CREAT, S_IRWXU);
	ret = ft_write(fd, content, strlen(content));
	printf("Return of ft_write with perm error: %ld -> errno = %d\n", ret, errno);
	close(fd);


	return 0;
}
