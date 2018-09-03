#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

class Heap {
public:
	Heap(int *v, int vSize);	//���캯��
	void heap_init(int *vec, int size);	//������ʼ�Ѻ���
	void heap_sort(int *vec, int size);	//����
	~Heap();	//��������
private:
	int *vec;	//������
	int vec_size;	//�����С
	void root_sort(int *vec, int root, int size);	//�Ը��ڵ㼰�ӽڵ���еݹ�����
};
