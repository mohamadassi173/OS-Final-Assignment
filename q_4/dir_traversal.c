#define _XOPEN_SOURCE 500
#include <stdio.h> 
#include <stdlib.h>
#include <ftw.h>




int fbg(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf){
    if(tflag != FTW_SLN && tflag != FTW_SL){
    if(tflag == FTW_F) printf("F ");
    else if(tflag == FTW_D) printf("D ");
    else printf("NOT D OR F");
    printf("%ld %s\n",sb->st_ino, fpath + ftwbuf->base);
    }
    return 0;
}


int main(int argc, const char* argv[]){
    if(argc <= 1){
        printf("You must enter the path.\n");
        return 1;
    }
    if(nftw(argv[1], &fbg, 10, FTW_PHYS) != 0){
        printf("ERROR while running!\n");
	return 0;
	
    }
    exit(EXIT_SUCCESS);
}
