restaurant: main.o functions.o linkList.o
	gcc -o restaurant main.o functions.o linkList.o

main.o: main.c restaurant.h
	gcc -c main.c

functions.o: functions.c restaurant.h
	gcc -c functions.c

linkList.o: linkList.c restaurant.h
	gcc -c linkList.c

clean:
	rm main.o functions.o linkList.o restaurant
