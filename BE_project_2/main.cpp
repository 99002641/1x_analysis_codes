#include <iostream>
#include "be_header.h"
#include <bits/stdc++.h>

using namespace std;
int ser=0;
void calculate(double N1,double N2,double r1,double r2);
void print_out(double n1,double n2,double a1,double a2,double r1,double r2,int i,int k);

int main()
{double n1,n2,T1=0.00,T2=0.00;
    double cn1=0.00,cn2=0.00;
    int choice,amount,bchoice;
       list<Myheader> thelist;
       list<Myheader>::iterator iter;


       while(1)
       {cout<<"\n 1.ADD bets:\n 2.equalize current bet\n 3.show all green options\n4.EXIT\n\n";
           cin>>bchoice;
           switch (bchoice) {

           case 1 :{  cout << "\nEnter two odds=" << endl;
               cin>>n1>>n2;
               cout<<"\n Enter choice->(1/2):";
               cin>>choice;
               cout<<"\nEnter amount=";
               cin>>amount;


                Myheader temp(n1,n2,amount,choice);
                thelist.push_back(temp);
                T1=0.00;
                T2=0.00;


               for(iter=thelist.begin();iter!=thelist.end();++iter)
               { T1+=(iter->r1);
                 T2+=(iter->r2);

               }
               cout<<"\n===========================================================================================================================\n";
               cout<<"Final Result:\n\n";

               cout<<"\t\t"<<T1;
               cout<<"\t\t| \t\t"<<T2;
               cout<<"\n\n\n";


           } break;

           case 3: cout<<"Enter Current odds:\n";
               cin>>cn1>>cn2;
               cout<<"\n\n Possible cominations (To get both side green)***********************************************************************************################################################################\n";
               cout<<"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
               calculate(cn1,cn2,T1,T2);
               break;
           case 4: exit(0);
           default:{cout<<"Invalid choice\n";
               break;}

           }

       }




    return 0;
}

void calculate(double N1, double N2, double r1, double r2)
{ double R1=0.00,R2=0.00,diff=0.00,tempAM1=0.00,tempAM2=0.00; int temp=0;
    if(r1>0)
        temp=r1;
    else if(r2>0)
        temp=r2;

    if(r1>0 && r2>0)
        cout<<"\n\nAlready both are green\n";
 //cout<<"\ntesting 1\\\\";

    //cout<<temp;
    for(int i=0;i<=temp;i++)
    {

            int k =temp - i ;
            R1=N1*i -temp;
            R2=N2*k -temp;
            //cout<<"\ntesting 2\\\\";
            if((R1+r1)>0 && (R2+r2)>0)
            {/* if(abs((R1+r1)-(R2+r2))>diff)
                {tempAM1=i; tempAM2=k;}
                diff=abs((R1+r1)-(R2+r2));*/
             print_out(N1,N2,r1,r2,R1+r1,R2+r2,i,k);
             //cout<<"\ntesting 3\\\\";
            }

           }
  /* cout<<"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    cout<<"\nBest possible(and safe) combination:\n";
     print_out(N1,N2,r1,r2,tempAM1*N1,tempAM2*N2);
     cout<<"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
*/



}






void print_out(double n1,double n2,double a1,double a2,double r1,double r2,int i,int k)
{cout<<"\n\n\n\n";


    cout<<"\n===================================================================================================================================================================================================\n";
        cout<<"\n Serial Number = "<<++ser;
        cout<<"\n------------------------------------------------------------------------------------------------------\n";
    cout<<"Current odds=>\n\t"<<n1<<"\t"<<n2<<"\t\n";
     cout<<"Amount to put on sides:=>\n\t"<<i<<"\t"<<k<<"\t\n";
     cout<<"Amount obtained on both sides after deduction :=>\n\t"<<(n1*i)-(i+k)<<"\t"<<(n2*k)-(i+k)<<"\t\n";
    cout<<"Previous Outcomes :\n\t"<<a1<<"\t"<<a2<<"\t\n";
    cout<<"\n------------------------------------------------------------------------------------------------------\n";
    cout<<"Final combined Outcome (both side green):\n";
    cout<<"\t"<<r1<<"\t"<<r2<<"\t\n\n";








}
