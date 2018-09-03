#include "HeapSort.h"

//���캯��
Heap::Heap(int * v, int vSize)
{
	vec = new int[vSize];
	memcpy(vec, v, vSize);
	vec_size = vSize;
}

/* **
* ���ݸ��ڵ�ţ��Ե�ǰ���ǽ���������
* ԭ��֮����û����Ը��ڵ�Ϊ��׼������������Ϊ��֪������ҡ����һ����Ҷ�ڵ㡱��
* ��ʵ�����ף�n/2 - 1
* **/
void Heap::root_sort(int * vec, int root, int size)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size)	//ͨ���ж��ӽڵ��Ƿ������У����粻��ֱ���˳���
		return;
	/* **
	* ��ʵ���Բ����ж������ӽڵ��Ƿ���ڣ���Ϊ�ں������õ�ʱ�򣬾��Ѿ���֤�ˣ�
	* ��һ�ֵ��ã��ֶ�ѡ�����һ����Ҷ�ڵ���ú�����n/2-1 ��ʾ���һ����Ҷ�ڵ�
	* �ڶ��ֵ��ã��ݹ���ã����õ�ʱ���ж� 2*record+1 < size��
	* **/
	
	if (right >= size){	//����ý��ֻ��������
		if(vec[root] < vec[left])
			swap(vec[root], vec[left]);
		return;
	}
	
	//����ʹ���ڵ�Ϊ���ֵ
	int record;
	if (vec[left] > vec[root] || vec[right] > vec[root]) {
		if (vec[left] > vec[right]) {
			swap(vec[left], vec[root]);
			record = left;
		}
		else {
			swap(vec[right], vec[root]);
			record = right;
		}	

		//�ж��Ƿ�ݹ飬�����ڡ��������ڵ㺯�������棬��Ϊ���粻��Ҫ�����Ļ�������Ҳ�Ͳ���Ҫ�ݹ��ˣ�
		if (2 * record + 1 < size)
			root_sort(vec, record, size);
	}
}

//������ʼ�󶥶�
void Heap::heap_init(int * vec, int size)
{
	for (int i = size/2 - 1; i >= 0; i--)
		root_sort(vec, i, size);
}

void Heap::heap_sort(int * vec, const int size)
{
	heap_init(vec, size);
	swap(vec[0], vec[size - 1]);

	for (int i = 0; i < size - 2; i++) {
		root_sort(vec, 0, size - 1 - i);
		swap(vec[0], vec[size - 2 - i]);
	}
}

//��������
Heap::~Heap()
{
	delete[] vec;
}
