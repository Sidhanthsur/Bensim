#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
/*****************************************************************************
/* What this code does ?
Generates a Bensim Graph based on the given computational complexity and the communicational
complexity given by the user.
*/
/******************************************************************************
/*Things TO-DO :
1.Add classes such as Graph_Algorithms , Numeric_Algorithms etc as and when the algorithms
are added and call accordingly to give a mix of the algorithms.
2.The algorithm selection isn't random. Make it Random.
3.Define proper computational complexity and communicational complexity of the
various algorithms in terms of generic expressions
*/
/*******************ADD ALGORITHMS AND ID'S HERE*************************************
/*

  ID  ALGORITHMS
  0   Matrix_Multiplication
  1   Matrix_Inverse
  2   Matrix_Determinant
  3   Matrix_LUD
  4   Euler

*/



/*******************************************Global declaration **************************/
int Total_Computational_Complexity[10];//Each i value is a specific algorithm
int Total_Communicational_Complexity[10];
int k;
int Graph_Components[4];
//******************************************************************************************


/*
Add all Marix algorithms here.
When adding a Algorithm function say Matrix_Multiplication then make sure
1.Total_Computation_Complexity[i] is defined
2.Total_Communication_COmplexity[i] is defined
3. The 'i' signifies the id of the algorithm
*/


class Matrix_Algorithms
{
  int Order_Of_Matrix;
public:

  Matrix_Algorithms(int x)//Make it such a way that user defines it somewhere else
  {

    Order_Of_Matrix=x;//The Order_Of_Matrix is obtained.
 }



  int Computational_Complexity[4];//{+,-,*,/}
  int Communicational_Complexity[2];//{MOV,Depth_Level,Data_Set_size}
//  int Total_Computational_Complexity[10];
  //int Total_Communicational_Complexity[10];
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
  void Matrix_Determinant()
  {
    Total_Computational_Complexity[2]=300;
    Total_Communicational_Complexity[2]=450;

  }
  void Matrix_LUD()
  {
    Total_Computational_Complexity[3]=300;
    Total_Communicational_Complexity[3]=300;
  }

};
/* Add the graph algorithms here
Like the matrix algorithms make sure you deifne the complexities
*/

class Graph_Algorithms
{
  int Number_Of_Nodes;
public:
  Graph_Algorithms()
  {
    Number_Of_Nodes=0;
  }
  void Euler()
  {
    Total_Computational_Complexity[4]=30;
    Total_Communicational_Complexity[4]=15;
  }

};
/* This is the class that computes the various algorithms and generates the
graph.
After generation it displays the grpah
*/


class Algorithms
{
public:

  void Compute(int User_Computational,int User_Communicational)
  {
    k=0;

    int Calculated_Computational_Complexity=0;
    int Calculated_Communicational_Complexity=0;
/************IMPORTANT*******************************************

If any new algorithms are added then make sure the final value in the
following for loop is also updated
*****************************************************************/
    for(int i=0;i<5;i++)
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
    cout<<"\n\n GRAPH \n\n";
    for(int i=0;i<k;i++)
    {
      /*******************IMPORTANT**********************
      If a new algorithm is added then make sure
      in the switch statement create:
      case id:
      cout<<"Algorithm_Name";
      break;
      *******************************************************/
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
        case 4:
        cout<<"Euler\n";
        break;


      }
    }
}
};



int main()
{

/************Object declaration*****************/
Matrix_Algorithms Object_1(3);
Graph_Algorithms Object_2;
Algorithms Algo_Object;
/***********************************************/


/*****************Important********************

After every new entry of a algorithm make sure the
method is called

**********************************************/




/**************MATRIX METHODS*******************/
Object_1.Matrix_Multiplication();
Object_1.Matrix_Inverse();
Object_1.Matrix_Determinant();
Object_1.Matrix_LUD();

/*************************************************/


/*************GRAPH METHODS********************/
Object_2.Euler();


/**********************************************/

/************COMPUTING , GENERATING AND DISPLAYING THE BENSIM GRAPH*******/
Algo_Object.Compute(100,100);
Algo_Object.Display();

/******************************************************************/
return 0;
}
