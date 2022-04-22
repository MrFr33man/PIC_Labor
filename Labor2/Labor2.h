//
// Created by fabia on 14.04.2022.
//

#ifndef PIC_LABOR_LABOR2_H
#define PIC_LABOR_LABOR2_H


class Labor2 {
public:
    Labor2(int const &x, int const &y);
    void SetX(int const &x);
    int GetX() const;       // Ausschließlich Lesezugriff
    void SetY(int const &y);
    int GetY() const;
private:
    int _x, _y;
};


#endif //PIC_LABOR_LABOR2_H
