#include <opencv2/core/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

static void
sample_creation()
{
    Mat A(2, 2, CV_8UC3, Scalar(0, 0, 255));
    Mat B;
    Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

    cout << endl << "sample_creation" << endl;
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
}

static void
sample_creation_by_static_method()
{
    Mat A = Mat::zeros(2, 2, CV_8U);
    Mat B = Mat::ones(3, 3, CV_32F);
    Mat C = Mat::eye(4, 4, CV_64F);

    cout << endl << "sample_creation_by_static_method" << endl;
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
}

static void
sample_shallow_copy()
{

    Mat A(2, 2, CV_8U, Scalar(0));
    Mat B = A;
    Mat C(A);

    A.at<unsigned char>(0, 0) = 255; // change (0, 0) from '0' to '255'

    cout << endl << "sample_shallow_copy" << endl;
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
}

static void
sample_deep_copy()
{
    Mat A(2, 2, CV_8U, Scalar(0));
    Mat B = A.clone();
    Mat C;
    A.copyTo(C);

    A.at<unsigned char>(0, 0) = 255; // change (0, 0) from '0' to '255'

    cout << endl << "sample_deep_copy" << endl;    
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
}

int
main(int argc, char *argv[])
{
    sample_creation();
    sample_creation_by_static_method();

    sample_shallow_copy();
    sample_deep_copy();

    return 0;
}
