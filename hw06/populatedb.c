#include <my_global.h>
#include <mysql.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(int argc, char **argv)
{
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
  
  if (mysql_query(con, "DROP TABLE IF EXISTS Boxers")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "CREATE TABLE Boxers(Id INT PRIMARY KEY AUTO_INCREMENT, FirstName varchar(255) NOT NULL, LastName varchar(255) NOT NULL, Sex varchar(2) NOT NULL, Age INT NOT NULL, Weight INT NOT NULL, Bouts INT NOT NULL)")) {      
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('Hayley', 'Hansson', 'F', 20, 145, 2)")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('Alison', 'Berkowitz', 'F', 19, 130, 3)")) {
      finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('Ben', 'Kahle', 'M', 20, 185, 8)")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('Abe', 'Levitan', 'M', 20, 145, 7)")) {
      finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('Cory', 'Dolphin', 'M', 21, 207, 8)")) {
      finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('Dan', 'Kearney', 'M', 21, 165, 6)")) {
      finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('Evan', 'Dorsky', 'M', 20, 120, 7)")) {
      finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('Forest', 'Bourke', 'M', 19, 135, 2)")) {
      finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('Erin', 'Pierce', 'F', 19, 110, 4)")) {
      finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO Boxers(FirstName, LastName, Sex, Age, Weight, Bouts) VALUES('Adam', 'Coppola', 'M', 20, 145, 2)")) {
      finish_with_error(con);
  }

  mysql_close(con);
  exit(0);
}