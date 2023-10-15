#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Point2DClass
{
private:
    float x, y;

public:
    /*Phuong thuc khoi tao*/
    Point2DClass(float _x = 0, float _y = 0);   // co tham so
    Point2DClass(const Point2DClass &geometry); // sao chep

    /*Getter-Setter*/
    void setGeometry(float xAfter, float yAfter);
    float getGeometry();

    /*Phuong thuc xu ly*/
    float getOrdinate();                                              // lay x
    float getAbscissa();                                              // lay y
    float calDistance(Point2DClass geometry, Point2DClass geometry2); // tinh khoang cach giua 2 diem
    float findSymmetryPoint();                                        // tim diem doi xung

    // Phuong thuc nhap - xuat
    void enterGeometry();
    void exportGeometry();
    /*Phuong thuc huy*/
    ~Point2DClass();
};

int main()
{
    // Point2DClass g1(1, 2);
    // Point2DClass g2(5, 7);
    // Point2DClass g3;
    // // Lay gia tri x, y cua g1
    // cout << g1.getOrdinate() << " " << g1.getAbscissa() << endl;
    // // gan lai gia tri cho g1
    // g1.setGeometry(2.7, 4.65);
    // g1.getGeometry();
    // // xuat g1
    // g1.exportGeometry();
    // // Tinh khoang cach giua g1 va g2
    // cout << g3.calDistance(g1, g2) << endl;
    // // tim diem doi xung cua g2
    // g2.findSymmetryPoint();
    // g2.exportGeometry();

    // Nhap - Xu Ly - Xuat
    Point2DClass g1;
    g1.enterGeometry();
    g1.exportGeometry();
    Point2DClass g2;
    g2.enterGeometry();
    g2.exportGeometry();
    Point2DClass gResult;
    cout << "Khoang giua 2 diem g1 va g2 la: " << gResult.calDistance(g1, g2) << endl;
    cout << "g2 doi xung qua Ox" << endl;
    g2.findSymmetryPoint();
    cout << "Khoang giua 2 diem g1 va g2 la: " << gResult.calDistance(g1, g2);

    system("pause");
    return 0;
}

/*Dinh Nghia Ham*/

// Ham khoi tao
Point2DClass::Point2DClass(float _x, float _y)
{
    x = _x;
    y = _y;
}
Point2DClass::Point2DClass(const Point2DClass &geometry)
{
    x = geometry.x;
    y = geometry.y;
}

// Getter-Setter
void Point2DClass::setGeometry(float xAfter, float yAfter)
{
    x = xAfter;
    y = yAfter;
}
float Point2DClass::getGeometry()
{
    return x, y;
}

// Ham lay x, y
float Point2DClass::getOrdinate()
{
    return x;
}
float Point2DClass::getAbscissa()
{
    return y;
}

// Ham tinh khoang cach giua 2 diem
float Point2DClass::calDistance(Point2DClass geometry, Point2DClass geometry2)
{
    // can binh phuong x2 - x1 + binh phuong y2 - y1
    // roumd (x * 100) / 100, lam tron 2 chu so thap phan
    return round(sqrt(pow(geometry2.x - geometry.x, 2) + pow(geometry2.y - geometry.y, 2)) * 100) / 100;
}

// Ham tim diem doi xung
float Point2DClass::findSymmetryPoint()
{
    int n = 0;
    cout << "0 (doi xung qua O), 1 (doi xung qua Ox), 2 (Doi xung qua Oy)" << endl;
    cout << "Tim diem doi xung qua ";
    cin >> n;
    switch (n)
    {
    case 0:
        x = x * -1;
        y = y * -1;
        break;
    case 1:
        x = x * -1;
        break;
    case 2:
        y = y * -1;
        break;
    default:
        cout << "Nhap sai!!!" << endl;
        break;
    }
    return x, y;
}

// Ham nhap - xuat
void Point2DClass::enterGeometry()
{
    cout << "Nhap vao toa do x, y" << endl;
    cout << "Hoanh do (x): ";
    cin >> x;
    cout << "Tung do (y): ";
    cin >> y;
}
void Point2DClass::exportGeometry()
{
    cout << "Toa do x, y: (" << x << "," << y << ")" << endl;
    // setprecision(3) << fixed
}

// Ham Huy
Point2DClass::~Point2DClass()
{
}
