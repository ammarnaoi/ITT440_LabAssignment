#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 100

void func(int sockfd)
{
  char buff[MAX];
  int n;
  for(;;)
  {
    bzero(buff,sizeof(buff));
    printf("Enter string: ");
    n=0;
    
    while((buff[n++] = getchar()) != '\n')
      ;
    write(sockfd, buff, sizeof(buff));
		bzero(buff, sizeof(buff));
    
    read(sockfd, buff, sizeof(buff));
		printf("Server: %s", buff);
    
     if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
     }
  }
}

int main()
{
  int sockfd,connfd,len;
  struct sockaddr_in server, client;
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
  {
     printf("socket creation failed.\n");
     exit(0);
  }
  printf("Socket successfully created..\n");
  
  bzero(&servaddr, sizeof(servaddr));
  
  server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("169.254.156.75");
	server.sin_port = htons(8888);
  
  if(connect(sockfd, (struct sockaddr*)&server, sizeof(server)) != 0)
    {
		printf("Connection failed.");
		exit(0);
	}
	printf("Connection successful.\n");
  
	func(sockfd);

	close(sockfd);
}
