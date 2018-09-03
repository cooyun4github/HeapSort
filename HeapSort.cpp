#include "HeapSort.h"

//构造函数
Heap::Heap(int * v, int vSize)
{
	vec = new int[vSize];
	memcpy(vec, v, vSize);
	vec_size = vSize;
}

/* **
* 根据根节点号，对当前三角结点进行排序
* 原来之所以没有想对根节点为基准进行排序，是因为不知道如何找“最后一个非叶节点”，
* 其实很容易：n/2 - 1
* **/
void Heap::root_sort(int * vec, int root, int size)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left >= size)	//通过判断子节点是否在树中，假如不是直接退出！
		return;
	/* **
	* 其实可以不用判断左右子节点是否存在，因为在函数调用的时候，就已经保证了；
	* 第一种调用：手动选择最后一个非叶节点调用函数，n/2-1 表示最后一个非叶节点
	* 第二种调用：递归调用，调用的时候判断 2*record+1 < size；
	* **/
	
	if (right >= size){	//假如该结点只有左子树
		if(vec[root] < vec[left])
			swap(vec[root], vec[left]);
		return;
	}
	
	//交换使根节点为最大值
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

		//判断是否递归，必须在“交换根节点函数”里面，因为假如不需要交换的话，后面也就不需要递归了！
		if (2 * record + 1 < size)
			root_sort(vec, record, size);
	}
}

//构建初始大顶堆
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

//析构函数
Heap::~Heap()
{
	delete[] vec;
}
