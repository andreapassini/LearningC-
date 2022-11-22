#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
/*
    Creare un programma che permetta ad un alunno di:
    - inserire 10 voti 
    - calcolare la media.
*/

    // inserire 10 voti
    //      array
    //      for
    int i;
    int A[10];
    for(i=0;i<10;i++)
    {
        cout<<"inserisci il voto "<<i+1<<endl;
        cin>>A[i];
    }
    
    // calcolare la media
    //      somma dei voti
    //          dividere per 10
    int som = 0;
    int media;
    for(i=0;i<10;i++)
    {
        som += A[i];
    }
    media=som/10;
    cout<<"la media dei voti e' "<<media<<endl;
    
    return 0;
}
