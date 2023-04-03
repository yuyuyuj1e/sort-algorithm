/** 
 * @author: yuyuyuj1e 807152541@qq.com
 * @github: https://github.com/yuyuyuj1e
 * @csdn: https://blog.csdn.net/yuyuyuj1e
 * @date: 2023-04-03 16:28:03
 * @last_edit_time: 2023-04-03 16:35:18
 * @file_path: /sort-algorithm/heap/main.cpp
 * @description: 最小堆测试文件
 */

#include "MinHeap.h"
#include <iostream>

using namespace std;
int main() {
	int arr[8] = { 17, 33, 58, 2, 6 };
	MinHeap<int> iheap(arr, 5);
	cout << iheap;
	iheap.insert(11);
	cout << iheap;

	MinHeap<float> fheap;
	fheap.insert(3.3);
	fheap.insert(7.3);
	fheap.insert(3.8);
	fheap.insert(7.1);
	cout << fheap.remove() << " " << fheap.remove() << " " << fheap.remove() << " " << fheap.remove() << " " << endl;

	return 0;
}