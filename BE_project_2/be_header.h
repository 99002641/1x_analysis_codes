#ifndef BE_HEADER_H
#define BE_HEADER_H
#include <bits/stdc++.h>
using namespace std;
class Myheader
{
public:
     int amount,choice;
    double n1,n2,a1=0.00,a2=0.00,r1=0.00,r2=0.00;


    Myheader(double a,double b,int c,int d)
        :n1(a),n2(b),amount(c),choice(d)
    {
        generate();
        print_it();

    }
    void generate()
    {
        if(choice==1)
        {
            a1=n1*amount;
            a2=0;
        }
        else if(choice==2)
        {
            a2=n2*amount;
            a1=0;
        }
        else if(choice!=2 && choice!=1)
        {
            cout<<"\nWrong choice dude\n";
        }

        r1=a1-amount;
        r2=a2-amount;
    }

    void print_it()
    {cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\t";
        cout<<"\nODDS:\n"<<"\t\t"<<n1<<"\t\t|"<<"\t\t"<<n2<<"\n";
        cout<<"\nAmount if won:\n\t\t"<<a1<<"\t\t|"<<"\t\t"<<a2<<"\n";
        cout<<"\n------------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\n NET amount:\n"<<"\t\t"<<r1<<"\t\t|"<<"\t\t"<<r2<<"\n";
    }

};

#endif // BE_HEADER_H
