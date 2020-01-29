#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int M_GET_SIZE(float size_giga) {
	float final_size = size_giga * pow(10, 9); 
	return (int) final_size;
}
void M_PAUSE(long delta) {
	long unsigned int pause = (int) (delta * pow(10, 9));
	long unsigned int k = 0;
	while(k < pause){
		k++;
	}
}
void M_PIC_PAUSE(float size_giga, float delta) {
	// 1 char => 1 o
	// 10^9 char => 1 Go
	int size = M_GET_SIZE(size_giga);
	char* tmp = (char* ) malloc(sizeof(char) * size);
	for(int i = 0; i < size; i++) {
		tmp[i] = 'a';
	}
	M_PAUSE(delta);
	free(tmp);
}
void M_PIC(float size_giga) {
 	M_PIC_PAUSE(size_giga, 0);
}

int main() {
	int n_curves = 10,
		     num = 1;

	float max = 1.2,
		delta = 9.0,
     interval = 5;

	while(num <= n_curves) {
		printf("\n- Curve number %i :: %f Go\n", num, max);
		M_PIC_PAUSE(max, delta);
		M_PAUSE(interval);
		num++;
	}
	printf("\n** End.\n");
	system("pause");
	return 0;
}
