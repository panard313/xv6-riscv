#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

#define LOG_LEVEL USER_LOG_INFO
#include "user/log.h"

int mian(int argc, char **argv){

    int pid = fork();
    if (pid == 0){
        logi("I'm child, exit now");
        exit(0);
    } else if (pid > 0) {
        //sleep(1);
        //wait(&pid);
        logi("I'm parent, child pid=%d", wait(&pid));
    } else
        loge("fork error !");
	exit(0);
}
