#include <stdio.h>
#include <math.h>

enum sorszam {elso = 1, masodik, harmadik, negyedik, otodik};

typedef struct
{
    double x;
    double y;
} koordinata;


char load_place;
int tarolo, szalag, szalag_t[5] = {0, 0, 0, 0, 0};
double t = 0.1, vegso_ido = 0, x, y;
koordinata honnan, hova;


double ido_mozog(double ds)
{
    double dt = ds / 5000;
    return dt;
}

double x_y_tav_max_ido(koordinata honnan, koordinata hova)
{
    koordinata tav;
    tav.x = fabs(hova.x - honnan.x);
    tav.y = fabs(hova.y - honnan.y);
    if (tav.x > tav.y)
    {
        return ido_mozog(tav.x);
    }
    return ido_mozog(tav.y);
}

void load(int szalag, int tarolo)
{
    hova.x = -500;
    hova.y = 300 * szalag;
    vegso_ido += t + x_y_tav_max_ido(honnan, hova);
    honnan.x = hova.x;
    honnan.y = hova.y;
    szalag_t[szalag - 1]++;
}

void place(koordinata p_hova, int tarolo)
{
    vegso_ido += t + x_y_tav_max_ido(honnan, p_hova);
    honnan.x = p_hova.x;
    honnan.y = p_hova.y;
}

void kiiras()
{
    printf("Assembly time: %.2lf s\nPart usage\n", vegso_ido);

    for (int i = 0; i < 5; i++)
    {
        printf("\tTape %d: %d\n", i + 1, szalag_t[i]);   
    }
}

int main()
{
    honnan.x = 0;
    honnan.y = 0;
    while (scanf(" %c", &load_place) == 1)
    {
        if (load_place == 'L')
        {
            scanf("%d %d", &szalag, &tarolo);
            load(szalag, tarolo);
        }
        else if (load_place == 'P')
        {
            scanf("%lf %lf %d", &x, &y, &tarolo);
            hova.x = x;
            hova.y = y;
            place(hova, tarolo);
        }
        else
        {
            kiiras();
            return 0;
        }
    }
    kiiras();
    return 0;
}