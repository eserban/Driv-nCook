#include "bdd.h"

int insertInDB(char* query){

  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "projet", "projet",
          "bdd_projet_c", 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      return 1;
  }

  if (mysql_query(con, query))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        return 1;
  }

  mysql_close(con);
  return 0;
}

char *getFromFile(char* filename){
    char* name = malloc(sizeof(int)*255);
    FILE* file = fopen(filename, "r+");
    fgets(Name, 255, file);
    return name;
}

int main(int argc, char** argv){
    char* name = malloc(sizeof(int)*255);
    name = getFromFile("user.txt");
    insertInDB("");

}
