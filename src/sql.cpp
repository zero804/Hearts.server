#include <cstring>
#include <cstdlib> // exit()
#include <cstdarg>
#include "define.h"
#include "sql.h"
#include "log.h"

int cMYSQL::query( const char *format, ... )
{
  int errno;
  va_list args;
  char buffer[SIZE_QUERY_BUFFER];

  if (!freed) {
    mysql_free_result(result);                    // free any previous query storage
    freed = true;
  }

  va_start(args, format);

  vsnprintf(buffer, SIZE_QUERY_BUFFER, format, args);
  strncpy(last_query, buffer, SIZE_QUERY_BUFFER);  // keep a backup of the last query
  errno = mysql_query(&mysql, buffer);

#ifdef DEBUG
  printf("query: %s, errno: %d\n", buffer, errno);
#endif

  va_end(args);

  if (errno) return false;

  if (!(result = mysql_store_result(&mysql))) {
    freed = true; // nothings has been saved, so nothing will need to be freed.
    if (mysql_field_count(&mysql) != 0) { // data was expected
      Log.Write("SYSERR: cMYSQL::query() error: %s\n", mysql_error(&mysql));
      return false; // error
    }
    return true; // not error, was a "insert", "delete"... not data to retreive.
  } 

  freed = false; // data has been saved, will need to release it later.
  num_affected_row = mysql_affected_rows(&mysql);
  num_fields = mysql_num_fields(result);
  if (!(row = mysql_fetch_row(result))) {
    mysql_free_result(result);
    freed = true;
    return num_affected_row;
  }
  return num_affected_row;
}

const char *cMYSQL::get_row(unsigned int index)
{
  if (index + 1 > num_fields) {
    Log.Write("SYSERR: cMYSQL::get_row() invalid index: %d > num_fields: %d", index, num_fields);
    Log.Write("SYSERR: last query was '%s'" , last_query);
    return "";
  }

  if (row[index] == nullptr) {
    Log.Write("SYSERR: cMYSQL::get_row() row[%d] == nullptr", index);
    Log.Write("SYSERR: last query was '%s'", last_query);
    return "";
  }

  return row[index];
}

cMYSQL::cMYSQL()
{
  FILE *fp;

  char line[QUERY_SIZE],
       param[10 + 1],
       value[70 + 1];

  if (!(fp = fopen(".hserver", "r"))) {
    printf("Can't open .hserver file!\r\n");
    exit(1);
  }

  int ret;

  while (fgets (line, QUERY_SIZE, fp) != nullptr) {
    ret = sscanf(line, "%10s %70s", param, value);
    if (ret != 2) continue;
    if (!strcmp(param, "host")) strcpy(host, value); else
    if (!strcmp(param, "db")) strcpy(db, value); else
    if (!strcmp(param, "user")) strcpy(user, value); else
    if (!strcmp(param, "password")) strcpy(password, value);
  }

  fclose(fp);

  sql.connect();
}

void cMYSQL::connect()
{
  bool option = true;
  mysql_init(&mysql);
  mysql_options(&mysql, MYSQL_OPT_RECONNECT, &option);
  mysql_options(&mysql, MYSQL_OPT_COMPRESS, 0);
  mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "odbc");

  if (!mysql_real_connect(&mysql, host, user, password, NULL, 0, NULL, 0)) {
 // A MYSQL* connection handle if the connection was successful, NULL if the connection was unsuccessful. For a successful connection, the return value is the same as the value of the first parameter.
    Log.Write("SYSERR: can't connect to the mysql database");
    exit(1);
  }

  if (mysql_select_db(&mysql, db)) { 
// Zero for success. Non-zero if an error occurred.
    Log.Write("SYSERR: can't select the database: '%s'", db);
    exit(1);
  }

  freed = true;
  num_affected_row = num_fields = 0;
}

cMYSQL::~cMYSQL()
{
  if (!freed)
    mysql_free_result(result);
}

unsigned int cMYSQL::Num_Fields()
{
  return num_fields;
}
