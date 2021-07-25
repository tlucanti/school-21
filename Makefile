all:
	docker-compose -f srcs/docker-compose.yaml up

stop:
	docker-compose -f srcs/docker-compose.yaml down

build:
	docker-compose -f srcs/docker-compose.yaml up --build

re:
	sudo rm -rf /home/tlucanti/data/wp/*
	sudo rm -rf /home/tlucanti/data/db/*
	make clean

clean:
	docker stop $$(docker ps -qa); \
	docker rm $$(docker ps -qa); \
	docker rmi -f $$(docker images -qa); \
	docker volume rm $$(docker volume ls -q); \
	docker network rm $$(docker network ls -q)
