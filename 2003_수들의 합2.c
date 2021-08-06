#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	int *box = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &box[i]);
	}

	int s = 0, e = 0;
	
	/* How to Solve
	*  ó���� ���۰� ���� ��� 0���� �����ȴ�.
	*  s��ġ(����)���� e��ġ(��) �迭�� ���� ��� ���Ѵ�.
	*  �� ���� ���� M���� �۰� �ȴٸ�, e�� ������Ų��.
	*  �׷��� ���� ���ų� ũ�� �ȴٸ�, �� ���� ���� �����ϰ�
	*  s�� ���Ѵ�.
	*  �׷������� ��� ���� ���غ��� M�� ������ ���Ѵ�.
	*/

	/* �� ������ �˰����ε�, �ڿ����� �ƴ϶�� �Ұ����ϴ�. */

	int sum = 0, answer = 0;
	//end�� N�� ������ �� ���� �غ���.
	while (e <= N)
	{
		if (sum < M) {
			sum = sum + box[e];
			e++;
		}
		else if (sum >= M) {
			sum = sum - box[s];
			s++;
		}
		if (sum == M) {
			answer++;
		}
	}
	printf("%d\n", answer);
	free(box);
	return 0;
}