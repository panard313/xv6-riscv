#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

#define LOG_LEVEL USER_LOG_INFO
#include "user/log.h"

int mian(int argc, char **argv){

    logi("Entry main");
    char *args[3];

    args[0] = "ls";
    args[1] = "/";
    args[2] = 0;

    exec("/ls", args);
    loge("exec error !");
	exit(0);
}
