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
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int c = 0;
	char * argumento = NULL;
	    while ((c = getopt(argc, argv, "m:")) != -1) {
	        switch (c) {
	        	case 'm':
	                argumento = optarg;
	                break;
	            case '?':
	                return 1;
	            default:
	                abort();
	        }
	    }
	FILE *fp= NULL;
	pid_t process_id = 0;
	pid_t sid = 0;
	int sleepFor = atoi(argumento) * 60;
	process_id = fork();
	if (process_id < 0)
		{
			printf("fork failed!\n");
			exit(1);
		}
	if (process_id > 0)
	{
		printf("Daemon's Pid: %d \n", process_id);
		exit(0);
	}
		umask(0);
		sid = setsid();
		if(sid < 0)
			exit(1);
		
		chdir("/");
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		while (1)
			{
				sleep(sleepFor);
				system("cat /proc/*/status | grep 'Name\\|^Pid' > procesosActivos.txt");
			}
		return (0);
}
