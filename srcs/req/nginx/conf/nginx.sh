#!/usr/bin/env bash

echo ">>> STARTING NGINX"

openssl req -newkey rsa:4096 -x509 -sha256 -days 3650 -nodes -out /etc/nginx/certificate.crt \
-keyout /etc/nginx/private.key -subj "/C=RU/ST=Moscow/L=Moscow /O=21 School/OU=tlucanti/CN=tlucanti.42.fr/emailAddress=tlucanti@42.fr"
mv /var/www/nginx.conf /etc/nginx/sites-available/default

echo ">>> NGINX DONE"
exec "$@"
