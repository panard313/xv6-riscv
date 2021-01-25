#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

#define LOG_LEVEL USER_LOG_INFO
#include "user/log.h"

// redirect cat

int mian(int argc, char **argv){
    // should be like "redirect-t < README"

    logi("Entry main");
    char *args[2];

    args[0] = "cat";
    args[1] = 0;

	int pid = fork();
	if (0 == pid) {
		close(0);
		open("README", O_RDONLY);
		exec("/cat", args);
		loge("exec error !");
		exit(0);
	}
	wait(&pid);
	exit(0);
}
