/*
 ============================================================================
 Name        : Tarea.c
 Author      : José Cisneros
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define FILEPATH "mmap.bin"
#define NUMINTS  1
#define FILESIZE (NUMINTS * sizeof(int))

int main(int argc, char *argv[])
{
    int i;
    int fd;
    int result;
    int *map;  

    fd = open(FILEPATH, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
    if (fd == -1) {
	perror("Error when opening file.");
	exit(EXIT_FAILURE);
    }

    result = lseek(fd, FILESIZE-1, SEEK_SET);
    if (result == -1) {
	close(fd);
	perror("Error when calling lseek() to 'stretch' the file.");
	exit(EXIT_FAILURE);
    }

    result = write(fd, "", 1);
    if (result != 1) {
	close(fd);
	perror("Error when writing last byte of the file.");
	exit(EXIT_FAILURE);
    }

    map = mmap(0, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
	close(fd);
	perror("Error when mmapping the file.");
	exit(EXIT_FAILURE);
    }

    while(1){
    printf("Enter number: (-1 to Quit)\n");
    scanf("%d",map);
    if(*map == -1)
    	break;
    system("./T3E4Read");

    }

    if (munmap(map, FILESIZE) == -1) {
	perror("Error when un-mmapping the file.");
    }

    close(fd);
    return 0;
}
