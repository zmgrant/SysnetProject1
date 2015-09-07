#include "main.h"
#include <stdio.h>
#include <unistd.h>

int main( int argc, char **argv )
{
  execlp("ls", "ls", "-l", (char *)0);

    return 0;
}
