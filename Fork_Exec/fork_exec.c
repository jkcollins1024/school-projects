#include <stdio.h> //printf
#include <unistd.h> //fork, execv
#include <errno.h> //perror, errno
#include <wait.h> //waitpid

int main(int argc, char **argv)
{
  //This program immediately spawns a child. fork
  //creates another process that is an identical copy
  //and both execute simultaneously. The only difference
  //between the two programs will be the return value of
  //fork. In the original (parent) program, fork will
  //return the process ID of the child copy it created.
  //In the new (child) program, fork will return 0.
  int child_pid = fork();

  if(child_pid == 0)
  {
    //We are the child, because fork returned 0. Our only
    //purpose in the universe is to execute our replacement.
    //In this example, that's our hello program. In a shell,
    //it would be whatever the user provides. This section
    //is largely similar to the simple_exec example. The
    //difference is that now our parent is still running.
    char *cmd_args[] = {"/scratch/jwdeve/live/hello",
                        NULL};

    printf("about to exec\n");
    if(execv("/scratch/jwdeve/live/hello", cmd_args) < 0)
    {
      printf("errno %d\n", errno);
      perror("trying to exec");
    }
  }
  else
  {
    //We are the parent, because fork return a non-zero child PID.
    //Before we continue or terminate, we should wait for our child
    //to finish. waitpid is a blocking call. In most cases, it does
    //not return until the process with the specified PID terminates,
    //though you can modify this behavior via option flags in the
    //third parameter. The second parameter is a result parameter 
    //that will be populated with information about the terminated
    //child. It should be provided as a reference to an integer.
    //See the man page for waitpid for details. 
    int status;
    printf("Parent wating for child process with pid %d.\n", child_pid);
    waitpid(child_pid, &status, 0);
    printf("child process terminated.\n");
  }

  return 0;
}
