/** 
 * @author: yuyuyuj1e 807152541@qq.com
 * @github: https://github.com/yuyuyuj1e
 * @csdn: https://blog.csdn.net/yuyuyuj1e
 * @date: 2023-04-03 13:55:34
 * @last_edit_time: 2023-04-03 16:37:47
 * @file_path: /sort-algorithm/heap/MinHeap.h
 * @description: 最小堆的头文件
 */

#pragma once
#include <iostream>
 
template <class T>
class MinHeap {
private:
	T* heap;  // 存放元素的数组
	int current_size;  // 当前元素的个数
	int max_size = 20;  // 最小堆最多允许的元素个数

	void siftDown(int start, int end);  // 向下调整
	void siftUp(int start);  // 向上调整

public:
	MinHeap();
	MinHeap(T arr[], int n);
	~MinHeap() { 
		delete[] heap; 
	}
 
	bool insert(const T& new_element);  // 插入新元素
	T remove();  // 移除堆顶的元素

	inline bool empty() const { 
		return (current_size == 0) ? true : false; 
	}
	inline bool full() const { 
		return (current_size == max_size) ? true : false; 
	}
	
	template<class R>
	friend std::ostream& operator<<(std::ostream &out, MinHeap<R> &hp);
};
 
template<class T>
MinHeap<T>::MinHeap() {
	heap = new T[max_size];  // 申请堆存储空间
	if (heap == nullptr) {
		std::cerr << "内存分配失败" << std::endl;
		exit(1);
	}
	current_size = 0;
}
 
template<class T>
MinHeap<T>::MinHeap(T arr[], int n) {
	heap = new T[max_size];
	if (heap == nullptr) {
		std::cerr << "内存分配失败！" << std::endl;
		exit(1);
	}
	current_size = n;
 
	// 把数组 arr 复制到堆数组中
	for (int i = 0; i < n; i++) {
		heap[i] = arr[i];
	}

	// 构建堆时需要从最后拥有子结点的结点的父节点开始，通过向下调整，不断获得最优子堆
	int currentPos = (current_size - 1) / 2;  
	for (; currentPos >= 0; currentPos--) {
		siftDown(currentPos, current_size - 1);
	}
}
 

/** 
 * @description: 插入新节点
 * @description: 插入的元素需要放到堆的最后面，采用向上调整的方法，不断与父节点进行比较
 * @description: 直到比父节点大，或者成为根节点
 * @param {T&} new_element: 待插入的元素
 * @return {bool} 成功返回 true，失败返回 false
 */
template<class T>
bool MinHeap<T>::insert(const T& new_element) {
	if (current_size == max_size) {
		std::cerr << "Heap Full!" << std::endl;
		return false;
	}
 
	// 将新元素放在堆的最后
	heap[current_size] = new_element;  
	siftUp(current_size);  // 向上调整
	current_size++;
	return true;
}

 
/** 
 * @description: 向上调整，用于向堆中插入一个数据，全局
 * @description: 从 start 开始，自下向上比较；
 * @description: 如果子节点小于父节点，则相互交换，直到（条件一）子节点大于父节点，（条件二）或者子节点成为根节点（index == 0）
 * @param {int} start: 子节点下标
 */
template<class T>
void MinHeap<T>::siftUp(int start) {
	/*
	 *	1. 下标为 i 的节点的父节点下标：(i - 1) / 2 【向下取整】
   	 *	2. 下标为 i 的节点的左孩子下标：i * 2 + 1
   	 *	3. 下标为 i 的节点的右孩子下标：i * 2 + 2
	 */
	int son = start, parent = (son - 1) / 2;
 
	while (son > 0) {  // 条件二
		if (heap[parent] < heap[son]) {  // 子节点大于父节点，条件一
			break;
		}
		else {
			// 交换父子节点
			T temp = heap[son];
			heap[son] = heap[parent];
			heap[parent] = temp;

			// 获取下一轮父子节点下标
			son = parent;  // 子节点(本节点)新下标
			parent = (son - 1) / 2;  // 父节点(下次循环的父节点)的新下标
		}
	}
 
}
 
 
/** 
 * @description: 移除堆顶元素
 * @description: 通过不断移除堆顶元素，直到堆空，就完成了一次堆排序
 * @description: 需要将堆顶元素，与最后一个元素互换位置，此时堆的特性已被破坏
 * @description: 然后通过向下调整，重新维护堆的特性
 * @return {T} 堆顶元素
 */
template<class T>
T MinHeap<T>::remove() {
	if (current_size == 0) {
		std::cerr << "Heap Empty!" << std::endl;
		return false;
	}
 
	T heap_top = heap[0];  // 取堆顶
	heap[0] = heap[current_size - 1];  // 将最后一个元素，放到堆顶；注意，此时堆的特性已经被破坏，需要重新维护
	heap[current_size - 1] = heap_top;
	current_size--;

	siftDown(0, current_size - 1);  // 从堆顶向下调整
	return heap_top;
}


/** 
 * @description: 向下调整，用于重构推结构，局部
 * @description: 从根节点开始，向下比较，与值更大的子节点交换
 * @description: 直到，成为叶子节点或者子节点都比自己小为止，这样将以 start 为根节点的子树调整为局部的最小堆
 * @param {int} start: 起始节点下标
 * @param {int} end: 结束节点下标
 */
template<class T>
void MinHeap<T>::siftDown(int start, int end) {
	int parent = start;
	int son = 2 * parent + 1;  // lson: i * 2 + 1，rson: i * 2 + 2
 
	while (son <= end) {
		// 让 son 指向更小的子节点
		if (son < end && heap[son + 1] < heap[son]) {
			son++;
		}
 
		// 两个子节点都比父节点的大
		if (heap[son] > heap[parent]) {
			break;  
		}
		else {
			// 交换节点
			T temp = heap[parent];
			heap[parent] = heap[son];
			heap[son] = temp;

			// 更新下标
			parent = son;  // 父节点(本节点)的新下标
			son = 2 * son + 1;  // 子节点(下次循环的子节点)的新下标
		}
	}
}

 
/** 
 * @description: 层序遍历堆，即从左至右输出数组
 */
template<class R>
std::ostream& operator<<(std::ostream &out, MinHeap<R> &hp) {
	if (hp.current_size == 0) {
		out << "Heap Empty!" << std::endl;
	}
	else {
		for (int i = 0; i < hp.current_size; i++) {
			out << hp.heap[i] << " ";
		}
	}
	out << std::endl;
	return out;
}