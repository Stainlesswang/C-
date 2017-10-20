//
// Created by stanwang on 2017/10/10.
//
#ifndef LEARNCODING_SORTFUNCTIONS_H
#define LEARNCODING_SORTFUNCTIONS_H

#include <iostream>
using namespace std;
class SortFunctions {
    //直接插入排序
public:void insertSort(int a[], int n) {

        int i, j;
        for (i = 1; i < n; i++)
            for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
                swap(a[j], a[j + 1]);


        for (int f = 0; f < n; f++)
               cout << a[f] << "  ";
    };
    //直接插入排序方法2
public:void insertSort2(int a[], int k) {

        int i,j;
        for (i = 1; i < k; i++)//循环从第2个元素开始
        {
            cout << " 第 " << i << "大循环！" << endl;
            if (a[i] < a[i - 1]) {
                int temp = a[i];
                for (j = i - 1; j >= 0 && a[j] > temp; j--) {
                    cout << " 第 " << j << "调整位置循环！" << endl;
                    a[j + 1] = a[j];
                }
                cout << " 此时的插入位置为 " << j + 1 << endl;
                a[j + 1] = temp;//此处就是a[j+1]=temp;
            }
        }
        for (int f = 0; f < k; f++) {
            cout << a[f] << "  ";
        }

    };
    //二分直接插入排序，将查找插入位置采用二分查找，只是减少了查找次数，时间复杂度认为0（n^2）
public:void binaryInsertSort(){

    };

    /*二分查找函数，返回插入下标*/
    template <typename T>
    int BinarySearch(T array[], int start, int end, T k)
    {
        while (start <= end)
        {
            int middle = (start + end) / 2;
            int middleData = array[middle];
            if (middleData > k)
            {
                end = middle - 1;
            }
            else
                start = middle + 1;
        }
        return start;
    }
//二叉查找插入排序
    template <typename T>
    void InsertSort(T array[], int length)
    {
        if (array == nullptr || length < 0)
            return;
        int i, j;
        for (i = 1; i < length; i++)
        {
            if (array[i]<array[i - 1])
            {
                int temp = array[i];
                int insertIndex = BinarySearch(array, 0,i-1, array[i]);//使用二分查找在有序序列中进行查找，获取插入下标
                for (j = i - 1; j>=insertIndex; j--) //移动元素
                {
                    array[j + 1] = array[j];
                }
                array[insertIndex] = temp;    //插入元素
            }
        }
    }
    //希尔排序（对直接插入法的改进）
    // 1.因为直接插入法当数列大致有序的时候会减少移动的步骤
    // 2.直接插入排序对数量较少的序列效率较高
    //根据以上两点我们产生了希尔排序，采用由大到小的间隔将整个数列分为不同的小序列，逐渐减小间隔至1以提高排序的效率
/*希尔排序基本思想：
先取一个小于n的整数d1作为第一个增量，把文件的全部记录分组。
所有距离为d1的倍数的记录放在同一个组中。
先在各组内进行直接插入排序；
然后，取第二个增量d2<d1重复上述的分组和排序，直至所取的增量  =1(<…<d2<d1)，即所有记录放在同一组中进行直接插入排序为止。
*/

/*定义输出一维数组的函数*/
    void print(int array[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
/*
一种查找比较操作和记录移动操作交替地进行的方法。
具体做法：
　将待插入记录R[i]的关键字从右向左依次与有序区中记录R[j](j=i-1，i-2，…，1)的关键字进行比较：
 　① 若R[j]的关键字大于R[i]的关键字，则将R[j]后移一个位置；
   ②若R[j]的关键字小于或等于R[i]的关键字，则查找过程结束，j+1即为R[i]的插入位置。
  　关键字比R[i]的关键字大的记录均已后移，所以j+1的位置已经腾空，只要将R[i]直接插入此位置即可完成一趟直接插入排序。

   */
public:int shellSort(int array[], int n)
    {
        //定义变量，记录交换次数
        int count = 0;
        //定义中间变量，做为临时交换变量
        int temp;
        //遍历数组（进行排序）
        cout << "开始对数组进行排序了..." << endl;
        //定义初始增量值
        int gap = n;
int k=0;


        do{
            //初始增量变化规律
            gap = gap / 3 + 1;

            //从当前的gap位置向后遍历
            for (int i = gap; i < n; i++)
            {
                for (int j = i; j >= gap; j-=gap)
                {
                    if (array[j] < array[j - gap])
                    {
                        temp = array[j];
                        array[j] = array[j - gap];
                        array[j - gap] = temp;
                        cout << array[j] << "和" << array[j - gap] << "互换了" << endl;
                        //输出此时数组的顺序
                        cout << "数组此时的顺序是：";
                        print(array, 10);
                        //每交换一次，记录数加1
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }

            }
        } while (gap>1);
        cout << "数组排序结束了..." << endl;
        return count;
    }




































};


#endif //LEARNCODING_SORTFUNCTIONS_H
