#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 100

void func(int connfd)
{
  char buff[MAX];
  int n;
  
  for(;;)
  {
    bzero(buff,MAX);
    
    read(connfd,udd,sizeof(buff));
    print("Client: %s", buff);
    print("Server: ");
    
    bzero(buff,MAX);
    n=0
      
      while((buff[n++] = getchar()) != '\n')
			;
      write((connfd, buff, sizeof(buff));
          
      if(strncmp("exit", buff, 4) == 0)
        {
			printf("Server Exit.\n");
			break;
		}
            }
            
        int main(){
	int sockfd, connfd, len;
	struct sockaddr_in server, client;

	//Socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
    {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");

	bzero(&server, sizeof(server));
          
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	
	if(bind(sockfd,(struct sockaddr*)&server, sizeof(server)) < 0)
    {
		puts("Bind failed");
		exit(0);
	}
	else
		puts("Bind successful");

	//Listen
	if((listen(sockfd, 5)) != 0)
    {
		puts("Listen failed.");
		exit(0);
	}
	else
		puts("Server listening...");
	len = sizeof(client);
          
          
	connfd = accept(sockfd, (struct sockaddr*)&client, &len);
	if(connfd < 0)
    {
		puts("Client Failed");
		exit(0);
	}
	else
		puts("Client accepted.\n");

	func(connfd);

	close(sockfd);
}
