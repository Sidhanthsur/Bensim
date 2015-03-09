#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
/* What this code does ?
Generates a Bensim Graph based on the given computational complexity and the communicational
complexity given by the user.
*/
/*Things TO-DO :
1.Add classes such as Graph_Algorithms , Numeric_Algorithms etc as and when the algorithms
are added and call accordingly to give a mix of the algorithms.
2.The algorithm selection isn't random. Make it Random.
3.Define proper computational complexity and communicational complexity of the
various algorithms
*/

class Matrix_Algorithms
{
  int Order_Of_Matrix;
public:

  Algorithms(int x)//Make it such a way that user defines it somewhere else
  {

    Order_Of_Matrix=x;//The Order_Of_Matrix is obtained.
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
Matrix_Algorithms Object_1(3);
Object_1.Matrix_Multiplication();


Object_1.Matrix_Inverse();
Object_1.Sample();
Object_1.Sample2();
Object_1.Compute(100,100);
Object_1.Display();
return 0;
}
