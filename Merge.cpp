#include <iostream>

using namespace std;
int Merge(int Array[],int a, int b,int c)
{
    int n1,n2,i,j,k;
   
    n1=b-a+1;
    n2=c-b;
    int P[n1],Q[n2];
    
    for(i=0;i<n1;i++)
    {
        P[i]=Array[a+i];
    }
    
    for(j=0;j<n2;j++)
    {
        Q[j]=Array[b+j+1];
    }
    i=0,j=0;
    
    for(k=a;i<n1&&j<n2;k++)
    {
        if(P[i]<Q[j])
        {
            Array[k]=P[i++];
        }
        else
        {
            Array[k]=Q[j++];
        }
    }
    
    while(i<n1)
    {
        Array[k++]=P[i++];
    }
 
    while(j<n2)
    {
        Array[k++]=Q[j++];
    }
}

int MergeSort(int Array[],int a,int c)
{
    int b;
    if(a<c)
    {
        b=(a+c)/2;
        MergeSort(Array,a,b);
        MergeSort(Array,b+1,c);
        Merge(Array,a,b,c);
    }
}
int main()
{
    int n;
    cout<<"Enter size of the Array: ";
    cin>>n;
    int Array[n],i;
    cout<<"Enter array values:\n";
    for(i=0;i<n;i++)
    cin>>Array[i];
 
    MergeSort(Array,0,n-1);
    cout<<"The Sorted List is\n";
    for(i=0;i<n;i++)
    {
        cout<<Array[i]<<" ";
    }
    return 0;
}
