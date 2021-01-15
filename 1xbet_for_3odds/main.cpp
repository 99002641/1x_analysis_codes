#include <iostream>
#include "be_header.h"
#include <bits/stdc++.h>

using namespace std;
int ser=0;
void calculate(double N1, double N2,double N3, double r1, double r2,double r3);
void print_out(double n1,double n2,double n3,double a1,double a2,double a3,double r1,double r2,double r3,int i,int k,int j);

int main()
{double n1,n2,n3,T1=0.00,T2=0.00,T3=0.00;
    double cn1=0.00,cn2=0.00,cn3=0.00;
    int choice,amount,bchoice;
       list<Myheader> thelist;
       list<Myheader>::iterator iter;


       while(1)
       {cout<<"\n 1.ADD bets:\n 2.equalize current bet\n 3.show all green options\n4.EXIT\n\n";
           cin>>bchoice;
           switch (bchoice) {

           case 1 :{  cout << "\nEnter three odds=" << endl;
               cin>>n1>>n2>>n3;
               cout<<"\n Enter choice->(1/2/3):";
               cin>>choice;
               cout<<"\nEnter amount=";
               cin>>amount;


                Myheader temp(n1,n2,n3,amount,choice);
                thelist.push_back(temp);
                T1=0.00;
                T2=0.00;
                T3=0.00;


               for(iter=thelist.begin();iter!=thelist.end();++iter)
               { T1+=(iter->r1);
                 T2+=(iter->r2);
                 T3+=(iter->r3);

               }
               cout<<"\n===========================================================================================================================\n";
               cout<<"Final Result:\n\n";

               cout<<"\t\t"<<T1;
               cout<<"\t\t| \t\t"<<T2;
                cout<<"\t\t| \t\t"<<T3;
               cout<<"\n\n\n";


           } break;

           case 3: cout<<"Enter Current odds:\n";
               cin>>cn1>>cn2>>cn3;
               cout<<"\n\n Possible cominations (To get both side green)***********************************************************************************################################################################\n";
               cout<<"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
               calculate(cn1,cn2,cn3,T1,T2,T3);
               break;
           case 4: exit(0);
           default:{cout<<"Invalid choice\n";
               break;}

           }

       }




    return 0;
}

void calculate(double N1, double N2,double N3, double r1, double r2,double r3)
{ double R1=0.00,R2=0.00,R3=0.00,diff=100000.00,tempAM1=0.00,tempAM2=0.00,tempAM3=0.00; int temp=0;
int i,j,k,flag=0;
    if(r1>0)
        temp+=r1;
    if(r2>0)
        temp+=r2;
    if(r3>0)
        temp+=r3;

    if(r1>0 && r2>0 && r3>0)
        cout<<"\n\nAlready all are green\n";
 //cout<<"\ntesting 1\\\\";

    //cout<<temp;
    for(i=0;i<=temp;i++)
    {
        for(j=0;j<=temp-i;j++)
    {

            k =temp - i -j ;
            R1=N1*i -temp;
            R2=N2*k -temp;
            R3=N3*j -temp;
            //cout<<"\ntesting 2\\\\";
            if((R1+r1)>0 && (R2+r2)>0 &&(R3+r3)>0)
            { flag=1;
                if((abs((R1+r1)-(R2+r2))+abs((R2+r2)-(R3+r3))+abs((R3+r3)-(R1+r1))<diff))
                {tempAM1=i; tempAM2=k;tempAM3=j;
                diff=(abs((R1+r1)-(R2+r2))+abs((R2+r2)-(R3+r3))+abs((R3+r3)-(R1+r1)));}
             print_out(N1,N2,N3,r1,r2,r3,R1+r1,R2+r2,R3+r3,i,k,j);
             //cout<<"\ntesting 3\\\\";
            }

           }}
    if(flag==1)
   {cout<<"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    cout<<"\nBest possible(and safe) combination:\n";
    cout<<"\n"<<tempAM1<<"\t"<<tempAM2<<"\t"<<tempAM3<<"\n";
     print_out(N1,N2,N3,r1,r2,r3,tempAM1*N1-temp+r1,tempAM2*N2-temp+r2,tempAM3*N3-temp+r3,tempAM1,tempAM2,tempAM3);
     cout<<"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
}
    if(flag==0)
          cout<<"\n No possible combinations to get both side green:\n";




}





void print_out(double n1,double n2,double n3,double a1,double a2,double a3,double r1,double r2,double r3,int i,int k,int j)
{
    cout<<"\n\n\n\n";


    cout<<"\n===================================================================================================================================================================================================\n";
        cout<<"\n Serial Number = "<<++ser;
        cout<<"\n------------------------------------------------------------------------------------------------------\n";
    cout<<"Current odds=>\n\t"<<n1<<"\t"<<n2<<"\t"<<n3<<"\n";
     cout<<"Amount to put on sides:=>\n\t"<<i<<"\t"<<k<<"\t"<<j<<"\n";
     cout<<"Amount obtained on sides after deduction :=>\n\t"<<(n1*i)-(i+k+j)<<"\t"<<(n2*k)-(i+k+j)<<"\t"<<(n3*j)-(i+k+j)<<"\n";
    cout<<"Previous Outcomes :\n\t"<<a1<<"\t"<<a2<<"\t"<<a3<<"\n";
    cout<<"\n------------------------------------------------------------------------------------------------------\n";
    cout<<"Final combined Outcome (both side green):\n";
    cout<<"\t"<<r1<<"\t"<<r2<<"\t"<<r3<<"\n\n";








}
