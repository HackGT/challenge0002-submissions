
#include <iostream>
#include "architecture.h"
#include "matrix.h"
#include "conditionals.h"
#include "loops.h"

using namespace std;

void x86()
{
    cout << "Running on x86 architecture..." << endl;
}

void x64()
{
    cout << "Running on x64 architecture..." << endl;
}

int main()
{
    If<Architecture<>::value == 32>::run(x86, x64);

    cout << "Printing 10 items:" << endl;
    ForLoop<0, 1, 10>::execute();

    Matrix<int, 3, 3> a, b, c;
    Matrix<float, 2, 2> d, e, f;
    Matrix<int, 3, 2> g, h, i;

    a.SetMatrix({{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}});
    b.SetMatrix({{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}});

    cout << "Adding Matrix A and B:" << endl;
    c = a + b;


    h.SetMatrix({{{1, 2}, {4, 5}, {7, 8}}});

    cout << "Dimension of A and H Matrix is: " << endl;
    cout << a.GetNumRows() << " x " << a.GetNumCols() << endl;
    // cout << e.GetNumRows() << " x " << e.GetNumCols() << endl;
    cout << h.GetDim()[0] << " x " << h.GetDim()[1] << endl;

    cout << "Multiplying Matrix A and H:" << endl;
    g = a * h;
    g.Show();

    cout << "New Matrix Dimension after multiplying A and H is: " << endl;
    cout << g.GetDim()[0] << " x " << g.GetDim()[1] << endl;

    d.SetIdentityMatrix();
    e.SetOnes();

    d.Show();
    e.Show();
    cout << "Adding Matrix D and E:" << endl;
    f = d + e;
    f.Show();

    cout << "Subtracting Matrix D and E:" << endl;
    f = d - e;
    f.Show();

    cout << ((a == b) ? "Matrix A is equal to B" : "Matrix A is not equal to B") << endl;

    return 0;
}
