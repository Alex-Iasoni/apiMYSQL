#ifndef DOC_H
#define DOC_H


#define MAX_STRING_LENGTH 100
#define ILLNESS_NUMBER 5


typedef short Illness;
typedef short Symptom;


// typedef struct
// {
// 	Illness illness;
// 	short symptomNumber;
// 	Symptom *symptomArray;
// } MedicalData;


// This can be freed by a regular 'free()' call:
typedef struct
{
	int id_diag;
	char date_diag[MAX_STRING_LENGTH];
	// short illnessNumber;
	Illness illnessArray[ILLNESS_NUMBER];
	float illnessProbabilityArray[ILLNESS_NUMBER];
} Diagnostic;


// This must be freed by a freeMedicalRecord()' call:
typedef struct
{
	int id_socdet;
	char birthdate[MAX_STRING_LENGTH];
	int id_blgrp;
	short diagnosticNumber;
	Diagnostic *diagnosticArray; // length: 'diagnosticNumber'
} MedicalRecord;


// Allocates enough memory for a medical record:
MedicalRecord* allocateMedicalRecord(short diagnostic_number);


// Frees a medical record passed by address, and sets said address to NULL.
void freeMedicalRecord(MedicalRecord **medrec);


void printDiagnostic(const Diagnostic *diagnostic);


void printMedicalRecord(const MedicalRecord *medrec);


#endif
