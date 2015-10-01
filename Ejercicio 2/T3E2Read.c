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
#include <sys/shm.h>
#include <sys/stat.h>

int main ()
{
  key_t shm_key = 232323;
  const int shm_size = sizeof(int);

  int shm_id;
  int* shmaddr;
  int* shared_memory;

  shm_id = shmget (shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
  shmaddr = (int*) shmat (shm_id, 0, 0);
    int f = 1;
    int i;
    for(i = 2; i <= *shmaddr; ++i)
        f *= i;
  printf("%d! = %d\n",*shmaddr,f);
  shmdt (shmaddr);
  return 0;
}
