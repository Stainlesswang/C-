#include <iostream>
using namespace std;
bool fi = false;
//˳�����
void shunxuSearch(int array[], int key, int len) {

    for (int i = 0; i < len; i++) {
        if (key == array[i]) {
            fi = true;
            cout << "�ҵ���" << i + 1 << "��" << array[i] << endl;
        }

    }
    if (!fi) {
        cout << len << "���޴�ֵ" << endl;
    }

}
/* ���ַ������㷨
 * ��Ҫ˼����� ÿ�κ�mindֵ�Ƚϣ�
 * �������Ĳ����������д�С�������е�����
 * ����mind�����������Ϊmid+1 --- array.length
 * С��mind ������Ϊ0 ��mid-1��
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
//�ݹ���ַ�����
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



