/*
   Esercizio 2 (8 punti)
   A) Si implementi in C il tipo di dato alimento, che consente di rappresentare i dati nutrizionali per 100g di uno
   specifico alimento: kcal, proteine (g), grassi (g), carboidrati (g).
   B) Si implementi in C il tipo di dato piatto, che consente di rappresentare i dati di uno specifico piatto: i dati
   nutrizionale degli alimenti che lo compongono (non più di 50 diversi alimenti) e la loro quantità (in grammi).
   C) Si implementi la funzione float grassi(piatto p), che riceve in ingresso un piatto p e ritorna la
   percentuale di grassi che contiene (calcolata sulla base dei dati nutrizionali degli alimenti che contiene).
 */

//start 18:05
struct alimento {
	int kcal;
	float grassi;
	float proteine;
	float carboidrati;
} alimento;
struct piatto {
	alimento alimenti[50];
	float grammi[50];
} piatto;

float grassi(piatto p) {
	float grassiTot = 0.0, pesoTot = 0.0;
	for (int i = 0; i < sizeof(p) / (sizeof(float) + sizeof(alimento)); i++) {
		grassiTot += p.alimenti[i].grassi * p.grammi[i] / 100.0;
		pesoTot += p.grammi[i];
	}
	return grassiTot / pesoTot * 100.0;
}
