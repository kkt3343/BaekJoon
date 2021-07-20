#include <iostream>

using namespace std;

int box[9] = { 0 };
int main(void)
{
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> box[i];
		sum = sum + box[i];
	}
	bool key = false;
	int result = 0;
	int x, y;
	/*�˰��� ����*/
	/*
	* 9�� �߿� 7���� ���ϴ� ���� �����ϱ� ������ �ݴ�� 9���� ��� ���Ѵ���
	* 2���� ���Ͽ� ����.
	* �� �� 2���� �ߺ��� �Ǹ� �ȵȴ�.
	* ���Ʈ�����̱� ������ �ϳ��ϳ� �� �غ��� ���ۿ� ����.
	*/
	for (int i = 0; i < 9 && key == false; i++) {
		for (int j = 0; j < 9 && key == false; j++) {
			result = sum - box[i] - box[j];
			if (result == 100 && box[i] != box[j])
			{
				key = true;
				x = i;
				y = j;
			}
		}
	}
	//���õ� �� ���� �鼳������ �����̰� �ƴϱ� ������ -1�� ġȯ�Ѵ�.
	box[x] = -1; box[y] = -1;
	int tem;
	//������ �ǽ��Ѵ�.(��������) / �� �� ������ �������� ���
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - 1 - i; j++) {
			if (box[j] > box[j + 1]) {
				tem = box[j];
				box[j] = box[j + 1];
				box[j + 1] = tem;
			}
		}
	}
	// -1�� �� �����̸� �����ϰ� ���
	for (int i = 2; i < 9; i++) {
		printf("%d\n", box[i]);
	}
	return 0;
}