#define _GNU_SOURCE
#include <stdio.h> 
#include <unistd.h> 
#include <sched.h>
#include <errno.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/syscall.h>
#include <linux/sched.h>
#include <stdint.h>


struct sched_attr {
    uint32_t size;
    uint32_t sched_policy;
    uint64_t sched_flags;
    int32_t sched_nice;
    uint64_t sched_period;
    uint64_t sched_runtime;
    uint64_t sched_deadline;
    uint32_t sched_priority;
};


int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags) {
    return syscall(__NR_sched_setattr, pid, attr, flags);
}

int main(int argc, const char* argv[]){
    if(argc<=2){
        printf("ERROR!\n");
        return 1;
    }

    printf("the pid is: %d. (use chrt -p <pid>)\n", getpid());

    int policy = strtol(argv[1], NULL, 10);
    int priority = strtol(argv[2], NULL, 10);
	
    if(policy != SCHED_DEADLINE){
    struct sched_param param;
    param.sched_priority = priority;
	sched_setscheduler(0, policy, &param);
    }
    else if(policy == SCHED_DEADLINE){ // deadline policy 
            const struct sched_attr attr = {
            .size = sizeof (attr),
            .sched_policy = SCHED_DEADLINE,
            .sched_runtime = 10 * 1000 * 1000,
            .sched_period = 2 * 1000 * 1000 * 1000,
            .sched_deadline = 11 * 1000 * 1000
        };
	        sched_setattr(0, &attr, 0);
    }

	getchar();
    return 0;
}
