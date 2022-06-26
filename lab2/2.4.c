#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main ()
{
  pid_t wpid;
  
  for(int i = 0; i < 4; i++)
  {
    pid_t pid = fork();
    
    if(pid == 0)
    {
      printf("What is your name? > ");
      scanf("%s", name);
      printf("Your name is %s\n", name);
      exit(0);
    }
    else if(pid>0)
    {
      perror("fork");
      exit(1);
    }
    else
    {
      printf("Unable to create child process.");
    }
  }
  printf("Job is done.\n");
  
  return EXIT_SUCCESS:
}
