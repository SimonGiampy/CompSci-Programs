/* Programma assicurazione.c */
#include <stdio.h>
int main()
{
        int anni, cc, giovane,altaCC;
        printf("Inserire l'eta': "); scanf("%d",&anni);
        printf("Inserire cilindarata: "); scanf("%d",&cc);
        giovane = (anni<=20);
        altaCC = (cc>1400);
        if (giovane && altaCC)
                printf("Incremento: 70 per cento\n");
        if (giovane && !altaCC)
                printf("Incremento: 40 per cento\n");
        if (!giovane && altaCC)
                printf("Incremento: 10 per cento\n");
        if (!giovane && !altaCC)
                printf("Incremento: nessuno\n");
        return 0;
}
