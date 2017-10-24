#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    
    int src, dest, n;
    char *srcPath, * destPath;
    char buff[4096];

    if(argc < 3){
        printf("usage: ./filecopy src dest\n");
        return 0;
    }

    srcPath = argv[1];
    destPath = argv[2];

    if((src = open(srcPath, O_RDONLY)) != -1){
        if((dest = creat(destPath, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) != -1){
            while((n =  read(src, buff, 4096)) > 0){
                if(write(dest, buff, n) != n){
                    perror("write error");
                }
            }
            if(n < 0){
                perror("read error");
            }
            close(dest);
        }
        else{
            perror("create error");
        }
        close(src);
    }
    else{
        perror("open error");
    }
}   
