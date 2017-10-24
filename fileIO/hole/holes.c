#include <fcntl.h>
#include <stdio.h>

int main(void){

    int i;
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    char buf3[16394];

    for(i = 0; i < 16394; i++){
        buf3[i] = buf1[i%10];
    }

    int fd;

    if((fd = creat("file.hole", S_IRUSR | S_IWUSR)) < 0 ){
        perror("create error");
    }
    //if(write(fd, buf1, 10) != 10){
    //    perror("buf1 write error");
    //}
    ////offset now 10
    
    if(lseek(fd, 16384, SEEK_SET) == -1){
        perror("lseek error");
    }
    //offset now 16384

    if(write(fd, buf2, 10) != 10){
        perror("buf2 write error");
    }
    //offset now 16394
    
    //create a file without holes with the same size as file.hole
    if((fd = creat("file.nohole", S_IRUSR | S_IWUSR)) < 0 ){
        perror("create error");
    }
    if(write(fd, buf3, 16394) != 16394){
        perror("buf3 write error");
    }

}
