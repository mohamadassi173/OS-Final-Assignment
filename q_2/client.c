
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

int main(int argc, char *argv[]){
    if(argc<4){
        printf("you must enter the server <pid>, <signl number> and the amount of <signals to send>.\n");
        return 1;
    }
	int pid = atoi(argv[1]); 
	int signal_num = atoi(argv[2]); 
	int times =atoi(argv[3]); 

for (int i=0; i<times; i++){
kill(pid, signal_num );
printf("Sending signal %d to %d.\n", signal_num, pid);
} 

 printf("Finished\n");

return 0;
}
