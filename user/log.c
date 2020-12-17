#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

#define LOG_LEVEL USER_LOG_INFO
#include "user/log.h"

int mian(int argc, char **argv){
    logv("test logv");
    logd("test logd");
    logi("test logi");
    logw("test logw");
    loge("test loge");
	exit(0);
}
