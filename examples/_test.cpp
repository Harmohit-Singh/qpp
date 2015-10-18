// Used for testing, do not use it as an example
#include <qpp.h>
#include <experimental/experimental.h>
// #include <MATLAB/matlab.h>
using namespace qpp;

// Future work
// TODO: Implement a circuit description language, load/save from/to file
// TODO: Write a MatrixView class, for multi-index lazy evaluation view - wip

cmat gettmp()
{
    cmat tmp(2, 2);
    tmp << 10, 20, 30, 40;
    return tmp;
}

int main()
{
    // testing qpp::experimental::MatrixView
    idx ROWS = 4, COLS = 4;
    cmat A = gt.CNOT;
    //A << 1, 2., 3., 4.;

    std::cout << "Initial:\n";
    std::cout << disp(A) << std::endl << std::endl;

    auto viewA = experimental::make_MatrixView(A, {1, 0});
    experimental::MatrixView<cmat> viewB = viewA;

    std::cout << "MatrixView: \n";
    std::cout << disp(viewA) << std::endl << std::endl;

    std::cout << "Copy via static_cast of the MatrixView:\n";
    cmat result = static_cast<cmat>(viewA); // convert
    std::cout << disp(result) << std::endl << std::endl;

    std::cout << "Copy MatrixView:\n";
    auto viewAcopy = viewA; // copy
    std::cout << disp(viewAcopy) << std::endl << std::endl;

    // rvalues should not bind

    // should not compile, and it doesn't :)
    // auto view_expression = experimental::make_MatrixView(A + A, {0, 1});
    // std::cout << disp(view_expression) << std::endl;

    // this line should not compile, and it doesn't :)
    // experimental::MatrixView<cmat> tmpview{gettmp(), {0, 1}};

}