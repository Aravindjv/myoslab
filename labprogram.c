#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    pid=vfork();
    if(pid==-1)
    {
        perror("vfork");
        return 1;
    }
    else if(pid==0)
    {
        printf("child process:hello,I'm child!\n");
        printf("child process:my PID is %d\n",getpid());
        printf("child process:my parent's PID is %d\n",getppid());
        _exit(0);
    }
    else{
        printf("parent process:Hello ,I'm the parent\n");
         printf("parent process:Hello ,my PID is %d\n",getpid());
          printf("parent process:Hello ,my childs PID is %d\n",pid);
    }
    int status;
    waitpid(pid,&status,0);
    if(WIFEXITED(status)){
        printf("parent process:child process is terminated normally");
    }
    else{
        printf("parent process:child process is terminated abnormally\n");
    }
return 0;
    }
    
