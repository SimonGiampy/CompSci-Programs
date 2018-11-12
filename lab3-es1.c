/*
   Scrivere un programma che legga da tastiera due date (giorno, mese e anno) e le memorizzi in due variabili di un tipo di dati strutturato appositamente definito. Il programma quindi calcoli la differenza fra le due date inserite in giorni.
 */
#include <stdio.h>
#include <stdlib.h>

struct date {
	int day;
	int month;
	int year;
} date1, date2;

int main() {
	printf("write day of date1: \n");
	scanf("%d", &date1.day);
	printf("write month of date1: \n");
	scanf("%d", &date1.month);
	printf("write year of date1: \n");
	scanf("%d", &date1.year);

	printf("write day of date2: \n");
	scanf("%d", &date2.day);
	printf("write month of date2: \n");
	scanf("%d", &date2.month);
	printf("write year of date2: \n");
	scanf("%d", &date2.year);

	int diffOfDay = 0, diffOfMonth = 0, diffOfYear = 0;
	diffOfDay = abs(date1.day - date2.day);
	diffOfMonth = abs(date1.month - date2.month) * 30;
	diffOfYear = abs(date1.year - date2.year) * 12 * 30;

	diffOfDay = diffOfDay + diffOfMonth + diffOfYear;

	printf("difference of days: %d\n", diffOfDay);

}
