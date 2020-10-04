#include <stdio.h> //printf
#include <unistd.h> //execv
#include <errno.h> //perror, errno

int main(int argc, char **argv)
{
  // First, setup the arguments array. Our hello world
  // app does not take any command-line parameters, so
  // we only have the name of the program being executed.
  // Note that cell 0 of the argument array ALWAYS contains
  // the program name, even though that is also provided
  // as an explicit parameter to execve. This array is
  // NULL-terminated.
  char *cmd_args[] = {"/scratch/jwdeve/live/hello",
                      NULL};

  printf("about to exec\n");
  
  //execv only returns if it is unable to run the specified
  //program (otherwise, that program is running instead). If
  //it does return, it will be with a negative value indicating
  //an error. The first parameter to execv is the name of the
  //program to launch. The second parameter is the argument 
  //array we created above. (The v in execv stands for vector,
  //the mechanism by which arguments are provided.)
  if(execv("/scratch/jwdeve/live/hello", cmd_args) < 0)
  {
    //Typically, when a system call fails, the uberglobal
    //variable errno is set to an integer indicating the cause
    //of the error. Because numbers are meaningless to humans, 
    //the perror function generates a human-readable explanation
    //of the error condition.
    printf("errno %d\n", errno);
    perror("trying to exec");
  }

  //Still only reachable if the exec failed. One could argue that
  //we shoulr return -1 here, instead.
  printf("after exec\n");

  return 0;
}
