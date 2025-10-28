#include "libasm.h"


int main(int ac, char** av) {
	if (ac != 2) {
		printf("Usage: ./prog read_filename.txt");
		return 1;
	}
	ssize_t ret = 0;
	char *buffer = malloc(129);
	char *filename = ac > 0 ? av[1] : "read.txt";

	errno = 0;
	int fd = open(filename, O_RDONLY);
	ret = read(fd, buffer, 128);
	if(ret >= 0)
		buffer[ret] = 0;
	printf("Reads value %s in file with default read and returns: %ld -> errno = %d\n", buffer , ret, errno);
	close(fd);
	bzero(buffer, 129);

	errno = 0;
	fd = open(filename, O_RDONLY);
	ret = ft_read(fd, buffer, 128);
	if(ret >= 0)
		buffer[ret] = 0;
	printf("Reads value %s in file and returns: %ld -> errno = %d\n",buffer, ret, errno);
	close(fd);
	bzero(buffer, 129);

	errno = 0;
	fd = open(filename, O_RDONLY);
	ret = ft_read(fd, buffer, 8);
	if (ret >= 0)
		buffer[ret] = 0;
	printf("Reads 8 chars : '%s', of the file and returns: %ld -> errno = %d\n", buffer, ret, errno);
	close(fd);
	bzero(buffer, 129);

	errno = 0;
	fd = open(filename, O_WRONLY);
	ret = read(fd, buffer, 128);
	if (ret >= 0)
		buffer[ret] = 0;
	printf("Return of read with perm error (file opened in wronly): %ld -> errno = %d\n", ret, errno);
	close(fd);
	bzero(buffer,129);

	errno = 0;
	fd = open(filename, O_WRONLY);
	ret = ft_read(fd, buffer, 128);
	if (ret >= 0)
		buffer[ret] = 0;
	printf("Return of ft_read with perm error (file opened in wronly): %ld -> errno = %d\n", ret, errno);
	close(fd);
	bzero(buffer,129);

	free(buffer);
	return 0;
}
