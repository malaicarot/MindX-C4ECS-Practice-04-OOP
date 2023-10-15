#include <iostream>
// #include <bits/stdc++.h>
#include <math.h>

using namespace std;
class FractionClass
{
private:
    float numer, denomin;

public:
    // Getter - Setter
    void setFraction(float numer, float denomin);
    float getFraction();
    // Phuong thuc khoi tao
    FractionClass(float _numer = 1.0, float _denomin = 1.0); // khoi tao co tham so
    FractionClass(const FractionClass &fraction);            // khoi tao sao chep

    // Ham lay tu so va mau so
    float getValueOfNumerator();
    float getValueOfDenominator();

    // Ham xu ly
    float simplifyingAFractions();                                           // rut gon phan so
    float inverseFraction();                                                 // tim phan so nghich dao
    float plusFraction(FractionClass fraction, FractionClass fraction2);     // + 2 phan so
    float subtractFraction(FractionClass fraction, FractionClass fraction2); // - 2 phan so
    float multiFraction(FractionClass fraction, FractionClass fraction2);    // * 2 phan so
    float divisionFraction(FractionClass fraction, FractionClass fraction2); // / 2 phan so

    // Ham nhap - xuat
    void enterFraction();
    void exportFraction();

    // Ham huy
    ~FractionClass();
};

int main()
{
    FractionClass fraction(15, 6);
    FractionClass fraction2(24, 1);
    FractionClass fraction3;
    FractionClass fraction4;
    FractionClass fractionResult;
    // cout << fraction.getValueOfNumerator() << "/" << fraction.getValueOfDenominator() << endl;
    // cout << fraction2.getValueOfNumerator() << "/" << fraction2.getValueOfDenominator() << endl;

    // gan gia tri
    // fraction.setFraction(3, 7);
    // cout << fraction.getValueOfNumerator() << "/" << fraction.getValueOfDenominator() << endl;

    // rut gon phan so
    // fraction2.simplifyingAFractions();
    // cout << fraction2.getValueOfNumerator() << "/" << fraction2.getValueOfDenominator() << endl;

    // phan so nghich dao
    // fraction2.inverseFraction();
    // cout << fraction2.getValueOfNumerator() << "/" << fraction2.getValueOfDenominator() << endl;

    // Nhap - xuat
    // fraction3.enterFraction();
    // fraction3.exportFraction();
    // fraction4.enterFraction();
    // fraction4.exportFraction();

    // // Tinh toan 2 phan so
    // fractionResult.plusFraction(fraction3, fraction4);     // +
    // cout << "Tong hai phan so la ";
    // fractionResult.exportFraction();
    // fractionResult.subtractFraction(fraction3, fraction4); // -
    // fractionResult.multiFraction(fraction3, fraction4);    // *
    // fractionResult.divisionFraction(fraction3, fraction4); // /
    fraction3.exportFraction();
    system("pause");
    return 0;
}

/*Dinh ngia ham*/

// Ham khoi tao
FractionClass::FractionClass(float _numer, float _denomin)
{
    numer = _numer;
    denomin = _denomin;
    if (denomin == 0)
    {
        cout << "Value does not exist" << endl;
        numer = 0;
        denomin = 0;
    }
}
FractionClass::FractionClass(const FractionClass &fraction)
{
    numer = fraction.numer;
    denomin = fraction.denomin;
}

// Ham lay tu so va mau so
float FractionClass::getValueOfNumerator()
{
    return numer;
}
float FractionClass::getValueOfDenominator()
{
    return denomin;
}

// Getter-Setter
void FractionClass::setFraction(float numerAfter, float denominAfter)
{
    numer = numerAfter;
    denomin = denominAfter;
}
float FractionClass::getFraction()
{
    return numer, denomin;
}

// Ham xu li
float calGCD(float a, float b) // tim uoc chung lon nhat
{
    if (a * b == 0)
        return a + b;
    while (a != b)
    {
        (a > b) ? a -= b : b -= a;
    }
    return a;
}

float FractionClass::simplifyingAFractions() // rut gon phan so
{
    float GCD = calGCD(numer, denomin);
    numer /= GCD;
    denomin /= GCD;
    return numer, denomin;
}
float FractionClass::inverseFraction() // phan so nghich dao
{
    if (numer == 0)
        return numer, denomin;
    numer += denomin;
    denomin = numer - denomin;
    numer -= denomin;
    return numer, denomin;
}

float FractionClass::plusFraction(FractionClass fraction, FractionClass fraction2) // + 2 phan so
{

    numer = (fraction.numer * fraction2.denomin) + (fraction2.numer * fraction.denomin);
    denomin = fraction.denomin * fraction2.denomin;
    simplifyingAFractions();
    // cout << "Tong hai phan so la: " << numer << "/" << denomin << endl;
    return numer, denomin;
}

float FractionClass::subtractFraction(FractionClass fraction, FractionClass fraction2) // - 2 phan so
{
    // Phai rut gon truoc vi co the ra so am
    fraction.simplifyingAFractions();
    fraction2.simplifyingAFractions();
    numer = (fraction.numer * fraction2.denomin) - (fraction2.numer * fraction.denomin);
    denomin = fraction.denomin * fraction2.denomin;
    // simplifyingAFractions();
    cout << "Hieu hai phan so la: " << numer << "/" << denomin << endl;
    return numer, denomin;
}

float FractionClass::multiFraction(FractionClass fraction, FractionClass fraction2) // * 2 phan so
{
    numer = fraction.numer * fraction2.numer;
    denomin = fraction.denomin * fraction2.denomin;
    simplifyingAFractions();
    cout << "Tich hai phan so la: " << numer << "/" << denomin << endl;

    return numer, denomin;
}

float FractionClass::divisionFraction(FractionClass fraction, FractionClass fraction2) // / 2 phan so
{
    fraction2.inverseFraction();
    numer = fraction.numer * fraction2.numer;
    denomin = fraction.denomin * fraction2.denomin;
    simplifyingAFractions();
    cout << "Thuong hai phan so la: " << numer << "/" << denomin << endl;
    return numer, denomin;
}
// Ham nhap - xuat
void FractionClass::enterFraction()
{
    do
    {
        cout << "Nhap vao tu so: ";
        cin >> numer;
        cout << "Nhap vao mau so: ";
        cin >> denomin;
        if (denomin == 0)
        {
            cout << "Mau so khong the bang 0! Vui long nhap lai mau" << endl;
        }
    } while (denomin == 0);
}
void FractionClass::exportFraction()
{
    if (denomin == 1)
    cout << "Phan so: " << numer << endl;
    else
    cout << "Phan so: " << numer << "/" << denomin << endl;
}
// Ham Huy
FractionClass::~FractionClass()
{
}
