/*
 * utn.menu.c
 *  Created on: 8 sep. 2021
 *      Author: Gonzalo Ernesto Blas Trillo
 */
#include <stdio.h>
#include <stdlib.h>
#define REINTENTOS 3 //cantidad de veces que se pide un numero

//prototipo de las funsiones
int getNumeroFloat (float* pfloat, int reintentos, char *variableTextoSolicitudNumero, char *variableTextoFueraDeRango);
int operacionSuma(float operadorUno, float operadorDos, float *returnResultado);
int operacionResta(float operadorUno, float operadorDos, float *returnResultado);
int operacionMultiplicacion(float operadorUno, float operadorDos,float *returnResultado);
int operacionDivision(float operadorUno, float operadorDos,float *returnResultado);
int operacionFactorial(float operadorUno, float *returnResultado);
void utn_menu(float *pnumeroUno, float *pnumeroDos, char *mensaje1,char *mensaje2, char *mensaje3, char *mensaje4, char *mensaje5, char *mensaje6)
{
	//declaracion de variables
	float bufferFloat1 = *pnumeroUno;
	float bufferFloat2 = *pnumeroDos;
	int opcion;
	int seguir = 0;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	float factorialA;
	float factorialB;

	int retErrorFactorialA;
	int retErrorFactorialB;
	int retErrorDivision;
	int retErrorSuma;
	int retErrorResta;
	int retErrorMultiplicacion;

	int recibiNum1 = 1;
	int recibiNum2 = 1;
	//menu de opciones
	do {
		printf("%s", mensaje1);
		printf("%s", mensaje2);
		printf("%s", mensaje3);
		printf("%s", mensaje4);
		printf("%s", mensaje5);
		printf("%s", mensaje6);

		fflush(stdin);
		printf("\nOpcion elegida:");
		scanf("%d", &opcion);

		switch (opcion) { // switch de opciones
		case 1:
			if (getNumeroFloat (&bufferFloat1, REINTENTOS, "\nIngrese un numero:", "\nSolo se admiten numeros") == 0) {
				printf("Ingresaste A=%.2f ", bufferFloat1);
				recibiNum1 = 0;
			}else {
				printf("\nError. SOLO SE ADMITEN NUMEROS. \nprograma finalizado.");
				exit(0);
			}
			break;
		case 2:
			if (getNumeroFloat (&bufferFloat2, REINTENTOS, "\nIngrese un numero:", "\nSolo se admiten numeros") == 0) {
				printf("Ingresaste B=%.2f ", bufferFloat1);
				recibiNum2 = 0;
			}else {
				printf("\nError. SOLO SE ADMITEN NUMEROS. \nprograma finalizado.");
				exit(0);
			}
			break;
		case 3:
			if (recibiNum1 == 0 && recibiNum2 == 0){
			retErrorSuma = operacionSuma(bufferFloat1, bufferFloat2, &suma);
			if (retErrorSuma == 0)
			{
				printf("\na) El resultado de A+B es: %.2f", suma);
			}
			retErrorResta = operacionResta(bufferFloat1, bufferFloat2, &resta);
			if (retErrorResta == 0)
			{
				printf("\nb) El resultado de A-B es: %.2f", resta);
			}
			retErrorMultiplicacion = operacionMultiplicacion(bufferFloat1,bufferFloat2, &multiplicacion);
			if (retErrorMultiplicacion == 0)
			{
				printf("\nc) El resultado de A*B es: %.2f", multiplicacion);
			}
			retErrorDivision = operacionDivision(bufferFloat1, bufferFloat2, &division);
			if (retErrorDivision == -1) {
				printf("\nd)Error. no se puede dividir por 0");
			} else {
				printf("\nd)El resultado de A/B es: %.2f", division);
			}
			retErrorFactorialA = operacionFactorial(bufferFloat1, &factorialA);
			if (retErrorFactorialA == -1) {
				printf("\ne)El factorial de A es: 0");
			} else {
				printf("\ne)El factorial de A es: %.2f", factorialA);
			}
			retErrorFactorialB = operacionFactorial(bufferFloat2, &factorialB);
			if (retErrorFactorialB == -1) {
			printf(" y El factorial de B es: 0");
			} else {
			printf(" y El factorial de B es: %.2f", factorialB);
			}
			printf("\nprograma finalizado");
			exit(0);
			}//fin del if principal
			break;
		case 4:
			//finaliza el programa
			printf("\nprograma finalizado");
			exit(0);
		}
	} while (seguir != 4);
}
/**
 * \brief solicitud de numero flotante
 * \param pfloat es el puntero del numero flotante
 * \param reintentos es la cantidad de veces que se va a solicitar el numero en caso de que el caracter ingresado no corresponda a un tipo float
 * \param variableTextoSolicitudNumero es el mensaje de solicitud de numero
 * \param variableTextoFueraDeRango es el mensaje de error que se ejecuta en caso de que el caracter ingresado no corresponda a un numero float
 * \return 0 si esta ok y -1 en caso de error.
 */
