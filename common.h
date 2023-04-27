/** 
 * @author: yuyuyuj1e 807152541@qq.com
 * @github: https://github.com/yuyuyuj1e
 * @csdn: https://blog.csdn.net/yuyuyuj1e
 * @date: 2023-04-27 11:00:18
 * @last_edit_time: 2023-04-27 11:09:54
 * @file_path: /sort-algorithm/common.h
 * @description: 共用部分
 */

#include <iostream>
#include <vector>

/** 
 * @description: 输出 vector<int>
 */
std::ostream& operator<<(std::ostream &out, std::vector<int> &vec) {
    if (vec.size() == 0) {
		out << "Empty!" << std::endl;
	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			out << vec[i] << " ";
		}
	}
	return out;
}

/** 
 * @description: 交换两个数
 * @param {int&} l: 操作数一
 * @param {int&} r: 操作数二
 */
void swap(int& l, int& r) {
    int temp = l;
    l = r;
    r = temp;
}