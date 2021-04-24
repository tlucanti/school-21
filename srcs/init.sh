#!/usr/bin/env bash

# Config Access
echo "config access"
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

# mySQL database
echo "mysql"
service mysql start
mysql -u root -e "CREATE DATABASE wordpress21"
mysql -u root -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin'"
mysql -u root -e "GRANT ALL PRIVILEGES ON wordpress21.* TO 'admin'@'localhost'"
mysql -u root -e "FLUSH PRIVILEGES"

mkdir /var/www/tmp
mkdir /var/www/ft_server

# PHPMyAdmin
echo "phpmyadmin"
mkdir /var/www/ft_server/phpmyadmin
cd /var/www/tmp
wget https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-english.tar.gz
tar -xvf phpMyAdmin-latest-english.tar.gz --strip-components 1 \
    -C /var/www/ft_server/phpmyadmin > /dev/null
mv /var/www/phpmyadmin.inc.php /var/www/ft_server/phpmyadmin/
rm -rf phpMyAdmin-latest-english.tar.gz
service php7.3-fpm start

# SSL
echo "ssl"
openssl req \
    -newkey rsa:4096 \
    -x509 -sha256 \
    -days 3650 -nodes \
    -out /etc/nginx/certificate.crt \
    -keyout /etc/nginx/private.key \
    -subj "/C=RU/ST=Moscow/L=Moscow /O=21School/OU=tlucanti/CN=*.localhost/emailAddress=unknown"

# Wordpress
echo "wordpress"
mkdir /var/www/ft_server/wordpress
cd /var/www/tmp
wget http://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz > /dev/null
mv wordpress /var/www/ft_server
rm -f latest.tar.gz
mv /var/www/wp-config.php /var/www/ft_server/wordpress/

# Nginx
echo "nginx"
mv /var/www/nginx.conf /etc/nginx/sites-available/default
service nginx start

/bin/bash
