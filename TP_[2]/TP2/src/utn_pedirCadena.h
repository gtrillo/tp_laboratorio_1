#ifndef UTN_PEDIRCADENA_H_
#define UTN_PEDIRCADENA_H_
int utn_getNumeroInt (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int utn_getTextAlfanumerico(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
#endif /* UTN_PEDIRCADENA_H_ */
