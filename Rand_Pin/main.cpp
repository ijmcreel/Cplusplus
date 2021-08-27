#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <cmath>



using namespace std;

int main()
{
    int seed=time(0);
    int Nseed=0;
    int split=0;
    int SumOfBits=0;
    int Inc=0;
    int Nums=0;
    int Bits[16];
    int p=0;
    int steps=0;
    bool A=true;
    int SumOfSplit=0;

    //do{

    //split=Nseed%10;
    //SumOfSplit=SumOfSplit+split;


    //  }while(split>0);

    for(int i=0; i<16; i++)
        Bits[i]=0;

    do
    {

        for(int i=0; i<16; i++)
        {
            // sleep(1);
            seed=time(0);
            split=(seed%336)+101;

            seed=seed/split;
        }
        for(int i=0; i<split; i++)
        {
            seed=seed-(split*100);
//cout<<"split: "<<split<<" Seed: "<<seed<<endl;
//steps++;

        }
        steps=steps%10;
        if(seed<0)
        {
            seed=seed*-1;
            seed=seed+1;
        }
        Nums=seed/split;

        while(Nums!=1)
        {
            if(Nums%2>0)
            {
                Nums=(Nums*3)+1;
                Inc++;
            }
            while(Nums%2==0)
            {
                if(Nums%2==0)
                {
                    Nums=Nums/2;
                    Inc++;
                }
            }
        }
//cout<<"inc "<<Inc<<endl;
        Bits[p]=(Inc%2);
        p++;
        Inc=0;
        sleep(1);

        for(int i=15; i>0; i--)
        {
            cout<<Bits[i];
        }

        for(int i=0; i<=17; i++)
        {
            if(Bits[i]==1)
            {
                steps=pow(2,i);
                cout<<"\nSteps: "<<steps;
                SumOfBits=SumOfBits+steps;
            }

        }
        cout<<"\nPIN: "<<SumOfBits<<endl;

        p=0;
    }
    while(true);
    return 0;
}
