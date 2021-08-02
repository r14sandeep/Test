#include<stdio.h>
#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{
  
	MYSQL *con = mysql_init(NULL);
	printf("MySQL client version: %s\n", mysql_get_client_info());

	exit(0);
}

