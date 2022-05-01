#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
using namespace std;

int main()
{
    /* the idea is simple, we take a vector with values, after that, we arrange the same vector in increasing order. After each "cycle", the new
    matrix will be displayed. until all is done.
    We can have a Sleep function, preferably. A "system("cls") is mandatory
    */
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, 15);
    int vec[10],i,j,aux,targetvec[10];
    bool ProgramRunning=true,MatrixSorted;
    char mat[10][10];
        for(i=1;i<=10;i++)
            {
                cout<<"vec["<<i<<"]=";cin>>vec[i];
            }
    system("cls");

    for(i=1;i<=10;i++)
        targetvec[i]=i;
    for(i=1;i<=10;i++)
        for(j=1;j<=10;j++)
            mat[i][j]='0';

    while(ProgramRunning==true)
    {
    cout<<"Welcome to matrix sorter!"<<endl;
    for(i=1;i<=10;i++)
        if(vec[i]!=targetvec[i])
            MatrixSorted=false;
        if(MatrixSorted==false)
        {
          for(i=1;i<=10;i++)
            for(j=10;j>=10-vec[i];j--)
                mat[i][j]='2';
        }
        for(i=1;i<=10;i++)
        for(j=i+1;j<=10;j++)
        {
        if(vec[i]>vec[j])
            {
          aux=vec[i];
          vec[i]=vec[j];
          vec[j]=aux;
            }
        }
    for(i=1;i<=10;i++)
    {
    cout<<endl;
        for(j=1;j<=10;j++)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout<<mat[i][j]<<"  ";
                SetConsoleTextAttribute(hConsole, 15);
            }
    }
    getch();
    system("cls");
    }



    return 0;
}
