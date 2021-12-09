#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <bits/stdc++.h>

#define NUM 1000000

//Random number generator program
long int Random_Number_Generator()
{
    long int rand1 = std::rand();
    return rand1;
}

//GCD using Euclids algorithm
long int GCD_Euclids_Algorithm(long int a, long int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return GCD_Euclids_Algorithm(a % b, b);
    return GCD_Euclids_Algorithm(b % a, a);
}

int main()
{
    long int rand1,rand2, gcd;
    long long result=0;
    double probability, pi;
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (long long int i=1; i <= NUM; i++)
    {
        rand1= Random_Number_Generator();
        rand2=Random_Number_Generator();
        gcd = GCD_Euclids_Algorithm(rand1,rand2);
        if (gcd == long(1))
        {
            result++; 
        }
     }

     probability = float(result) / NUM;
     pi = sqrt(6.0 /probability);

     printf("\nTotal samples Taken                  : %lu", NUM);
     printf("\nRandom numbers generated with GCD 1  : %lu", result);
     printf("\nProbability                          : %f", probability);
     printf("\nPi value                             : %f", pi);
     return 0;
}