#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 56

struct roslina
{
    char nazwa[20];
    int czas;
    int cena_kup;
    int cena_sprzedaj;
};
struct day
{
    int pogoda;
    short targ;
    short sklep;
    int los1;
    int los2;
};


struct plon
{
    int szt;
    int nowe;
};

struct blok
{
    int id;
    int stan;
    int dni;
};

void wypelnienie_dni(struct day* tab, int end)
{
    int i = 0;
    for (i; i < end; i++)
    {
        int a = rand() % 10;
        if (a < 6)
        {
            tab[i].pogoda = 0;
        }
        else if (a < 8)
        {
            tab[i].pogoda = 1;
        }
        else
        {
            tab[i].pogoda = 2;
        }

        if ((i % 7) == 1 || (i % 7) == 3)
        {
            tab[i].targ = 1;
        }
        else
        {
            tab[i].targ = 0;
        }

        if ((i % 7) > 4)
        {
            tab[i].sklep = 0;
        }
        else
        {
            tab[i].sklep = 1;
        }

        tab[i].los1 = rand() % 10;
        tab[i].los2 = rand() % 10;

    }
}

void prognoz(struct day* tab, int i)
{

    if (tab[i].pogoda == 0)
    {
        printf("sun\n");
    }
    else  if (tab[i].pogoda == 1)
    {
        printf("rain\n");
    }
    else
    {
        printf("storm\n");
    }

}

void kakoy_den(int a)
{
    if (a % 7 == 0) printf("Monday");
    else if (a % 7 == 1) printf("Tuesday");
    else if (a % 7 == 2) printf("Wednesday");
    else if (a % 7 == 3) printf("Thursday");
    else if (a % 7 == 4) printf("Friday");
    else if (a % 7 == 5) printf("Saturday");
    else printf("Sunday");
}

int main()
{

}
