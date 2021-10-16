#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "utn_menu.h"
#define LENEMPLEADOS 1000

int main(void) {
	Employee aEmpleados [LENEMPLEADOS];
	setbuf (stdout, NULL);
	initEmployees(aEmpleados, LENEMPLEADOS);

	//empleados_altaForzada(aEmpleados, LENEMPLEADOS, 0, 0, "Gonzalo", "Trillo", 210, 5);
	//empleados_altaForzada(aEmpleados, LENEMPLEADOS, 1, 1, "Jorge", "Gomez", 215, 3);
	//empleados_altaForzada(aEmpleados, LENEMPLEADOS, 2, 2, "Kevin", "Martinez", 356, 1);

	utn_menu (aEmpleados, LENEMPLEADOS);
	return EXIT_SUCCESS;
}
