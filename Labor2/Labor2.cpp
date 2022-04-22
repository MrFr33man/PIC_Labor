//
// Created by fabia on 14.04.2022.
//

#include "Labor2.h"


Labor2::Labor2(int const &x, int const &y) : _x {x}, _y {y}{

}

void Labor2::SetX(int const &x) {
    this->_x = x;
}

int Labor2::GetX() const {
    return this->_x;
}

void Labor2::SetY(int const &y) {
    this->_y = y;
}

int Labor2::GetY() const {
    return this->_y;
}