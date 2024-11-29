//m>n è il caso trattato

/*
 * Sulla base dell'approccio implementato (stile c), un programma di questo tipo dovrebbe acquisire i dati da file
 *  quindi la procedura "void data_iniz(mat* a, in* b, double* U)" dovrebbe modellare il vettore delle pulsazioni in base
 * ai punti del diagramma di bode ogni volta che il sistema (magari sempre diverso dal precedente) risponde all'ingresso sinusoidale.
 *
 * La visione di una matrice nx2 è sempre esteticamente brutta, dunque si è pensato di usare una struct, un pò come se fosse un vero
 * e proprio oggetto. Il paradigma OOP non è stato comunque implementato perchè non era necessario usufruire di Incapsulamento, Polimorfismo, Astrazione Data structure ed Ereditarietà.
 * */
#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
using namespace std;
#define dimension 50

typedef struct data_output {
    double A_F[2];
}mat;

typedef struct data_input {
    double w;}in; //pulsazione

//funzioni per estensioni future
void data_iniz(mat* a, in* b, double* U);
void T(mat* H,mat* B,double U,int DIM);
void I(mat* H,mat* B,int DIM);

//lista di funzioni
void polartorect(double* a, double* b, double M, double phi);
void gv(double* v1, double* v2, double* M, double* phi,int DIM);
void evdmd(double *v1,mat* m,int D,int B,int n);
void printVect(double* h,int DIM,string name);
void compressoreToDB(double* v,double* M, int DIM);
int orderEstimator(double* V, in* w, int DIM);
void genMatsVandermonde(in* w,double* vandRe[], double* vandIm[],int orderS,int DIM);
int segnj(int z);
void stampaMatrici(double* v[],int n,int m);
void stampa(double matr, int DIM, int dim);
void composizione(mat *A, double moduli[], double fasi[], int DIM);
void trasformazioneLineare();
