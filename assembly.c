#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct
{
    double x;
    double y;
} koordinata;


char load_place;
int tarolo, szalag, t = 0.1, szamlalo = 0, vegso_ido = 0, szalag_t[5], tarolo_t[5];
koordinata honnan, hova;


double ido_mozg(double ds)
{
    double dt = ds / 5000;
    return dt;
}

double x_y_tav_max(koordinata honnan, koordinata hova)
{
    koordinata tav;
    tav.x = abs(hova.x - honnan.x);
    tav.y = abs(hova.y - honnan.y);
    if (tav.x > tav.y)
    {
        return tav.x;
    }
    return tav.y;
}


int load()
{
    while(scanf("%d %d", &szalag, &tarolo) == 2)
    {
        if (szamlalo == 0)
        {
            
        }
        
        hova.x = -500;
        hova.y = 300 * szalag;
    }   
}

int place()
{

}

int futas(char load_place)
{

}



int main()
{
    honnan.x = 0;
    honnan.y = 0;
    while (scanf("%c", &load_place) == 1)
    {
        if (load_place == 'L')
        {
            
        }
        else if (load_place == 'P')
        {
            
        }
        else
        {
            return 0;
        }
        szamlalo++;
        vegso_ido += t;   
    }

    hova.x = -500;
    hova.y = -300;
    double tav = x_y_tav_max(honnan, hova);
    double time = ido_mozg(tav);
    printf("%lf %lf", time, tav);
    return 0;
}