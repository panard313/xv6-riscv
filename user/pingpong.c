#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

#define LOG_LEVEL USER_LOG_INFO
#include "user/log.h"

// redirect cat

int mian(int argc, char **argv){

    logi("Entry main");

	int pipe_p2c[2];
	int pipe_c2p[2];

	char *buf[32];
	pipe(pipe_c2p);
	pipe(pipe_p2c);
	if (fork() == 0) {
		memset(buf, 0, sizeof(buf));
		read(pipe_p2c[0], buf, sizeof(buf));
		logi("%d: received %s", getpid(), buf);
		close(pipe_p2c[0]);

		write(pipe_c2p[1], "pong\n", 5);
		close(pipe_c2p[1]);
	} else {
		write(pipe_p2c[1], "ping\n", 5);
		close(pipe_p2c[1]);

		memset(buf, 0, sizeof(buf));
		read(pipe_c2p[0], buf, sizeof(buf));
		logi("%d: received %s", getpid(), buf);
		close(pipe_c2p[0]);
	}

	exit(0);
}
