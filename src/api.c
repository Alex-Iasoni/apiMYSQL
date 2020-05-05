#include <stdio.h>
#include <stdlib.h>



#include "api.h"
#include <string.h>
#include <mysql.h>
MYSQL  connectToDatabase(void)
{
	
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
	

	if(mysql_real_connect(&mysql, "localhost", "root", "root", "CAD", 0, NULL, 0))
	 {
	 	printf("connect mysql\n");
      
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD!");
    }
	return mysql;

}


// Writes a diagnostic on the database. Returns 1 on success, 0 else.
int writeDiagnostic(const Diagnostic *diagnostic)
{
	if (diagnostic == NULL)
	{
		printf("\nNULL diagnostic.\n");
		return 0;
	}

	// write the diagnostic in the database !!!

	return 0;
}


// Reads medical records on the database. Returns NULL on failure.
MedicalRecord* readMedicalRecord(int id_socdet)
{
	short diagnostic_number = 10; // to fetch !!!

	MedicalRecord *medrec = allocateMedicalRecord(diagnostic_number);

	// fetch and fill 'medrec' attributes !!!

	return medrec;
}


Diagnostic* readDiagnostic(int id_diag)
{
	Diagnostic *diagnostic = (Diagnostic*) calloc(1, sizeof(Diagnostic));

MYSQL mysql = connectToDatabase();

			char * query = strcat("SELECT doct.id_diag, date_diag, ill.name, illp.probability FROM doctor_diagnostic as doct INNER JOIN illness_probability as illp ON doct.id_diag = illp.id_diag INNER JOIN illness as ill ON ill.id_ill = illp.id_ill WHERE doct.id_diag = ", (char *) id_diag);
		mysql_query(&mysql, query); 

		MYSQL_RES *result = mysql_use_result(&mysql);
		MYSQL_ROW row = NULL;
		diagnostic->id_diag = id_diag;

		
		int i = 0;

		while ((row = mysql_fetch_row(result))) // assignment and testing!
		{
			
				diagnostic->date_diag[i] = (char) row[1];
				diagnostic->illnessArray[i] = (Illness) row[2];
				
				diagnostic->illnessProbabilityArray[i]= strtod(row[3], NULL);
				i++;
			}
		
		

		mysql_free_result(result);
		mysql_close(&mysql);
	
	// fetch and fill 'medrec' attributes !!!
	printDiagnostic(diagnostic);
	return diagnostic;
}


