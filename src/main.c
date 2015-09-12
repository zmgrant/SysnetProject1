#include "main.h"
#include "prompt.h"
#include <stdio.h>
#include <unistd.h>

int main( int argc, char **argv )
{
  //  execlp("ls", "ls", "-l", (char *)0);
  print_prompt();
    return 0;
}
