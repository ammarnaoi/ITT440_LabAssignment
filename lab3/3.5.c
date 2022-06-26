#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

int main(void)
{
  void sigINT_handler(int sig);

        if(signal(SIGINT, sigINT_handler) == SIG_ERR)
        {
                perror("Signal");
                exit(EXIT_SUCCESS);
  }

  int number;
  int x;
  int pipes[2];
  pipe(pipes);
  pid_t pid = fork();

  if(pid==0)
  {
    printf("Enter a number : ");
                scanf("%d", &number);
                close(pipes[0]);
                write(pipes[1], &number, sizeof(number));
                exit(EXIT_SUCCESS);
  }

  else if(pid>0)
  {
    close(pipes[1]);
    read(pipes[0], &x, sizeof(int));
                close(pipes[0]);

  if(x <=3)
             {
               if(x == 1)
               {
                 printf("%d not a prime number.\n", x);
               }
               else
               {
                 printf("%d is a prime number.\n", x);
               }
               exit(EXIT_SUCCESS);
             }

             if(x > 3)
          {
            for(int i = 2; i <= x/2; i++)
            {
              if(x % i == 0)
              {
                printf("%d is not a prime number.\n", x);
                exit(1);
              }
              else
              {
               printf("%d is a prime number.\n", x);
                                             exit(1);
              }
            }
          }
          printf("Done");
          }
          else
          {
            perror("Error");
          }
    return 0;
 }

