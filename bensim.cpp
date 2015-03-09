#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

class Algorithms
{
  int Order_Of_Matrix;
public:

  Algorithms(int x)
  {

    Order_Of_Matrix=x;
 }

  int k;
  int Graph_Components[4];
  int Computational_Complexity[4];//{+,-,*,/}
  int Communicational_Complexity[2];//{MOV,Depth_Level,Data_Set_size}
  int Total_Computational_Complexity[10];
  int Total_Communicational_Complexity[10];
  void Matrix_Multiplication()
  {
    Total_Computational_Complexity[0]= pow((Order_Of_Matrix),2);
    Total_Communicational_Complexity[0]=10;
  }
  void Matrix_Inverse()
  {
    Total_Computational_Complexity[1]=30;
    Total_Communicational_Complexity[1]=30;
  }
  void Sample()
  {
    Total_Computational_Complexity[2]=300;
    Total_Communicational_Complexity[2]=450;

  }
  void Sample2()
  {
    Total_Computational_Complexity[3]=30;
    Total_Communicational_Complexity[3]=30;
  }
void Compute(int User_Computational,int User_Communicational)
{
  k=0;

  int Calculated_Computational_Complexity=0;
  int Calculated_Communicational_Complexity=0;
  for(int i=0;i<4;i++)
  {
    if(Calculated_Computational_Complexity + Total_Computational_Complexity[i] <= User_Computational && Calculated_Communicational_Complexity + Total_Communicational_Complexity[i] <= User_Communicational)
    {
      Graph_Components[k]=i;
      k++;
      Calculated_Computational_Complexity += Total_Computational_Complexity[i];
      Calculated_Communicational_Complexity += Total_Communicational_Complexity[i];
    }

  }
}
void Display()
{
  for(int i=0;i<k;i++)
  {
    switch (Graph_Components[i])
    {
      case 0:
      cout<<"Matrix Multiplication\n";
      break;

      case 1:
      cout<<"Matrix Inverse\n";
      break;
      case 2:
      cout<<"Sample\n";
      break;
      case 3:
      cout<<"Sample1\n";
      break;


    }
  }
}

};



int main()
{
Algorithms Object_1(3);
Object_1.Matrix_Multiplication();

cout<<Object_1.Total_Computational_Complexity[0];
cout<<"\n\n now it starts \n";
Object_1.Matrix_Inverse();
Object_1.Sample();
Object_1.Sample2();
Object_1.Compute(100,100);
Object_1.Display();
return 0;
}
