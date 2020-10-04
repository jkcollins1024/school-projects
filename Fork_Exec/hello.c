#include <stdio.h> //printf
#include <unistd.h> //sleep

int main(int argc, char **argv)
{
  printf("Hello world\n");

  //having the program sleep for a bit helps us see
  //what is running when. It helps visualize the fork/
  //exec process.
  sleep(5);

  return 0;
}
