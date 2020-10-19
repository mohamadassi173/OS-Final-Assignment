#include <errno.h>
#include <signal.h>
#include <stdio.h>

int main(int argc, char *argv[]){

pid_t pid = atoi(argv[1]); 
int isKilled = kill(pid, 0);
 if(isKilled==0){
 printf("Pid %d exists.\n",pid);
	}
    else if (errno == EPERM ) {
	printf("Process %d does exist but‬‬ we‬‬ ‫‪have‬‬ ‫‪no‬‬ ‫‪permission.(EPERM)\n",pid);
	}
	
	else{ printf("Process‬‬ %d ‫‪does‬‬ not ‫‪exist.(ESRCH)\n",pid);
}

return 0;
}
