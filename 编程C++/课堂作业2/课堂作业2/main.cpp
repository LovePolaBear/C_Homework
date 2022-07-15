#include <iostream>
using namespace std;

class Shape{
public:
    virtual double area() const {return 0.0;}
};

class Circle:public Shape{
public:
    Circle(){};
    Circle(double r):radius(r){}
    virtual double area() const {return 3.14159*radius*radius;}
private:
    double radius;
};

class Rectangle:public Shape{
public:
    Rectangle(){}
    Rectangle(double h,double w):height(h),width(w){}
    virtual double area() const {return width*height;}
private:
    double height;
    double width;
};

class Triangle:public Shape{
public:
    Triangle(){};
    Triangle(double w,double h):width(w),height(h){}
    virtual double area() const {return (width*height)/2;}
private:
    double width;
    double height;
};

int main(){
    Circle c1(12.6),c2(4.9);//建立Circle类对象c1,c2,参数为圆半径
    Rectangle r1(4.5,8.4),r2(5.0,2.5);//建立Rectangle类对象r1,r2,参数为矩形长、宽
    Triangle t1(4.5,8.4),t2(3.4,2.8); //建立Triangle类对象t1,t2，参数为三角形底边长与高
    Shape *pt[6]= {&c1,&c2,&r1,&r2,&t1,&t2}; //定义基类指针数组pt，使它每一个元素指向一个派生类对象
    double areas=0.0; //areas为总面积
    for(int i=0; i<6; i++){
        areas=areas + pt[i]->area();
    }
    cout<<"totol of all areas="<<areas<<endl;   //输出总面积
    return 0;
}
