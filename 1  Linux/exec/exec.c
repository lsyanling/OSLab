
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {
	// 获取当前目录
	char* fileName = malloc(sizeof(char) * 100);
	getcwd(fileName, 100);
	int length = strlen(fileName);

	// 环境配置，系统调用exec的参数
	char* envr[] = { NULL };

	printf("命令解释程序运行中，输入h查看帮助，输入q退出程序\n");

	while (1) {
		fileName[length] = '/';
		fileName[length + 1] = '\0';

		// 输入命令
		char* input = malloc(sizeof(char) * 100);
		printf(">>> ");
		fgets(input, 100, stdin);
		int i = 0;
		while (input[i] == ' ')
			i++;

		// 求最小值
		if (input[i] == 'm' && input[i + 1] == 'i' && input[i + 2] == 'n' && input[i + 3] == ' ') {
			i = i + 3;
			while (input[i] == ' ')
				i++;
			int o1 = i;
			while (input[i] != ' ')
				i++;
			input[i] = '\0';
			i++;
			while (input[i] == ' ')
				i++;
			int o2 = i;
			while (input[i] != ' ')
				i++;
			input[i] = '\0';

			pid_t pid = fork();
			// 子进程执行命令
			if (pid == 0) {
				// 补充调用的命令名
				strcat(fileName, "min");
				char* newArgv[] = { fileName, input + o1,input + o2, NULL };
				printf("解析失败，返回值%d\n", execve(fileName, newArgv, envr));
			}
			else if (pid > 0) {
				usleep(100000);
			}
		}
		// 求最大值
		else if (input[i] == 'm' && input[i + 1] == 'a' && input[i + 2] == 'x' && input[i + 3] == ' ') {
			i = i + 3;
			while (input[i] == ' ')
				i++;
			int o1 = i;
			while (input[i] != ' ')
				i++;
			input[i] = '\0';
			i++;
			while (input[i] == ' ')
				i++;
			int o2 = i;
			while (input[i] != ' ')
				i++;
			input[i] = '\0';

			pid_t pid = fork();
			// 子进程执行命令
			if (pid == 0) {
				// 补充调用的命令名
				strcat(fileName, "max");
				char* newArgv[] = { fileName, input + o1,input + o2, NULL };
				printf("解析失败，返回值%d\n", execve(fileName, newArgv, envr));
			}
			else if (pid > 0) {
				usleep(100000);
			}
		}
		// 求平均值
		else if (input[i] == 'a' && input[i + 1] == 'v' && input[i + 2] == 'e' && input[i + 3] == 'r'
			&& input[i + 4] == 'a' && input[i + 5] == 'g' && input[i + 6] == 'e' && input[i + 7] == ' ') {
			i = i + 7;
			while (input[i] == ' ')
				i++;
			int o1 = i;
			while (input[i] != ' ')
				i++;
			input[i] = '\0';
			i++;
			while (input[i] == ' ')
				i++;
			int o2 = i;
			while (input[i] != ' ')
				i++;
			input[i] = '\0';
			i++;
			while (input[i] == ' ')
				i++;
			int o3 = i;
			while (input[i] != ' ')
				i++;
			input[i] = '\0';

			pid_t pid = fork();
			// 子进程执行命令
			if (pid == 0) {
				// 补充调用的命令名
				strcat(fileName, "average");
				char* newArgv[] = { fileName, input + o1,input + o2,input + o3, NULL };
				printf("解析失败，返回值%d\n", execve(fileName, newArgv, envr));
			}
			else if (pid > 0) {
				usleep(100000);
			}
		}
		else if (input[i] == 'a' && input[i + 1] == 'v' && input[i + 2] == 'g' && input[i + 3] == ' ') {
			i = i + 3;
			while (input[i] == ' ')
				i++;
			int o1 = i;
			while (input[i] != ' ')
				i++;
			input[i] = '\0';
			i++;
			while (input[i] == ' ')
				i++;
			int o2 = i;
			while (input[i] != ' ')
				i++;
			input[i] = '\0';
			i++;
			while (input[i] == ' ')
				i++;
			int o3 = i;
			while (input[i] != ' ')
				i++;
			input[i] = '\0';

			pid_t pid = fork();
			// 子进程执行命令
			if (pid == 0) {
				// 补充调用的命令名
				strcat(fileName, "average");
				char* newArgv[] = { fileName, input + o1,input + o2,input + o3, NULL };
				printf("解析失败，返回值%d\n", execve(fileName, newArgv, envr));
			}
			else if (pid > 0) {
				usleep(100000);
			}
		}
		// 帮助
		else if (input[i] == 'h') {
			printf("输入格式：命令名 操作数1 操作数2 [操作数3]\n");
			printf("max：max 1 2\nmin：min 2 3\naverage：avg 1 2 3 或 average 1 2 3\n");

		}
		// 退出
		else if (input[i] == 'q') {
			printf("命令解释程序结束\n");
			break;
		}
		// 输入错误
		else {
			printf("无法解析此命令，输入h以请求帮助\n");
		}
		free(input);
	}

	free(fileName);

	return 0;
}
