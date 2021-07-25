FROM		debian:buster

RUN			apt-get update
RUN			apt-get -y upgrade
RUN			apt-get install -y openssl php-gd php-xml nginx procps

EXPOSE		443
COPY		./conf/nginx.conf /etc/nginx/sites-available/default
COPY		./conf/certificate.crt /etc/nginx/
COPY		./conf/private.key /etc/nginx/

ENTRYPOINT	["nginx"]
CMD			["-g", "daemon off;"]
