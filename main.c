/*fait par le prof */
#include <stdio.h>
#include <stdlib.h>
#include <math.h> /*pour sqrt et pow on compile avec -lm*/

/* le type complexe */
struct complexe
  {
      double Re;
      double Im;
 };

/* une définition plus courte pour la structure */
typedef struct complexe Complexe;
/* on dispose du type Complexe  */

void affiche_complexe(Complexe nb)
{
printf("nb complexe : %.3f +i%.3f \n",nb.Re,nb.Im);
}

void affiche_somme_complexe(Complexe nb1,Complexe nb2)
{
printf("La somme est %.3f+i%.3f \n",nb1.Re+nb2.Re, nb1.Im+nb2.Im);
}

Complexe carre_complexe(Complexe nb)
{
    Complexe Calcul;
    Calcul.Re= (nb.Re*nb.Re)-(nb.Im*nb.Im);
    Calcul.Im= 2*nb.Re*nb.Im;
    return (Calcul);
}

Complexe somme_complexe(Complexe nb1,Complexe nb2)
{
Complexe somme;
somme.Re=nb1.Re+nb2.Re;
somme.Im=nb1.Im+nb2.Im;
return(somme);
}

double module(Complexe  nb)
{
return( sqrt(pow((nb.Re),2)+pow((nb.Im),2)));
}

double argument(Complexe nb)
{
double S1 = atan(nb.Im/nb.Re);
return(S1);
}

#define nb_iter_max 20
#define x_max 1000
#define y_max 1000
#define x_min 0
#define y_min 0

#define x1  -2.1
#define x2  0.6
#define y1 -1.2
#define y2 1.2

#define pas_x (x2-x1)/(x_max-x_min)
#define pas_y (y2-y1)/(y_max-y_min)

int main (/*int argc, char ** argv*/)
{
/* espace complexe (plan) */
int x,y,nb_iter;
printf ("P1\n%d %d\n",x_max,y_max);
/* on définit 2 nombres complexes c et n */
 Complexe c;  /* x+iy */
 Complexe z;
 z.Im=0;z.Re=0; /* z=0 */
 double module_z;
 Complexe carre_z;

for (y=y_min;y<y_max;y++)
{
    for (x=x_min;x<x_max;x++)
    {
    z.Im=0;z.Re=0; /* z=0 */
    nb_iter=0;
    c.Im=y1+y*pas_y;
    c.Re=x1+x*pas_x;
    do
    {
    carre_z=carre_complexe(z);
    z=somme_complexe( carre_z,c);  /* z=z*z +c */
    nb_iter++;
    module_z=module(z);
    }
    while ((module_z<=2) && (nb_iter<nb_iter_max));

    if (nb_iter==nb_iter_max)
         printf("1 ");
    else
         printf("0 ");
    }
printf("\n");
}
 return EXIT_SUCCESS;
}
