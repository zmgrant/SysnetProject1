#include <stdio.h>
#include <stdlib.h>

int print_prompt(){
  char str[20];
  system("whoami && pwd");
  printf(" > ");
  scanf("%s", str);
  printf("You entered: \" %s \" \n", str);
  return 0;
}
