#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int _atoi(char* str){
	int sign = 1;
	int data = 0;

	if (*str == '\n') return 0;
	
	while(*str){
		if (*str >= "0" && *str <= "9") {
			data = data * 10 + *str - '0';
		}
		str++;
	}

	return data * sign;
}

int main(int argc, char* argv[]) {
	int rfd, wfd, n;
	char buf[10];
	int chunkSize = _atoi(argv[3]);
	clock_t start, end;
	float load_time;
	char *path[1000];
	realpath(argv[1], path);


	rfd = open(argv[1], O_RDONLY);
	if (rfd == -1){
		perror(argv[1]);
		exit(1);
	}

	wfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (wfd == -1) {
		perror(argv[2]);
		exit(2);
	}
	start = clock();
	while((n = read(rfd, buf, chunkSize)) > 0)
	       if (write(wfd, buf, n) != n) perror("Write");
	end = clock();
	load_time = (float)(end - start)/CLOCKS_PER_SEC;
	
	if (n == -1) perror("Read");
	
	printf("Copy %s to %s (chunck size = %s)\n", path, argv[2], argv[3]);
	printf("It takes %.10f seconds\n", load_time);
	close(rfd);
	close(wfd);
	return 0;
}
