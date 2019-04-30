#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void *func()
{
	printf("this is func!\n");
}


int main(int argc, const char *argv[])
{
	void *result;
	int ret;

	pthread_t my_thread;

	ret = pthread_create(&my_thread, NULL, func, NULL);
	perror("pthread_creat");
	if (ret != 0)
	{
		exit(-1);
	}
	printf("hello world\n");

	pthread_join(my_thread, &result);

	return 0;
}