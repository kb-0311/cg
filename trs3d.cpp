#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    double x, y, z;
} Point;

const Point sqr[] = {
    {15, 45, 10},
    {15, 80, 10},
    {125, 80, 10},
    {125, 45, 10}};

double tr_matrix[][4] = {
    {1, 0, 0, 200},
    {0, 1, 0, 10},
    {0, 0, 1, 1}};

double sc_matrix[][4] = {
    {2, 0, 0, 0},
    {0, 3, 0, 0},
    {0, 0, 5, 1}};

// sin30 = 0.5
// cos30 = 0.866
// rotation about z axis
double rt_matrix[][4] = {
    {0.866, 0.5, 0, 0},
    {-0.5, 0.866, 0, 0},
    {0, 0, 1, 1}};

Point matrixmultiplication(double m[][4], Point v)
{

    double arr[] = {v.x, v.y, v.z, 1}, ans[] = {0, 0, 0, 1};
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            ans[i] += m[i][j] * arr[j];
        }
    }
    Point p = {ans[0], ans[1], ans[2]};
    return p;
}

void init()
{
    const int xshift = 300;
    const int yshift = 300;
    // original
    cout << "Original coordinates" << endl;
    cout << "[";
    for (int i = 0; i < 4; ++i)
    {
        if (i != 3)
            cout << sqr[i].x << " " << sqr[i].y << sqr[i].z << endl;
        else
        {
            cout << sqr[i].x << " " << sqr[i].y << sqr[i].z << "]" << endl;
        }
    }

    cout << endl
         << "After translation" << endl;
    cout << "[";
    for (int j = 0; j < 4; ++j)
    {
        Point p = matrixmultiplication(tr_matrix, sqr[j]);
        if (j != 3)
            cout << p.x << " " << p.y << p.z << endl;
        else
            cout << p.x << " " << p.y << p.z << "]";
    }

    cout << endl
         << "After scaling" << endl;
    cout << "[";
    for (int k = 0; k < 4; ++k)
    {
        Point p = matrixmultiplication(sc_matrix, sqr[k]);
        if (k != 3)
            cout << p.x << " " << p.y << p.z << endl;
        else
            cout << p.x << " " << p.y << p.z << "]";
    }

    cout << endl
         << "After rotation" << endl;
    cout << "[";
    for (int l = 0; l < 4; ++l)
    {
        Point p = matrixmultiplication(rt_matrix, sqr[l]);
        if (l != 3)
            cout << p.x << " " << p.y << p.z << endl;
        else
            cout << p.x << " " << p.y << p.z << "]";
    }
}

int main()
{
    init();
}
