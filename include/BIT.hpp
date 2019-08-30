//
// Created by cre-chan on 19-8-30.
//

#ifndef BIT_BIT_HPP
#define BIT_BIT_HPP

#include <iostream>
#include <type_traits>

using namespace std;

template<class number>
class BinaryIndexedTree {
    number *content;
    uint length;

    uint lowbit(uint arr_index) {
        int natural_index = arr_index + 1;
        return natural_index & (-natural_index);
    }

public:

    friend ostream &operator<<(ostream &out, const BinaryIndexedTree<number> &bit) {
        for (int i = 0; i < bit.length; i++) out << bit.content[i] << " ";

        return out;
    }

    template<uint len>
    BinaryIndexedTree(const number (&arr)[len]):content(new number[len]), length(len) {
        uint i = 0;
        number sum = 0;
        do {
            sum += arr[i];
            content[i] = sum;
        } while (++i < len);

        for (i = 1; i < length; i++) {

            number accum = i < lowbit(i) ? 0 : content[i - lowbit(i)];
            content[i] -= accum;
        }
    }

    number query(uint l,uint r){
        uint lower_bound=r+1-lowbit(r);

        if(l<lower_bound)
            return  content[r]+query(l,lower_bound-1);
        else if (l>lower_bound)
            return  content[r]-query(lower_bound,l-1);
        else
            return content[r];
    }

    void update(uint index,typename make_signed<number>::type delta){
        if(index>=length)
            return;

        content[index]+=delta;
        update(index+lowbit(index),delta);
    }
};


#endif //BIT_BIT_HPP
