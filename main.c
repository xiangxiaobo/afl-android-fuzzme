#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv){
    if ( argc != 2){
        printf("./afl-fuzzme @fname\n");
        return -1;
    }
    char* fname = argv[1];
    int fd = open(fname, O_RDONLY);
    if ( fd == -1){
        printf("error: cannot open file.\n");
        return -2;
    }
    uint8_t buff[5];
    int retn = read(fd, buff, 4); 
    if ( retn < 4){
        printf("error: no enough data\n");
        return -3;
    }
    if (buff[0] == 'F')
        if (buff[1] == 'U')
            if(buff[2] =='Z')
                if(buff[3]=='Z')
                    raise(SIGSEGV);

    return 0;
}
