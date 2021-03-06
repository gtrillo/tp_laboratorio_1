#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "employee.h"
typedef struct
{
	int id;
	char name [51];
	char lastName [51];
	float salary;
	int sector;
	int flagEmpty; //esta variable sera utilizada para saber si una posicion esta disponible o no 0: ocupado 1: libre
}Employee;
int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int DameUnLugarLibre (Employee pEmpleado[], int lenArray, int* retornoPosicionLibre);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int printEmployees(Employee* list, int length);
int modificarEmpleado(Employee* aEmpleados);
int sortEmployees(Employee* list, int len, int order);
int promedioSalario (Employee array [], int len, float *resultado, float* retornoAcumSalario);
//int empleados_altaForzada (Employee* array, int limite, int indice, int id, char* nombre, char* apellido,float salario, int sector);
#endif /* EMPLOYEE_H_ */
