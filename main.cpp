#include "SortFunctions.h"
#include <iostream>
using namespace std;

/*定义输出一维数组的函数*/
void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main() {
/***顺序查找测试***/
//    int arr[] = {1, 23, 5, 45, 2, 54};
//    int len = sizeof(arr) / sizeof(arr[2]);
//    shunxuSearch(arr, 4, len);
/***二分法查找的递归与非递归的测试*/
//    cout<<"No recursive:"<<endl;
//    cout<<"position:"<<BinarySearch(arr, 13, 6)<<endl;
//    cout<<"recursive:"<<endl;
//    cout<<"position:"<<BinarySearchDiGui(arr, 0, 12, 6)<<endl;
/***测试数据，一个整数数组，一个数组大小k***/
    int a[]={76,98,109,86,67,190,80,12,14,89,1};
//    int k=sizeof(a)/sizeof(a[0]);
/***直接插入算法测试***/
    SortFunctions sortFunctions;
//    sortFunctions.insertSort(a,k);
/***希尔排序算法测试***/
    //定义待排序的一维数组
    int array[] = { 1, 3, 4, 5, 2, 6, 10, 9, 8, 7 };
    //输出原始数组
    cout << "原始数组是：" << endl;
    print(array, 10);
    //对数组进行排序
    int count = sortFunctions.shellSort(array, 10);
    //输出排序后的数组
    cout << "排序后的数组是：" << endl;
    print(array, 10);
    cout << "共交换" << count << "次" << endl;
    return 0;
}
