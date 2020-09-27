#include<iostream>
using namespace std;

//PRIME SIEVE & OPTIMISATIONS

long long int p[10000005] = {0};

void primeSieve(long long int n)
{
    p[0] = p[1] = 0;
    p[2] = 1;

    //Let us mark all odd numbers as Prime(Initialisations)
    for(long long int i=3;i<=n;i+=2)
    {
        p[i] = 1;
    }
    //Sieve Login to mark non prime numbers as 0
    //1.Optimisation : Iterate only over odd numbers
    for(long long int i=3;i<=n;i+=2)
    {
        if(p[i]){
            //Mark all the multiples of that numbers as non-prime.
            //2. Optimisation Take a jump of 2i starting fom i*i
            for(long long int j=i*i;j<=n;j+=2*i)
            {
                p[j] = 0;
            }
        }
    }
    return ;
}
int main()
{
    primeSieve(10000000);
    for(long long int i=0;i<=10000000;i++)
    {
        if(p[i])
            cout<<i<<" ";
    }
    return 0;
}
