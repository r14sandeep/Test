/* Simple C program that connects to MySQL Database server*/
#include"header.h"

void push_to_database(char *addr,int rssi) {
puts("in db");
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
printf("addr:%s,rssi:%d\n",addr,rssi);
   char *server = "192.168.4.167";
   char *user = "venkey";
   char *password = "venkey"; /* set me first */
   char *database = "data_BT";

   conn = mysql_init(NULL);

   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   /* send SQL query */
   //if (mysql_query(conn,"INSERT INTO bluetooth VALUES('addr','gateway1','rssi')")) {
///////////
	//char esc[2*len+1];
   // unsigned long esclen = mysql_real_escape_string(mysql, esc, str, len);

    char statement[512];
    sprintf(statement,"INSERT INTO bluetooth VALUES ('%s','%s',%d)",addr,"gateway1",rssi);
    if(mysql_query(conn,statement))
      //if (mysql_query(conn,"INSERT INTO bluetooth VALUES(%s,addr),VALUES('gateway1'),VALUES(%d,rssi)")) {
	{      
	fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   res = mysql_use_result(conn);

   /* output table name */
  /* printf("MySQL Tables in mysql database:\n");
   while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s %s %s\n", row[0],row[1],row[2]);*/

   /* close connection */
  // mysql_free_result(res);
   mysql_close(conn);
   return 0;

}


