#include "SortFunctions.h"
#include <iostream>
using namespace std;

/*�������һά����ĺ���*/
void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main() {
/***˳����Ҳ���***/
//    int arr[] = {1, 23, 5, 45, 2, 54};
//    int len = sizeof(arr) / sizeof(arr[2]);
//    shunxuSearch(arr, 4, len);
/***���ַ����ҵĵݹ���ǵݹ�Ĳ���*/
//    cout<<"No recursive:"<<endl;
//    cout<<"position:"<<BinarySearch(arr, 13, 6)<<endl;
//    cout<<"recursive:"<<endl;
//    cout<<"position:"<<BinarySearchDiGui(arr, 0, 12, 6)<<endl;
/***�������ݣ�һ���������飬һ�������Сk***/
    int a[]={76,98,109,86,67,190,80,12,14,89,1};
//    int k=sizeof(a)/sizeof(a[0]);
/***ֱ�Ӳ����㷨����***/
    SortFunctions sortFunctions;
//    sortFunctions.insertSort(a,k);
/***ϣ�������㷨����***/
    //����������һά����
    int array[] = { 1, 3, 4, 5, 2, 6, 10, 9, 8, 7 };
    //���ԭʼ����
    cout << "ԭʼ�����ǣ�" << endl;
    print(array, 10);
    //�������������
    int count = sortFunctions.shellSort(array, 10);
    //�������������
    cout << "�����������ǣ�" << endl;
    print(array, 10);
    cout << "������" << count << "��" << endl;
    return 0;
}
