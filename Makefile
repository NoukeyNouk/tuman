tuman: obj/main.o obj/my_list.o
	mkdir -p obj
	gcc -g obj/main.o obj/my_list.o -o tuman

obj/%.o: src/%.c
	gcc -c -g $< -o $@

clean:
	rm -f obj/* tuman
