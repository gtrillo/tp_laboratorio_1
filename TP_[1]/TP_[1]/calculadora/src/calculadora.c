/*
 ============================================================================
 Name        : calculadora.c
 Author      : Gonzalo Ernesto Blas Trillo
 Version     : 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_protipos.h"

int main(void) {
	setbuf (stdout, NULL);
	float numeroUno;
	float numeroDos;
	utn_menu (&numeroUno, &numeroDos , "\n[Calculadora V1]", "\n-Opciones:", "\n1) ingresar el primer numero", "\n2) Ingresar el segundo numero", "\n3) Mostrar resultados", "\n4) Salir");
	return EXIT_SUCCESS;
}
