
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	double m = atof(argv[1]), n = atof(argv[2]), l = atof(argv[3]);
	double temp = (m + n + l) / 3;
	printf("平均值是%f\n", temp);
	return 0;
}
