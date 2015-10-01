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
    int *map;

    fd = open(FILEPATH, O_RDONLY);
    if (fd == -1) {
	perror("Error when opening file.");
	exit(EXIT_FAILURE);
    }

    map = mmap(0, FILESIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
	close(fd);
	perror("Error when mmapping the file.");
	exit(EXIT_FAILURE);
    }

    int f = 1;
           int j;
           for(j = 2; j <= *map; ++j)
               f *= j;
         printf("%d! = %d\n",*map,f);

    if (munmap(map, FILESIZE) == -1) {
	perror("Error when un-mmapping the file.");
    }
    close(fd);
    return 0;
}
