//
// Created by stanwang on 2017/10/10.
//
#ifndef LEARNCODING_SORTFUNCTIONS_H
#define LEARNCODING_SORTFUNCTIONS_H

#include <iostream>
using namespace std;
class SortFunctions {
    //ֱ�Ӳ�������
public:void insertSort(int a[], int n) {

        int i, j;
        for (i = 1; i < n; i++)
            for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
                swap(a[j], a[j + 1]);


        for (int f = 0; f < n; f++)
               cout << a[f] << "  ";
    };
    //ֱ�Ӳ������򷽷�2
public:void insertSort2(int a[], int k) {

        int i,j;
        for (i = 1; i < k; i++)//ѭ���ӵ�2��Ԫ�ؿ�ʼ
        {
            cout << " �� " << i << "��ѭ����" << endl;
            if (a[i] < a[i - 1]) {
                int temp = a[i];
                for (j = i - 1; j >= 0 && a[j] > temp; j--) {
                    cout << " �� " << j << "����λ��ѭ����" << endl;
                    a[j + 1] = a[j];
                }
                cout << " ��ʱ�Ĳ���λ��Ϊ " << j + 1 << endl;
                a[j + 1] = temp;//�˴�����a[j+1]=temp;
            }
        }
        for (int f = 0; f < k; f++) {
            cout << a[f] << "  ";
        }

    };
    //����ֱ�Ӳ������򣬽����Ҳ���λ�ò��ö��ֲ��ң�ֻ�Ǽ����˲��Ҵ�����ʱ�临�Ӷ���Ϊ0��n^2��
public:void binaryInsertSort(){

    };

    /*���ֲ��Һ��������ز����±�*/
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
//������Ҳ�������
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
                int insertIndex = BinarySearch(array, 0,i-1, array[i]);//ʹ�ö��ֲ��������������н��в��ң���ȡ�����±�
                for (j = i - 1; j>=insertIndex; j--) //�ƶ�Ԫ��
                {
                    array[j + 1] = array[j];
                }
                array[insertIndex] = temp;    //����Ԫ��
            }
        }
    }
    //ϣ�����򣨶�ֱ�Ӳ��뷨�ĸĽ���
    // 1.��Ϊֱ�Ӳ��뷨�����д��������ʱ�������ƶ��Ĳ���
    // 2.ֱ�Ӳ���������������ٵ�����Ч�ʽϸ�
    //���������������ǲ�����ϣ�����򣬲����ɴ�С�ļ�����������з�Ϊ��ͬ��С���У��𽥼�С�����1����������Ч��
/*ϣ���������˼�룺
��ȡһ��С��n������d1��Ϊ��һ�����������ļ���ȫ����¼���顣
���о���Ϊd1�ı����ļ�¼����ͬһ�����С�
���ڸ����ڽ���ֱ�Ӳ�������
Ȼ��ȡ�ڶ�������d2<d1�ظ������ķ��������ֱ����ȡ������  =1(<��<d2<d1)�������м�¼����ͬһ���н���ֱ�Ӳ�������Ϊֹ��
*/

/*�������һά����ĺ���*/
    void print(int array[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
/*
һ�ֲ��ұȽϲ����ͼ�¼�ƶ���������ؽ��еķ�����
����������
�����������¼R[i]�Ĺؼ��ִ��������������������м�¼R[j](j=i-1��i-2������1)�Ĺؼ��ֽ��бȽϣ�
 ���� ��R[j]�Ĺؼ��ִ���R[i]�Ĺؼ��֣���R[j]����һ��λ�ã�
   ����R[j]�Ĺؼ���С�ڻ����R[i]�Ĺؼ��֣�����ҹ��̽�����j+1��ΪR[i]�Ĳ���λ�á�
  ���ؼ��ֱ�R[i]�Ĺؼ��ִ�ļ�¼���Ѻ��ƣ�����j+1��λ���Ѿ��ڿգ�ֻҪ��R[i]ֱ�Ӳ����λ�ü������һ��ֱ�Ӳ�������

   */
public:int shellSort(int array[], int n)
    {
        //�����������¼��������
        int count = 0;
        //�����м��������Ϊ��ʱ��������
        int temp;
        //�������飨��������
        cout << "��ʼ���������������..." << endl;
        //�����ʼ����ֵ
        int gap = n;
int k=0;


        do{
            //��ʼ�����仯����
            gap = gap / 3 + 1;

            //�ӵ�ǰ��gapλ��������
            for (int i = gap; i < n; i++)
            {
                for (int j = i; j >= gap; j-=gap)
                {
                    if (array[j] < array[j - gap])
                    {
                        temp = array[j];
                        array[j] = array[j - gap];
                        array[j - gap] = temp;
                        cout << array[j] << "��" << array[j - gap] << "������" << endl;
                        //�����ʱ�����˳��
                        cout << "�����ʱ��˳���ǣ�";
                        print(array, 10);
                        //ÿ����һ�Σ���¼����1
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }

            }
        } while (gap>1);
        cout << "�������������..." << endl;
        return count;
    }




































};


#endif //LEARNCODING_SORTFUNCTIONS_H
