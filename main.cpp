#include <iostream>
#include <BIT.hpp>

uint some_number[]={1,2,3,4,5};

int main() {
    BinaryIndexedTree<uint> a(some_number);
    cout<<a<<endl;

    cout<<a.query(1,1)<<endl;
    a.update(2,-1);
    cout<<a.query(0,4)<<endl;
    return 0;
}