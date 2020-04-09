#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono; 
int main()
{
    
    const int n = 250000;
    const int dim = ((10 * n) / 3);
    int c = 0;
    int i, j, k, resto, digant, nueves, aux;
    vector<int> pi(dim+1);
    auto start = high_resolution_clock::now();

    for (i = 1; i <= dim; i++)
        pi[i] = 2;
    nueves = 0;
    digant = 0;
    for (i = 0; i <= n; i++)
    {
        resto = 0;
        for (j = dim; j >= 1; j--)
        {
            aux = 10 * pi[j] + resto * j;
            pi[j] = aux % (2 * j - 1);
            resto = aux / (2 * j - 1);
        }
        pi[1] = resto % 10;
        resto = resto / 10;
        if (resto == 9)
            nueves++;
        else if (resto == 10)
        {

            for (k = 1; k <= nueves; k++)
               
            digant = 0;
            nueves = 0;
        }
        else
        {

          
            digant = resto;
            if (nueves != 0)
            {
                for (k = 1; k <= nueves; k++)
                  
                nueves = 0;
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<minutes>(stop - start);
    cout << "Tiempo para calcular "<<n<<" dígitos de pi: "
         << duration.count() << "minutos" << endl;


    return 0;
}