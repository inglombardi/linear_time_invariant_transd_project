# linear_time_invariant_transd_project
Transductor of a Generic Number of Poles for a Linear Time Invariant Low Pass Filter System.

Source report:
https://bugs.unica.it/~gppe/did/ca/tesine/19lombardi.pdf

------------------------------------------------------------
#### Autore
Nicola Lombardi, HW SW Engineer
#### Co-Autore
Giuseppe Rodriguez
Professore Ordinario Matematica Applicata e Algoritmi Numerici presso l'Università degli Studi di Cagliari.
Dipartimento di Matematica - Università di Cagliari
via Ospedale 72, Palazzo delle Scienze, 09124 Cagliari, Italy
### Dataset per i campioni
Messo a disposizione dal Prof. Dott. Ing. Elio Usai.
Professore ordinario
Area scientifico disciplinare - Ingegneria industriale e dell'informazione
Settore scientifico disciplinare - ING-INF/04 AUTOMATICA

Data pubblicazione del report: 7/07/2020 - Corso di Algebra Lineare Numerica

------------------------------------------------------------
### Come usare questo tool

E' presente, al link di cui sopra, una pubblicazione intitolata " Identificazione del modello matematico di un sistema LTI nel dominio della frequenza: fattorizzazione del sistema lineare.
Algebra Lineare Numerica
Corso di Laurea Magistrale in Ingegneria Elettrica, Elettronica e Informatica - A.A. 2019/20 ".

Leggendo il documento è possibile capire come il report dimostri che è possibile ottenere un algoritmo personalizzabile per cui si possa ottenere un modulo software in grado di "trasdurre" il diagramma di Bode (moduli e fasi) in un sistema di equazioni differenziali.
Durante il lavoro è stato usato un dataset pubblico, di poche misure. Il lavoro pubblicato qui comprende un template per poter sviluppare il tool, ma non viene pubblicato interamente il codice sorgente per diversi motivi:

1. Il lavoro è stato svolto per superare la prova di un Seminario e non deve agevolare coloro che in quell'intento copierebbero tale lavoro.
2. Il lavoro può essere personalizzato, essendo un problema sovradeterminato (m>n), si possono avere più soluzioni. La fattorizzazione QR di una generica matrice A non singolare (di dimensioni m × n , con m>n ) permette di risolvere il sistema Ax=b tramite la risoluzione di due sistemi più semplici, ma questo non è l'unico modo e quindi il contributo scientifico deve aiutare ad ispirare le persone che si troveranno in situazioni simili a percorrere una strada simile, ma non uguale.
3. Il lavoro è stato talmente impegnativo che non è giusto, per me stesso, consegnare il sorgente a qualcuno.


### README: Descrizione delle Funzionalità del Programma

#### Introduzione

Questo programma, scritto in stile C, si concentra sull'analisi e il calcolo di risposte di un sistema a ingressi sinusoidali. Vengono trattati vari aspetti, tra cui la trasformazione di dati, l'analisi di ordine di sistemi, e la generazione di matrici di Vandermonde per analisi più complesse.

#### Tipi di Dati Personalizzati

- **`typedef struct data_output { double A_F[2]; } mat;`**  
  Rappresenta i dati in uscita, con due componenti (`A_F[0]` e `A_F[1]`).

- **`typedef struct data_input { double w; } in;`**  
  Rappresenta la pulsazione di ingresso.

#### Funzioni Principali

##### **1. `void data_iniz(mat* a, in* b, double* U);`**
Inizializza le strutture dati leggendo i valori da un file esterno.

---

##### **2. `void T(mat* H, mat* B, double U, int DIM);`**
Esegue una trasformazione di normalizzazione sulla matrice `B`, scalando i valori di `A_F[0]` con il parametro `U` e copiando `A_F[1]`.

---

##### **3. `void I(mat* H, mat* B, int DIM);`**
Inverte i valori della matrice `B`:
- `A_F[0]` viene invertito.
- `A_F[1]` viene negato.

---

##### **4. `void polartorect(double* a, double* b, double M, double phi);`**
Converte coordinate polari (`M`, `phi`) in coordinate rettangolari:
- `a = M * cos(phi)`
- `b = M * sin(phi)`

---

##### **5. `void gv(double* v1, double* v2, double* M, double* phi, int DIM);`**
Calcola i vettori rettangolari corrispondenti a magnitudini (`M`) e fasi (`phi`).

---

##### **6. `void evdmd(double *v1, mat* m, int D, int B, int n);`**
Estrae la colonna `n` da una matrice di tipo `mat` e la salva in un vettore `v1`.

---

##### **7. `void printVect(double* h, int DIM, string name);`**
Stampa un vettore di dimensione `DIM` con un titolo personalizzato.

---

##### **8. `void compressoreToDB(double* v, double* M, int DIM);`**
Converte magnitudini lineari in dB:
- `v[i] = 20 * log10(M[i])`

---

##### **9. `int orderEstimator(double* V, in* w, int DIM);`**
Stima l'ordine del sistema analizzando il comportamento della risposta in frequenza. Restituisce l'ordine stimato e verifica la validità dei valori con una tolleranza di 9 dB.

---

##### **10. `void genMatsVandermonde(in* w, double* vandRe[], double* vandIm[], int orderS, int DIM);`**
Genera matrici di Vandermonde:
- **Reale**: Basata sui termini pari.
- **Immaginaria**: Basata sui termini dispari.
I risultati vengono salvati in array bidimensionali `vandRe` e `vandIm`.

---

##### **11. `int segnj(int z);`**
Calcola il segno di un esponente, alternando tra positivo e negativo in base a un ciclo di 4 stati.

---

##### **12. `void stampaMatrici(double* v[], int n, int m);`**
Stampa una matrice bidimensionale rappresentata come array di puntatori.

---

##### **13. `void composizione(mat* A, double moduli[], double fasi[], int DIM);`**
Costruisce una matrice di tipo `mat` invertendo i moduli e negando le fasi.

---

##### **14. `void trasformazioneLineare();`**
Placeholder per future implementazioni di trasformazioni lineari.

---

#### Funzionamento Generale

1. **Acquisizione dei Dati:**  
   Viene simulata un'acquisizione di dati di pulsazioni (`w`), moduli di risposta in frequenza e fasi.
   
2. **Generazione delle Matrici di Vandermonde:**  
   Utilizzando pulsazioni e ordine stimato del sistema, le matrici reale e immaginaria vengono generate per analisi successive.

3. **Stima e Analisi:**  
   - Ordine del sistema stimato con `orderEstimator`.
   - Moduli e fasi utilizzati per calcoli rettangolari (`gv`).

4. **Visualizzazione:**  
   Vettori e matrici vengono stampati per verifica manuale.

---

#### Requisiti

- Compilatore C++ con supporto per `iostream`, `math.h` e `string`.
- Input da file o simulato.

#### Estensioni Future

- Lettura dinamica da file tramite `data_iniz`.
- Implementazione di trasformazioni lineari aggiuntive.

