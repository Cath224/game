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

struct roslina katalog[10] =
{
    {"beetroot", 8, 6,9},
    {"radish", 4, 3,5},
    {"carrot", 8, 5,9},
    {"parsley", 12, 10, 25},
    {"leek", 10, 7, 12},
    {"dill", 2, 2, 3},
    {"celery", 10, 8, 14},
    {"cabbage", 6, 4,7},
    {"cauliflower", 10, 7,11},
    {"spinach", 6, 5, 10},

};

void nachalo()
{

    printf("Welcome to BUSSINESSFARM\n");
    printf("\nYou are a farmer and your money is counted in zuras(Zr);\nat the start you have 50.00 Zr and your goal is to earn more through selling your plants.\nyou have ");
    printf("8 weeks for that, after this time the game ends\n");

}

void wyswietl_katalog(struct roslina* kat)
{
    printf("\n(prices in the catalog don't include discounts/profits)\n\n");
    printf("name        growth in days  price in the shop  price on the market\n");
    printf("beetroot    8               6.00 Zr            9.00 Zr\n");
    printf("radish      4               3.00 Zr            5.00 Zr\n");
    printf("carrot      8               5.00 Zr            9.00 Zr\n");
    printf("parsley     12              10.00 Zr           25.00 Zr\n");
    printf("leek        10              7.00 Zr            12.00 Zr\n");
    printf("dill        2               2.00 Zr            3.00 Zr\n");
    printf("celery      10              8.00 Zr            14.00 Zr\n");
    printf("cabbage     6               4.00 Zr            7.00 Zr\n");
    printf("cauliflower 10              7.00 Zr            11.00 Zr\n");
    printf("spinach     6               5.00 Zr            10.00 Zr\n\n");



}

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

void zbieranie_komunikat(struct plon* ekw, struct roslina* kat, int n)
{
    printf("You collected:\n");
    int i = 0, flag = 0;
    for (i; i < n; i++)
    {
        if (ekw[i].nowe > 0)
        {
            printf("%d x %s\n", ekw[i].nowe, kat[i].nazwa);
            ekw[i].nowe = 0;
            flag = 1;
        }
    }
    if (flag == 0)
        printf("none");
    printf("\n\n");
}

void sow_proverka(int* ekw, struct blok* pol, int n, int id) // proverka polya
{
    int i = 0;
    while (n > 0)
    {
        if (pol[i].stan == 0)
        {
            pol[i].id = id;
            pol[i].stan++;
            pol[i].dni = 0;
            ekw[id]--;
            n--;
        }

        i++;
        if (i == 50 && n > 0)
        {
            "You don't have a place to sow more seeds";
            break;
        }
    }
}

int main()
{
    srand(time(NULL));
    nachalo();
    int heh;

}
