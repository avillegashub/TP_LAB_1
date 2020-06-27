/*
 * tp1_funciones.h
 *
 * Version: 1 del 14 de Abril de 2020
 * Autor: Alvaro Villegas
 */

#ifndef TP1_FUNCIONES_H_
#define TP1_FUNCIONES_H_



int tp1_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int tp1_intSum(int *pResultado, int num1, int num2);
int tp1_intSubtract(int *pResultado, int num1, int num2);
int tp1_intDivide(float *pResultado, int num1, int num2);
int tp1_intMult(int *pResultado, int num1, int num2);
int tp1_intFactor(int *pFactorA, int*pFactorB, int num1, int num2);
int tp1_getChar(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);
int tp1_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif /* TP1_FUNCIONES_H_ */

