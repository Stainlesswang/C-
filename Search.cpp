#include <iostream>
using namespace std;
bool fi = false;
//顺序查找
void shunxuSearch(int array[], int key, int len) {

    for (int i = 0; i < len; i++) {
        if (key == array[i]) {
            fi = true;
            cout << "找到第" << i + 1 << "个" << array[i] << endl;
        }

    }
    if (!fi) {
        cout << len << "查无此值" << endl;
    }

}
/* 二分法查找算法
 * 主要思想就是 每次和mind值比较，
 * 传进来的参数必须是有从小到大排列的数组
 * 大于mind则区间区间变为mid+1 --- array.length
 * 小于mind 则区间为0 到mid-1；
 * */
int BinarySearch(int *array, int size, int key){
    if ( array == NULL || size==0)
        return -1;
    int low=0;
    int height=size-1;
    int mid=0;

    while (low<=height){
        mid=(low+height)/2;
        if (array[mid]<key)
            low=mid+1;
        else if (array[mid]>key)
            height=mid-1;
        else
            return mid;
    }
    return -1;

}
//递归二分法查找
int BinarySearchDiGui(int *array,int low,int height, int key){

    if(low>height)
        return -1;

    int mid=(low+height)/2;
    if(array[mid]==key)
        return mid;
    else if (key>array[mid])
        return BinarySearchDiGui(array,mid+1,height,key);
    else
        return BinarySearchDiGui(array,low,mid-1,key);

}



