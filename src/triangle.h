//
// Created by Omar Shaikh on 2/23/16.
//

#ifndef HW3_TRIANGLE_H
#define HW3_TRIANGLE_H
/** Header file for the class Triangle. */

#include <vector>
#include <cmath>
#include <iostream>
#include "triangle_interface.h"


using namespace std;

template<class T>
class Triangle : public triangleInterface<T> {

private:
    T tSide1;
    T tSide2;
    T tSide3;

public:
    Triangle();

    Triangle(T side1, T side2, T side3);

    void setSides(T side1, T side2, T side3);

    std::vector<T> getSides() const;

    T getArea() const;

    T getPerimeter() const;

    bool isRightTriangle() const;

    bool isEquilateral() const;

    bool isIsosceles() const;

};//end triangle

template<class T>
Triangle<T>::Triangle() {
    tSide1 = 1;
    tSide2 = 1;
    tSide3 = 1;
}

template<class T>
Triangle<T>::Triangle(T side1, T side2, T side3) {
    tSide1 = side1;
    tSide2 = side2;
    tSide3 = side3;
}

template<class T>
void Triangle<T>::setSides(T side1, T side2, T side3){
    tSide1 = side1;
    tSide2 = side2;
    tSide3 = side3;
}

template<class T>
std::vector<T> Triangle<T>::getSides() const{
    std::vector<T> sides (3);
    sides[0] = tSide1;
    sides[1] = tSide2;
    sides[2] = tSide3;
    return sides;
}

template<class T>
T Triangle<T>::getArea() const{
    T s = (tSide1 + tSide2 + tSide3) / 2;
    T area = sqrt(s * (s - tSide1) * (s - tSide2) * (s - tSide3));
    return area;
}

template<class T>
T Triangle<T>::getPerimeter() const{
    return tSide1 + tSide2 + tSide3;
}

template<class T>
bool Triangle<T>::isRightTriangle() const{
    return tSide1 * tSide1 == tSide2 * tSide2 + tSide3 * tSide3 ||
   tSide2 * tSide2 == tSide1 * tSide1 + tSide3 * tSide3 ||
   tSide3 * tSide3 == tSide2 * tSide2 + tSide1 * tSide1;
}

template<class T>
bool Triangle<T>::isEquilateral() const{
    return tSide1 == tSide2 && tSide2 == tSide3 && tSide1 == tSide3;
}

template<class T>
bool Triangle<T>::isIsosceles() const{
    return (tSide1 == tSide2 && tSide2 != tSide3) || (tSide2 == tSide3 && tSide3 != tSide1) || (tSide1 == tSide3 && tSide3 != tSide2);
}

#endif //HW3_TRIANGLE_H
