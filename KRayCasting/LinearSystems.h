#ifndef LINEARSYSTEMS_H
#define LINEARSYSTEMS_H

float* gaussMethod(float A[][3], float b[], int n);
void gaussElimination(float A[][3], float b[], int n);
float partialPivotion(float A[][3], float b[], int k, int n);
void switchLines(float A[][3], float b[], int j, int k, int n);
float* backSubstituition(float A[][3], float b[], int n);

#endif // LinearSystems_H
