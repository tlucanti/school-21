#!/usr/bin/env bash

echo ">>> STARTING MARIADB"

sed -i "s/bind-ad/\#bind-ad/" "/etc/mysql/mariadb.conf.d/50-server.cnf"
sed -i "s/\#port/port/"       "/etc/mysql/mariadb.conf.d/50-server.cnf"

chown -R mysql:mysql /var/lib/mysql

if [ ! -d var/lib/mysql/wp ]; then
	echo ">>> CREATING NEW MYSQL DB"
	service mysql start
	mysql -u root -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE"
	mysql -u root -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'"
	mysql -u root -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'"
	mysql -u root -e "FLUSH PRIVILEGES"
	mysqladmin -u root password $MYSQL_ROOT_PASSWORD
	service mysql stop
else
	echo ">>> SETTING UP EXISTING DB"
	mkdir -p /var/run/mysqld
	touch /var/run/mysqld/mysqld.pid
	mkfifo /var/run/mysqld/mysqld.sock
fi
chown -R mysql /var/run/mysqld

echo ">>> MARIADB DONE"
exec "$@"
