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
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY 2323

int main()
{
   int id; 
	union semun {
		int val;
		struct semid_ds *buf;
		ushort * array;
	} argument;

   id = semget(KEY, 1, 0666);
   if(id < 0)
   {
      fprintf(stderr, "Error semaphore does not exist.\n");
   }

   int value = semctl(id,0,GETVAL,argument);
   int f = 1;
       int i;
       for(i = 2; i <= value; ++i)
           f *= i;
     printf("%d! = %d\n",value,f);

return 0;
}
