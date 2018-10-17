//controlla se il numero in input è primo


//prima versione tradotta del prof
#include <stdio.h>
int main() {
        //my version
        int number, i=2;
        scanf("%d", &number);
        if (number == 1) {
                printf("non primo\n");
        } else if(number == 2) {
                printf("numero primo\n");
        }
        //_Bool primo = false;
        int primo = 0;
        while (primo == 0) {
                if (number % i != 0) {
                        i++;
                        if (i==number) {
                                printf("numero primo\n");
                                primo = 1;
                        }
                } else {
                        printf("numero non è primo\n");
                        primo = 1;
                }
        }
        return 0;
}


/*versione del prof in pseudocodice
   r=1;
   div=1;
   leggi n;
   finchè div*div<n e r<>0
    div=div+1;
    r=n mod div
   chiudi
   se r=0 allora
    stampa non primo
   else
    stampa primo
 */
