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

	int p[2];
	char *args[2];

	args[0] = "wc";
	args[1] = 0;

	pipe(p);
	if (fork() == 0) {
		close(0);
		dup(p[0]);
		close(p[0]);
		close(p[1]);
		exec("/wc", args);
	} else {
		close(p[0]);
		write(p[1], "hello world\n", 12);
		close(p[1]);
	}

	exit(0);
}
