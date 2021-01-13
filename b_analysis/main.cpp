#include <iostream>
int ser=0;
using namespace std;
void calculate(double,double,double,int);
void print_out(double,double,double,double,double,double,double,double,double);
int main()
{double n1,n2,n3;
    int Totalamount;
    cout << "Enter three odds=" << endl;
    cin>>n1>>n2>>n3;
    cout<<"Enter total amount=";
    cin>>Totalamount;
    calculate(n1,n2,n3,Totalamount);

    return 0;
}


void calculate(double n1,double n2,double n3,int Totalamount)
{
    for(int i=0;i<=Totalamount;i++)
    {
        for(int j=0;j<=(Totalamount-i);j++)
        {
            int k =Totalamount - i - j;


            print_out(n1,n2,n3,n1*i,n2*j,n3*k,n1*i-Totalamount,n2*j-Totalamount,n3*k-Totalamount);
        }
    }


}


void print_out(double n1,double n2,double n3,double a1,double a2,double a3,double r1,double r2,double r3)
{int profit=0,loss=0,equal=0;
    if(r1>0)
        profit++;
    else
        if(r1<0)
            loss++;
    else
            equal++;

    if(r2>0)
        profit++;
    else
        if(r2<0)
            loss++;
    else
            equal++;

    if(r3>0)
        profit++;
    else
        if(r3<0)
            loss++;
    else
            equal++;

    if(profit>2)
    {  cout<<"\n===================================================================================================================================================================================================\n";
        cout<<"\n Serial Number = "<<++ser;
        cout<<"\n------------------------------------------------------------------------------------------------------\n";
    cout<<"odds=>\n\t"<<n1<<"\t"<<n2<<"\t"<<n3<<"\n";
     cout<<"Amount Invested=>\n\t"<<a1/n1<<"\t"<<a2/n2<<"\t"<<a3/n3<<"\n";
    cout<<"Output amount if won:\n\t"<<a1<<"\t"<<a2<<"\t"<<a3<<"\n";
    cout<<"\n------------------------------------------------------------------------------------------------------\n";
    cout<<"Final RESULT:\n";
    cout<<"\t"<<r1<<"\t"<<r2<<"\t"<<r3<<"\n\n";





    cout<<"\nProfits:"<<profit;
     cout<<"\nLosses:"<<loss;
      cout<<"\nEquals:"<<equal;
      cout<<"\n\n Final RESULT:"<<r1+r2+r3;
}
}
