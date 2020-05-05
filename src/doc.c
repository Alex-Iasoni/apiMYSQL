#include <stdio.h>
#include <stdlib.h>

#include "doc.h"


// Allocates enough memory for a medical record:
MedicalRecord* allocateMedicalRecord(short diagnostic_number)
{
	MedicalRecord *medrec = (MedicalRecord*) calloc(1, sizeof(MedicalRecord));

	if (medrec == NULL)
	{
		printf("\nNot enough memory to create a new medical record.\n");
		return NULL;
	}

	medrec -> diagnosticArray = (Diagnostic*) calloc(diagnostic_number, sizeof(Diagnostic));

	if (medrec -> diagnosticArray == NULL)
	{
		printf("\nNot enough memory to create a new diagnostic array.\n");
		return NULL;
	}

	return medrec;
}






// Frees a medical record passed by address, and sets said address to NULL.
void freeMedicalRecord(MedicalRecord **medrec)
{
	if (medrec == NULL || *medrec == NULL)
		return;

	free((*medrec) -> diagnosticArray);
	free(*medrec);
	*medrec = NULL;
}


void printDiagnostic(const Diagnostic *diagnostic)
{
	if (diagnostic == NULL)
	{
		printf("\nNULL diagnostic.\n");
		return;
	}

	printf("\nDiagnostic:\n - id_diag: %d\n - date_diag: %s\n - illnessNumber: %d\n - Illnesses:\n",
		diagnostic -> id_diag, diagnostic -> date_diag, ILLNESS_NUMBER);

	if (diagnostic -> illnessArray == NULL || diagnostic -> illnessProbabilityArray == NULL)
	{
		printf("NULL array!\n");
		return;
	}

	for (int i = 0; i < ILLNESS_NUMBER; ++i)
		printf("    %d) %3d -> %.3f\n", i, diagnostic -> illnessArray[i], diagnostic -> illnessProbabilityArray[i]);

	printf("\n");
}


void printMedicalRecord(const MedicalRecord *medrec)
{
	if (medrec == NULL)
	{
		printf("\nNULL medical record.\n");
		return;
	}

	printf("\nMedical record\n - id_socdet: %d\n - birthdate: %s\n - id_blgrp: %d\n - diagnosticNumber: %d\n - Diagnostics:\n\n",
		medrec -> id_socdet, medrec -> birthdate, medrec -> id_blgrp, medrec -> diagnosticNumber);

	if (medrec -> diagnosticArray == NULL)
	{
		printf("NULL array!\n");
		return;
	}

	for (int i = 0; i < medrec -> diagnosticNumber; ++i)
	{
		printf("%d)", i);
		printDiagnostic(medrec -> diagnosticArray + i);
	}

	printf("\n");
}
