#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFFSIZE 4096

int main(int argc, char **argv)
{
  int fd1, fd2;
  
  if(argc == 1)
    {
      fd1 = 0;
      fd2 = 1;
    }
  else
    {
      if((fd1 = open))
    }
  
  return 0;
}
