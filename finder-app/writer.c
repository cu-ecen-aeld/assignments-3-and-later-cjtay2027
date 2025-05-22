#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>


int main(int argc, char * argv[])
{
    // Set up logger
    openlog(NULL,0,LOG_USER);

    // error if argument not the correct number
    if(argc != 3){
        syslog(LOG_ERR, "Invalid number of arguments passed\n");
        return 1;
    }
    else{
        char* file_name = argv[1];
        char* write_string = argv[2];

        int fd = open(file_name,O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

        if(fd == -1){
            syslog(LOG_ERR,"%s\n",strerror(errno));
        }
        else{
            syslog(LOG_DEBUG,"Writing %s to %s\n",write_string, file_name);
            write(fd,write_string,strlen(write_string));
            close(fd);
            return 0;
        }

    }
    

}