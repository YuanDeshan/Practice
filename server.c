#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_LISTEN 5

void  *myclient( void *client_fd);


int main(int argc, const char *argv[])
{
	int fd,ret;
	int client_fd;
	struct sockaddr_in myaddr,client_addr;
	int len = sizeof(struct sockaddr_in);
	char buf[20] = {0};
	socklen_t addrlen;

	if(argc < 3)
	{
		printf("please input ip and port\n");
	}

	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1)
	{
		printf("socket error: fd = %d\n",fd);
		return -1;
	}
	printf("socket ok , fd = %d\n",fd);
	memset(&myaddr,0,len);
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(atoi(argv[2]));
	myaddr.sin_addr.s_addr = inet_addr(argv[1]); 
	//myaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	//myaddr.sin_addr.s_addr = htonl(0); 

	ret = bind(fd,(struct sockaddr *)&myaddr,len);
	if(ret == -1)
	{
		printf("bind error: ret = %d\n",ret);
		return -1;
	}
	puts("bind ok!");
	ret = listen(fd,MAX_LISTEN);
	if(ret < 0)
	{
		printf("listen error: ret = %d\n",ret);
		return -1;
	}
	puts("listen ok!");


	while(1)
	{
		pthread_t new_id;
		
		client_fd = accept(fd,(struct sockaddr *)&client_addr,&addrlen);

		pthread_create(&new_id,NULL,myclient , (void *)&client_fd);


	}
	return 0;
}

void  *myclient( void *myfd)
{
	int fd = *(int *)myfd;
	char buf[20];
	int ret;

	while(1)
	{
		memset(buf,0,20);
		ret = recv(fd,buf,20,0);
		if(ret < 1)
			break;
		printf("buf:%s\n",buf);
		send(fd,buf,strlen(buf),0);
	}
	close(fd);
	pthread_exit(NULL);
}


