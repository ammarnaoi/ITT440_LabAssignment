#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void)
{
  void sigINT_handler(int sig);
  void sigTSTP_handler(int sig);
  void sigQUIT_handler(int sig);
  char s[200];

  if (signal(SIGINT, sigINT_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }

  else if (signal(SIGTSTP, sigTSTP_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }

  else if (signal(SIGQUIT, sigQUIT_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }

  printf("Enter a string:\n");

  if (fgets(s, 200, stdin) == NULL)
      perror("gets");
  else
      printf("you entered: %s\n", s);

  return 0;
}

void sigINT_handler(int sig)
{
  printf("This is a special signal handler for INT signal (SIGINT) \n");
}

void sigTSTP_handler(int sig)
{
  printf("This is a special signal handler for TSTP signal (SIGTSTP) \n");
}

void sigQUIT_handler(int sig)
{
  printf("This is a special signal handler for QUIT signal (SIGQUIT) \n");
}
return 0;
}
