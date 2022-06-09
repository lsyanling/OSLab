
#include<unistd.h>
#include<stdio.h>

int main(int argc, char* argv[]) {
	pid_t pid = fork();
	if (pid > 0) {
		printf("我是父进程，我的pid是%d，我的子进程的pid是%d\n", getpid(), pid);
		pid = fork();
		if (pid > 0) {
			printf("我是父进程，我的pid是%d，我的子进程的pid是%d\n", getpid(), pid);
		}
		else if (pid == 0) {
			printf("我是子进程2，我的pid是%d\n", getpid());
		}
	}
	else if (pid == 0) {
		printf("我是子进程1，我的pid是%d\n", getpid());
	}
	return 0;
}
