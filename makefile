lltest: ll.c
	gcc ll.c -o ll

clean:
	rm ll

run: lltest
	./ll