int getNumeroFloat (float* pfloat, int reintentos, char *variableTextoSolicitudNumero, char *variableTextoFueraDeRango)
{
	    int retornoError;
	    float buffer;
	    int i;
	    if (pfloat != NULL && reintentos >= 0 && variableTextoSolicitudNumero != NULL && variableTextoFueraDeRango != NULL){
	    for (i = 0; i < reintentos; i++){
	    	fflush (stdin);
	    	printf("%s \n", variableTextoSolicitudNumero);
			if(scanf("%f",&buffer)==1)
			{
				*pfloat = buffer;
				retornoError=0;
				break;
					}
					else
					{
						printf("%s\n", variableTextoFueraDeRango);
						retornoError=-1;
					}
	    	}
	    }
	    return retornoError;
	    }
/**
 * \brief realiza la operacion suma
 * \param operadorUno es el primer numero flotante para realizar el calculo
 * \param operadorDos es el primer segundo flotante para realizar el calculo
 * \param returnResultado es el puntero del resultado de la operacion
 * \return 0 si esta ok y -1 en caso de error.
 */

int operacionSuma(float operadorUno, float operadorDos, float *returnResultado) {
	float resultadoSuma;
	int huboError;

		if (returnResultado != NULL)
		{
			resultadoSuma = operadorUno + operadorDos;
			*returnResultado = resultadoSuma;
			huboError = 0;
		}
			else
			{
				huboError = -1;
			}
	return huboError;
}
/**
 * \brief realiza la operacion resta
 * \param operadorUno es el primer numero flotante para realizar el calculo
 * \param operadorDos es el primer segundo flotante para realizar el calculo
 * \param returnResultado es el puntero del resultado de la operacion
 * \return 0 si esta ok y -1 en caso de error.
 */
int operacionResta(float operadorUno, float operadorDos, float *returnResultado) {
	float resultadoresta;
	int huboError;

		if (returnResultado != NULL)
		{
			resultadoresta = operadorUno - operadorDos;
			*returnResultado = resultadoresta;
			huboError = 0;
		}
			else
			{
				huboError = -1;
			}
	return huboError;
}
/**
 * \brief realiza la operacion multiplicacion
 * \param operadorUno es el primer numero flotante para realizar el calculo
 * \param operadorDos es el primer segundo flotante para realizar el calculo
 * \param returnResultado es el puntero del resultado de la operacion
 * \return 0 si esta ok y -1 en caso de error.
 */
int operacionMultiplicacion(float operadorUno, float operadorDos,
	float *returnResultado) {
	float resultadomultiplicacion;
	int huboError;

	if (returnResultado != NULL)
		{
			resultadomultiplicacion = operadorUno * operadorDos;
			*returnResultado = resultadomultiplicacion;
			huboError = 0;
		}
			else
			{
				huboError = -1;
			}
	return huboError;
}
/**
 * \brief realiza la operacion division
 * \param operadorUno es el primer numero flotante para realizar el calculo
 * \param operadorDos es el primer segundo flotante para realizar el calculo
 * \param returnResultado es el puntero del resultado de la operacion
 * \return 0 si esta ok y -1 en caso de error.
 */
int operacionDivision(float operadorUno, float operadorDos,
	float *returnResultado) {
	float resultado;
	int huboError;

	if (operadorDos != 0) {
		resultado = operadorUno / operadorDos;
		(*returnResultado) = resultado;
		huboError = 0;
	} else {
		huboError = -1;
	}
	return huboError;
}
/**
 * \brief realiza la operacion fatorial
 * \param operadorUno es el primer numero flotante para realizar el calculo
 * \param returnResultado es el puntero del resultado de la operacion
 * \return 0 si esta ok y -1 en caso de error.
 */
int operacionFactorial(float operadorUno, float *returnResultado) {
	float factorial = 1;
	float i;
	int huboError;
	if (operadorUno != 0) {
		for (i = operadorUno; i > 1; i--) {
			factorial *= i;
		}
		(*returnResultado) = factorial;
		huboError = 0;
	} else {
		huboError = -1;
	}
	return huboError;
}
