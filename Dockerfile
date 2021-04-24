FROM		debian:buster

RUN			apt-get	update
RUN			apt-get	-y upgrade
RUN			apt-get	install -y \
				php-fpm \
				php-mysql \
				php-mbstring \
				php-gd php-xml \
				wget \
				vim \
				nginx \
				default-mysql-server

EXPOSE		80 443
COPY		./srcs/ /var/www/
ENTRYPOINT	/var/www/init.sh
