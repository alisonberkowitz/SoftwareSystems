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

  char Sex[2];
  puts("M/F?: ");
  scanf("%1s", Sex);

  char Age[4];
  puts("Enter Age: ");
  scanf("%3s", Age);

  char Weight[4];
  puts("Enter Weight: ");
  scanf("%3s", Weight);

  char Bouts[4];
  puts("Number of Bouts: ");
  scanf("%3s", Bouts);

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

  char prefix[1000] = "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('";
  strcat(prefix, FirstName);
  strcat(prefix, "', '");
  strcat(prefix, LastName);
  strcat(prefix, "', '");
  strcat(prefix, Sex);
  strcat(prefix, "', '");
  strcat(prefix, Age);
  strcat(prefix, "', '");
  strcat(prefix, Weight);
  strcat(prefix, "', '");
  strcat(prefix, Bouts);
  strcat(prefix, "')");
  // strcat(prefix, cmd_argv[1]);
  // perror(prefix);

  if (mysql_query(con, prefix)) {
      finish_with_error(con);
  }

  mysql_close(con);
  exit(0);
}