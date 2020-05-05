#ifndef API_H
#define API_H


#include "doc.h"


void connectToDatabase(void);


// Returns 1 on success, 0 else.
int writeDiagnostic(const Diagnostic *diagnostic);


// Reads medical records on the database. Returns NULL on failure.
MedicalRecord* readMedicalRecord(int id_socdet);


#endif
