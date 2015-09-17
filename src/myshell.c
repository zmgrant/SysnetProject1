#include stdio.h
#include stdlib.h

void  main(void)
{
     char  line[1024];             // the input line
     char  *argv[32];              // argument vector
     
     system("whoami && pwd");
     
     while (1) {                   // run until exit
          printf(" > ");     	   // prompt displays
          fgets(line);             // save the input into line
          printf("\n");
          parse(line, argv);       // parse line into argument vector
          if (strcmp(argv[0], "exit") == 0)  // exit procedure
               exit(0);            
          execute(argv);           // run the command
     }
}


void  execute(char **argv)
{
     pid_t  pid;
     int    status;
     
     if ((pid = fork()) < 0) {     // create a child
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) {          // runs if child
          if (execvp(*argv, argv) < 0) {     
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
     }
     else {                                  // runs if parent
          while (wait(&status) != pid)       // waits for process to complete
               ;
     }
}
