#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{

    int n;
    int buffsize;

    if(argc < 2){
        printf("usage: ./bufftest size \n");
    }
    else{
        buffsize = atoi(argv[1]);
        char buff[buffsize];

        while((n =  read(STDIN_FILENO, buff, buffsize)) > 0){
            if(write(STDOUT_FILENO, buff, n) != n){
                perror("write error");
            }
        }
        if(n < 0){
            perror("read error");
        }
    }
}   
