#include<iostream>
using namespace std;
class Matrix{

    public:
    int rows;
    int cols;
    int **arr;



    Matrix(int rows,int cols){

        this->rows=rows;
        this->cols=cols;


        arr=new int*[rows];

        for(int i=0;i<rows;++i){
            arr[i]=new int[cols];
        }



    }

void reSize(int newrows,int newcols){

    if(newrows!=rows || newcols!=cols){


        int **temp=new int*[rows];

        for ( int i = 0; i < rows; i++)
        {
        
            temp[i]=new int[cols];
        }


        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                temp[i][j]=arr[i][j];
            }
        }


      for(int i=0;i<rows;++i){
        delete[] arr[i];

      }
      delete [] arr;

      arr=new int*[newrows];

        for ( int i = 0; i < newrows; i++)
        {
        
            arr[i]=new int[cols];
        }

        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                arr[i][j]=temp[i][j];
            }
        }


         for(int i=0;i<rows;++i){
        delete[] temp[i];

      }
      delete [] temp;


        rows=newrows;
        cols=newcols;


    }



   
}

void transpose()
{

    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }


}


void print(){

    cout<<"Original Matrix: "<<endl;
    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){

            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

       cout<<"Matrix After adding 2 at odd index: "<<endl;

       for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){

            if(j%2!=0){
                arr[i][j]+=2;
            }
        }
       }
    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){

            
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

~Matrix(){

    for (int i = 0; i < rows; i++)
    {
        delete [] arr[i];
    }
    delete []arr;
    
}
};
int main(){

    int rows,cols;
    cout<<"Enter the Rows and colums: "<<endl;
    cin>>rows>>cols;

    Matrix m(rows,cols);

    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            cin>>m.arr[i][j];
        }
    }


    m.print();

    cout<<endl;

    m.transpose();
    cout<<"Transpose Matrix: "<<endl;
    m.print();

    return 0;
}
