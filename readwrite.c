#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
int fd;
char buf[14];
fd=open("myfile.txt",O_CREAT | O_WRONLY,0600);
if(fd==-1){
    printf("Failed to create and open the file\n");
    exit(1);
}
write(fd,"Hello World!\n",13);
close(fd);



fd=open("myfile.txt",O_RDONLY);
if(fd==-1){
    printf("Failed to open and read the file\n");
    exit(1);
}
read(fd,buf,13);
buf[13]='\0';

printf("%s",buf);
fsync(fd);   // fsync funtion
close(fd);
    return 0;
}

