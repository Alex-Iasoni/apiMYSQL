#include <stdio.h>
// #include <stdlib.h>

#include <mysql.h>

#include "api.h"


void connectToDatabase(void)
{
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");

	if (mysql_real_connect(&mysql, "localhost", "root", "root", "BehaviorAnalysis", 0, NULL, 0))
	{
		mysql_query(&mysql, "SELECT * FROM illness"); // browsing the 'illness' table.

		MYSQL_RES *result = mysql_use_result(&mysql);
		MYSQL_ROW row = NULL;

		unsigned int fields_number = mysql_num_fields(result); // Returns the number of columns, in a table.

		while ((row = mysql_fetch_row(result))) // assignment and testing!
		{
			unsigned long *lengths = mysql_fetch_lengths(result); // columns lengths of the current row, in a table.

			for (int i = 0; i < fields_number; ++i)
			{
				printf("[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");
			}
			printf("\n");
		}

		mysql_free_result(result);
		mysql_close(&mysql);
	}

	else
	{
		printf("Error: cannot connect to the database!\n");
	}
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

// Reads medical records on the database. Returns NULL on failure.
Diagnostic* readDiagnostic(int id_socdet)
{
	short diagnostic_number = 10; // to fetch !!!

	Diagnostic *diagnostic = allocateMedicalRecord(diagnostic_number);

	// fetch and fill 'medrec' attributes !!!

	return medrec;
}
