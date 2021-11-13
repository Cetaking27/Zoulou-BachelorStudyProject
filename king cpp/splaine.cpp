#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n=5; i; j; double h;
    double *X=new double [n];
    double *Y=new double [n];
    cout<<"X:\n";
    for(i=0; i<n; i++)
        cin>>X[i];
    cout<<"Y:\n";
    for(i=0; i<n; i++)
        cin>>Y[i];
    h=X[1]-X[0];
    double *Q=new double [n];
    double *D=new double [n];
    double *A=new double [n];
    double *B=new double [n];
    double *C=new double [n];
    double *a=new double [n];
    double *b=new double [n];
    Q[0]=0;Q[4]=0;
    for(i=1;i<n-1;i++)
    D[i]=((Y[i+1]-Y[i])/h)-((Y[i]-Y[i-1])/h);
    A[1]=0;A[2]=h/6;A[3]=(h+h)/3;
    B[1]=h/6;B[2]=(h+h)/3;B[3]=0;
    C[1]=h/6;C[2]=(h+h)/3;C[3]=0;
    for(i=1;i<n-1;i++)
        {cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<" "<<D[i];
    cout<<endl;}
    a[1]=-C[1]/B[1];
    a[2]=-C[2]/(B[2]+A[2]-a[1]);
    a[3]=-C[3]/(B[3]+A[3]-a[2]);
    b[1]=(-D[1])/(B[1]);
    b[2]=(-D[2]-A[2]*b[1])/(B[2]+A[2]*a[1]);
    b[3]=(-D[3]-A[3]*b[2])/(B[3]+A[3]*a[2]);
    for(i=1;i<n-1;i++)
        cout<<"a"<<i<<"="<<a[i]<<" "<<"b"<<i<<"="<<b[i]<<endl;
    Q[3]=b[3];
    Q[2]=a[2]*Q[3]+b[2];
    Q[1]=a[1]*Q[2]+b[1];
    for(i=0;i<n;i++)
        cout<<"Q"<<i<<"="<<Q[i]<<endl;
    for(i=1;i<n-1;i++)
        cout<<"S"<<i<<"[x]="<<Q[i]/6*h<<"(x-"<<X[i-1]<<")+"<<Q[i]*(Y[i-1]/h-Q[i-1]/6)<<X[i]<<"(x-"<<")+"<<Y[i]/6-Q[i]/6<<"(x-"<<X[i-1]<<")"<<endl;
    system("pause");
    return 0;
}