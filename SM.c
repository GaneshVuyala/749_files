//program to read data from the shared memory location
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main()
{
char *s;
int shmid=shmget(1234,20,IPC_CREAT|0666);
s=shmat(shmid,NULL,0);
printf("Entered msg: %s \n",s);
}
