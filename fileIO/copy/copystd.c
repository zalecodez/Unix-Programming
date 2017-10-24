#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int n;
    char buff[4096];

    while((n =  read(STDIN_FILENO, buff, 4096)) > 0){
        if(write(STDOUT_FILENO, buff, n) != n){
            perror("write error");
        }
    }
    if(n < 0){
        perror("read error");
    }
}   
