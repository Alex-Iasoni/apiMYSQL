#include <stdio.h>
#include <stdlib.h>

#include "doc.h"
#include "api.h"


void testStructures(void);


int main(void)
{
	testStructures();

	connectToDatabase();

	return 0;
}


void testStructures(void)
{
	Diagnostic diag_1 =
	{
		.id_diag = 123456,
		.date_diag = "2020_05_04",
		.illnessArray = {15, 3, 2, 7, 20},
		.illnessProbabilityArray = {0.1, 0.4, 0.2, 0., 0.3}
	};

	Diagnostic diag_2 =
	{
		.id_diag = 789654,
		.date_diag = "2020_04_01",
		.illnessArray = {20, 1, 12, 5, 3},
		.illnessProbabilityArray = {0.1, 0.5, 0.05, 0., 0.1}
	};

	Diagnostic diag_3 =
	{
		.id_diag = 159627,
		.date_diag = "2019_01_01",
		.illnessArray = {2, 8, 33, 17, 51},
		.illnessProbabilityArray = {0.3, 0.1, 0., 0., 0.5}
	};

	// printDiagnostic(&diag_1);
	// printDiagnostic(&diag_2);
	// printDiagnostic(&diag_3);

	Diagnostic diagnosticArray[] = {diag_1, diag_2, diag_3};

	MedicalRecord medrec =
	{
		.id_socdet = 007,
		.birthdate = "1980_06_15",
		.id_blgrp = 2,
		.diagnosticNumber = 3,
		.diagnosticArray = diagnosticArray
	};

	printMedicalRecord(&medrec);
}
