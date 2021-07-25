#!/usr/bin/env bash

echo ">>> STARTING WORDPRESS"
sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/" "/etc/php/7.3/fpm/pool.d/www.conf"

mkdir -p /run/php/
touch /run/php/php7.3-fpm.pid
chown -R www-data:www-data /var/www/*
chmod -R 755 /var/www/*
mkdir -p /var/www/html/

if [ ! -f /var/www/html/wp-config.php ]; then
	echo ">>> DOWNLOADING WORDPRESS"
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp

	echo ">>> INSTALLING WORDPRESS"
	cd var/www/html/
	wp core download --allow-root

	echo ">>> CINFIGURING WORDPRESS"
	sed -i "s/__MYSQL_DATABASE__/${MYSQL_DATABASE}/" "/var/www/wp-config.php"
	sed -i "s/__MYSQL_USER__/${MYSQL_USER}/"         "/var/www/wp-config.php"
	sed -i "s/__MYSQL_PASSWORD__/${MYSQL_PASSWORD}/" "/var/www/wp-config.php"
	sed -i "s/__MYSQL_HOST__/${MYSQL_HOSTNAME}/"         "/var/www/wp-config.php"
	mv /var/www/wp-config.php /var/www/html/
	wp core install --allow-root \
		--url=${DOMAIN_NAME} \
		--title=${WORDPRESS_WEBSITE_TITLE} \
		--admin_user=${WORDPRESS_ADMIN_USER} \
		--admin_password=${WORDPRESS_ADMIN_PASSWORD} \
		--admin_email=${WORDPRESS_ADMIN_EMAIL}
	wp user create --allow-root \
		${WORDPRESS_USER_USER} \
		${WORDPRESS_USER_EMAIL} \
		--user_pass=${WORDPRESS_USER_PASSWORD}
fi
echo ">>> WORDPRESS DONE"

exec "$@"
