#include <iostream>
#include <ctime>
using namespace std;

void setRandValues(int *arr, int len) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % 1000000;
};

int main1(int N) {
	//int N;
	//while (true) {
	//	scanf_s("%d",&N);
	//	if ((N == (int)N) && (N > 1))
	//		break;
	//}

	int *mas = (int*)malloc(sizeof(int)*N);
	setRandValues(mas,N);

	//for (int i = 0; i < N; i++)
		//printf("element %d = %d\n",i,mas[i]);
	//printf("\n");

	int buf;
	clock_t start = clock();
	// Пузырьковая сортировка
	for (int i = 0; i < N-1; i++)
		for (int j = 0; j < N-1; j++) {
			if (mas[j] > mas[j + 1]) {
				buf = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = buf;
			}
		}
	
	// Чет-нечетная сортировка
	clock_t end = clock();
	/*for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j+=2) {
			if (mas[j] > mas[j + 1]) {
				buf = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = buf;
			}
		}
		for (int j = 1; j < N - 1; j+=2) {
			if (mas[j] > mas[j + 1]) {
				buf = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = buf;
			}
		}
	}*/

	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time to sort is %f\n",seconds);


	//for (int i = 0; i < N; i++)
		//printf("element %d = %d\n", i, mas[i]);
	printf("\n");
	return 0;
}

int main() {
	for (int k = 10000; k <= 100000; k += 10000) {
		printf("length %d ", k);
		main1((int)k);
	
	}
}
