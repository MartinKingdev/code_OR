#include<iostream>
#include<math.h>

using namespace std;


double f(double x, double y){
    return x*y;
}

double** methodeEuler(double a, double b, int n){
    double** Mat;
    Mat = new double*[2];
    for (int i = 0; i < 2; i++)
    {
        Mat[i] = new double[n+1];
    }
    Mat[0][0] = 0.0;
    Mat[1][0] = 1.0;
    for (int i = 1; i < n+1; i++)
    {
        Mat[0][i] = a+i*(b-a)/n;
        Mat[1][i] = Mat[1][i-1]+f(Mat[0][i-1],Mat[1][i-1])*(Mat[0][i]-Mat[0][i-1]);
    }
    return Mat;
}

int main(){
    double** A = methodeEuler(0,1,10);
    cout << "|-------|-------" << endl;
    for (int i = 0; i <= 10; i++)
    {
        cout << "|  " << A[0][i] << " | " << A[1][i] << "   " << endl;
    }
    cout << "|---------------" << endl;
}