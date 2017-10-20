//
// Created by stanwang on 2017/9/29.
//

#ifndef LEARNCODING_ORDER_H
#define LEARNCODING_ORDER_H


class Order {


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
};


#endif //LEARNCODING_ORDER_H
