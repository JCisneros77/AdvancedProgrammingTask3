/*
 ============================================================================
 Name        : Tarea.c
 Author      : José Cisneros
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

#define KEY 2323

int main()
{
   int id; 
	union semun {
		int val;
		struct semid_ds *buf;
		ushort * array;
	} argument;

   argument.val = 0;
   id = semget(KEY, 1, 0666 | IPC_CREAT);

   if(id < 0)
   {
      fprintf(stderr, "Error when creating semaphore.\n");
   }

   while(1){
	   printf("Enter number: (-1 to Quit)\n");
	   scanf("%d",&argument.val);
	   if(argument.val == -1)
		   break;
	   semctl(id, 0, SETVAL, argument);
	   system("./T3E3Read");
   }

   semctl(id, 0, IPC_RMID, argument);

   return 0;
}
