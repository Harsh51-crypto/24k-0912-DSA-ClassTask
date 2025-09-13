#include <vector>
#include <iostream>
using namespace std;

int main()
{

   int **arr;
   int rows;
   cout << "Enter the Rows: " << endl;
   cin >> rows;

   arr = new int *[rows];
   int col[rows];
   for (int i = 0; i < rows; ++i)
   {
      int cols;
      cout << "Enter the size for team: " << i + 1 << endl;
      cin >> cols;
      col[i] = cols;
      arr[i] = new int[cols];

      cout << "Enter the Score for team: " << i + 1 << endl;
      for (int j = 0; j < cols; ++j)
      {
         cin >> arr[i][j];
      }
   }

   for (int i = 0; i < rows; ++i)
   {
      for (int j = 0; j < col[i]; ++j)
      {
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }  
   cout<<endl<<"Displaying Elements: "<<endl;

   for (int i = 0; i < rows; ++i)
   {
      int sum = 0;
      for (int j = 0; j < col[i]; ++j)
      {
         sum += arr[i][j];
      }
      cout << "Sum of Row:" << i + 1 << " is " << sum << endl;
   }

   for (int i = 0; i < rows; ++i)
   {
      delete[] arr[i];
   }
   delete[] arr;
}