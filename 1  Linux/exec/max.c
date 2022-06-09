
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	double m = atof(argv[1]), n = atof(argv[2]);
	double temp = m > n ? m : n;
	printf("最大值是%f\n", temp);
	return 0;
}
