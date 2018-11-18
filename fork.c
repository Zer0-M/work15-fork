#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(){
    srand( time(NULL) );
    int f;
    int status;
    int t;
    printf("Progenitor pid:%d\n",getpid());
    f=fork();
    if(f){
        f=fork();
        if(!f){
            printf("Spawn1 pid:%d\n",getpid());
            t=(rand()%15)+5;
            sleep(t);
            printf("Child with pid %d exited\n",getpid());
            exit(t);
        }
        else{
            int exited_child=wait(&status);
            printf("Child with pid %d exited after %d seconds\n",exited_child,WEXITSTATUS(status));
            return 0;
        }
    }
    else{  
        printf("Spawn0 pid:%d\n",getpid());
        t=(rand()%15)+5;
        sleep(t);
        printf("Child with pid %d exited\n",getpid());
        exit(t);
    }
    return 0;
}