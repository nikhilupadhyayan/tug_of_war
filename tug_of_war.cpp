/*
Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the difference of the sum of two
subsets is as minimum as possible. If n is even, then sizes of two subsets must be strictly n/2 and if n is odd, then
size of one subset must be (n-1)/2 and size of other subset must be (n+1)/2.
*/
#include<iostream>
#include<climits>
using namespace std;

void find_sum(int *a,int *divider,int n,int &min_sum,int* final_divider)
{
    int temp_sum=0;
    for(int i=0;i<n;++i)
    {

        if(divider[i])
        {

           temp_sum+=a[i];
        }
        else
            temp_sum-=a[i];
    }
    if(temp_sum<0)
        temp_sum=0-temp_sum;

    if(temp_sum<min_sum)
    {
        min_sum=temp_sum;
        for(int i=0;i<n;++i)
        final_divider[i]=divider[i];
    }
}
int equally_divided(int* divider,int n)
{
    int count=0;
    int res=1;
    for(int i=0;i<n;++i)
    {
        if(divider[i])
            count++;

    }
    if((n&1))//odd n
    {
        if(count!=(n+1)/2)
            res=0;

    }
    else
    {
        if(count!=n/2)
            res=0;
    }
    return res;
}

void getSubset_util(int*a,int* divider,int n ,int &min_sum,int pos,int* final_divider)
{
    for(int i=0;i<2;++i)
    {
        divider[pos]=i;

        if(pos==n)
        {
            if(equally_divided(divider,n))
            {
                find_sum(a,divider,n,min_sum, final_divider);
            }
        }
        else
            getSubset_util(a,divider,n,min_sum,pos+1,final_divider);

    }
}

void getSubset(int* a , int n)
{
    int final_divider[n];
    int divider[n];
    int min_sum=INT_MAX;
    int pos=0;

    getSubset_util(a,divider,n,min_sum,pos,final_divider);
    cout<<"Min_difference: "<<min_sum<<endl;
     cout<<"set 1: ";
    for(int i=0;i<n;++i)
    {
        if(final_divider[i])
            cout<<a[i]<<"    ";
    }
         cout<<endl<<"set 2: ";

     for(int i=0;i<n;++i)
    {
        if(!final_divider[i])
            cout<<a[i]<<"    ";
    }
}

int main()
{
    int a[]={23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n=sizeof(a)/sizeof(a[0]);

    getSubset(a,n);
}
