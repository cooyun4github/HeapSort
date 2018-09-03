#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

class Heap {
public:
	Heap(int *v, int vSize);	//构造函数
	void heap_init(int *vec, int size);	//构建初始堆函数
	void heap_sort(int *vec, int size);	//排序
	~Heap();	//析构函数
private:
	int *vec;	//数组名
	int vec_size;	//数组大小
	void root_sort(int *vec, int root, int size);	//对根节点及子节点进行递归排序
};
