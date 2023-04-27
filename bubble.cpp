/** 
 * @author: yuyuyuj1e 807152541@qq.com
 * @github: https://github.com/yuyuyuj1e
 * @csdn: https://blog.csdn.net/yuyuyuj1e
 * @date: 2023-04-27 10:51:57
 * @last_edit_time: 2023-04-27 11:22:15
 * @file_path: /sort-algorithm/bubble.cpp
 * @description: 冒泡排序
 */

#include "common.h"

using namespace std;


/** 
 * @description: 冒泡排序，重复地走访过要排序的元素列，依次比较两个相邻的元素，如果顺序错误就把他们交换过来；走访元素的工作是重复地进行，直到没有相邻元素需要交换，也就是说该元素列已经排序完成
 * @description: 特点：每一轮都会将最大(最小)的数下沉，也就是每一轮至少有一个数字(待排序的最大或最小的数)到正确位置
 * @description: 是否稳定：是
 * @description: 空间复杂度：O(n)
 * @description: 最差时间复杂度：O(n^2)
 * @description: 平均时间复杂度：O(n^2) 
 */
void bubble(vector<int>& vec) {
    // 排序趟数
    for (int i = 0; i < vec.size() - 1; ++i) {
        // 判断本轮是否有变动，如果没有变动，说明排序已经完成，可以提前退出
        bool flag = false;  

        for (int j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                flag = true;
            }
        }

        cout << "step: " << i + 1 << " ---> " << vec << endl;

        if (!flag) {
            break;
        }
    }
}

int main () {
    vector<int> vec{5, 3, 2, 6, 3, 7, 1, 9 ,8};
    cout << "before: ---> " << vec << endl;

    bubble(vec);
    return 0;
}