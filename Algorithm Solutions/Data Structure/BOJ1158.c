#include <stdio.h>

typedef struct element
{
	int num;
	struct element * next;
} Element;

Element man[10000];
int result[10000];

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	for(int i = 0; i < N; ++i) {
		man[i].num = i+1;
		man[i].next = &man[(i+1)%N];
	}
	
	Element * target = &man[N-1];
	int lastResultIdx = 0;
	
	while(target != target->next) {
		for(int i = 0; i < K-1; ++i) {
			target = target->next;
		}
		
		result[lastResultIdx] = target->next->num;
		lastResultIdx++;
		target->next = target->next->next;
	}
	
	result[lastResultIdx] = target->next->num;
	
	printf("<");
	for(int i = 0; i < N-1; ++i) {
		printf("%d, ", result[i]);
	}
	printf("%d>", result[N-1]);
	
	return 0;
}
