//
// Created by yueshisheng on 2023/4/20.
//
#include<iostream>
using namespace std;
class base{
public:
    base(){

    }
    void print1(){
        cout<<"this is base print1"<<endl;
    }
    virtual void print2() {
        cout<<"this is base print2"<<endl;
    };
};
class derived:public base{
public:
    int diff=1000;
    void print1() {
        cout<<"this is derived print1"<<endl;
    }
    void print2() override{
        cout<<"this is derived print2"<<endl;
    }

};

int main(int argc){


    //base* base14= new derived;最重要的是based14这个指针指向derived，只是base的类型
    //理解复杂了，这些cast转换只是改变了指针类型，指针指向的对象不会改变。编译时多态会考虑指针的类型。运行态会考虑是否有虚函数
    base* base15= new derived;
    base15->print1();
    base15->print2();
    derived* d15=dynamic_cast<derived*>(base15);//只是改变一下指针类型，别的不影响
    d15->print1();
    d15->print2();
    derived* d16=new derived;
    base* b16=dynamic_cast<base*>(d16);
    b16->print1();
    b16->print2();
    cout<<d16->diff;







    derived d1;
    //static_cast静态转换,在编译时，发生转换，不能转换指针与非指针之间的转换，
    // 允许大类型转换为小类型,同时小类型可以转换为大类型
    double nums=10.8;
    int res1=10;
    double res2=static_cast<double>(res1);
    cout<<res2<<endl;
    int res=static_cast<int>(nums);
    cout<<res<<endl;
// 能子类转换为父类，也能父类转换为子类

    base* b1=static_cast<base*>(&d1);
    b1->print1();
    base* b2;
    derived* d2=static_cast<derived*>(b2);
    d2->print1();



    //const_cas在const和非cast、volatile和非volatile之间进行转换
    const int phone=100;
    int* temp=const_cast<int*>(&phone);
    *temp=111;
    cout<<*temp<<endl;











    return 0;

}
