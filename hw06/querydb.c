/*
Copyright 2014 Alison Berkowitz and Hayley Hansson
This program allows the user to query the database to find a sparring partner of the same gender and weight class from the command line.
When run, the program request the user's first and last name, and prints the information of everyone with the correct criteria.
*/

#include <my_global.h>
#include <mysql.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(int argc, char **argv)
{
  char FirstName[255];
  puts("Enter FirstName: ");
  scanf("%254s", FirstName);

  char LastName[255];
  puts("Enter LastName: ");
  scanf("%254s", LastName);

  MYSQL *con = mysql_init(NULL);
  
  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }  

  if (mysql_real_connect(con, "localhost", "root", "51Perkins", 
          "boxerdb", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    

  char prefix[1000] = "SELECT * FROM Boxers WHERE FirstName = '";
  strcat(prefix, FirstName);
  strcat(prefix, "' AND LastName = '");
  strcat(prefix, LastName);
  strcat(prefix, "' LIMIT 1");

  if (mysql_query(con, prefix)) {
      finish_with_error(con);
  }

  MYSQL_RES *user = mysql_store_result(con);
  
  if (user == NULL) 
  {
      finish_with_error(con);
  }

  MYSQL_ROW line;

  line = mysql_fetch_row(user);

  char *Sex = line[3];

  char *Age = line[4];

  char *Weight = line[5];

  char *Bouts = line[6];

  char req[1000] = "SELECT * FROM Boxers WHERE Sex = '";
  strcat(req, Sex);
  strcat(req, "' AND Weight = '");
  strcat(req, Weight);
  strcat(req, "'");

  if (mysql_query(con, req)) {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);
  
  if (result == NULL) 
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  printf("\n");
  printf("Matches Found:\n");

  MYSQL_ROW row;
  
  while ((row = mysql_fetch_row(result))) 
  { if (strcmp(row[0],line[0])){
      for(int i = 0; i < num_fields; i++) 
        { 
            printf("%s ", row[i] ? row[i] : "NULL"); 
        } 
            printf("\n"); 
    }
  }
  
  mysql_free_result(result);
  mysql_free_result(user);
  mysql_close(con);
  
  exit(0);
}
