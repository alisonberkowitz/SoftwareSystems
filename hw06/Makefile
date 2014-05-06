createdb: createdb.c
	gcc createdb.c -o createdb -std=c99  `mysql_config --cflags --libs`

populatedb: populatedb.c
	gcc populatedb.c -o populatedb -std=c99  `mysql_config --cflags --libs`

addtodb: addtodb.c
	gcc addtodb.c -o addtodb -std=c99  `mysql_config --cflags --libs`

retrieve_data: retrieve_data.c
	gcc retrieve_data.c -o retrieve_data -std=c99  `mysql_config --cflags --libs`

headers: headers.c
	gcc headers.c -o headers -std=c99  `mysql_config --cflags --libs`