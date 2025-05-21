
//in this we create an vector (thats what is acalled a sieve) which contains a bunch of boolean values of n size 
//telling if something is true or false in this case if values are prime or not 

//Then we look at the prime number and mark all its multiple as 


class Solution {
public:


    int countPrimes(int n) {
        if(n ==0) return 0;

        vector<bool> prime(n,true);
        prime[0] = prime[1] = false;

        int ans = 0;

        for(int i =2;i<n;i++)
            {
                if(prime[i])
                    {
                        ans++;
                    }
                int j =2*i;
                while(j<n){
                    prime[j] = false;
                    j+=i; //we junp aged based on i ..so if i is 2 we jump forward 2 
                }
            }
        return ans;
    }
};


///////How do we optimize this algo ?

1. the inner while loop ...
    works like this 2*2  3*3  -> these to total the same number ...and we actually traverse the same indexes 
                    2*3  3*4   
                    2*4  3*5

    To fix this j = i*i 
2.Optimization 2 outer loop 



    vector<bool> Sieve(int n)
{
    // create a sieve array telling isPrime till 'n'
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    /*for (int i = 2; i <= n; i++)*/
    for (int i = 2; i * i <= n; i++) // Optimisation 2: (Outer loop):
                                     // if i becomes > sqrt(N), then the
                                     // inner loop does not work.
    {
        if (sieve[i] == true)
        {
            // means, sieve[i] is Prime and mark its multiples
            //  as non-prime.
            /*int j = i * 2;*/
            int j = i * i; // Optimisation 1 (inner loop):
                           // first unmarked number would be i*i
                           // as, other have been marked by 2 to (i - 1).
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}