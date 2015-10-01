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
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main ()
{
  key_t shm_key = 232323;
  const int shm_size = sizeof(int);

  int shm_id;
  int * shmaddr, *ptr;

  shm_id = shmget (shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
  shmaddr = (int*) shmat (shm_id, 0, 0);
  while(1){
    int i = 0;
    printf("Enter number: (-1 to Quit)\n");
    scanf("%d",&i);
    if(i == -1)
      break;
    *shmaddr = i;
    system("./T3E2Read");
  }
  shmdt (shmaddr);
  shmctl (shm_id, IPC_RMID, 0);

  return 0;
}

