#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

#define LOG_LEVEL USER_LOG_INFO
#include "user/log.h"

int mian(int argc, char **argv){
    logv("test logv\n");
    logd("test logd\n");
    logi("test logi\n");
    logw("test logw\n");
    loge("test loge\n");
	exit(0);
}