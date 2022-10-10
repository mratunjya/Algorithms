#include<stdio.h>
#include<math.h>
void scan();
void calc();
void print();
int a,b,c;
float d,e;
int main()
{ 
     scan();
     calc();
     print();
     return 0;

}
void scan()
{   
    printf("Enter The Value Of Co-efficient Of X^2,X And 1 Respectively \n");
    scanf("%d%d%d",&a,&b,&c);
}
void calc()
{ 
    d = (-b+sqrt((b*b) - (4*a*c)))/(2*a);
    e = (-b+sqrt((b*b) - (4*a*c)))/(2*a);
}
void print()
{
    printf("The Roots Of The Quadratic Equations Are %f And %f \n",d,e);
}
