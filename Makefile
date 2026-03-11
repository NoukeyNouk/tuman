FILES = obj/main.o

DEP_FILES = $(FILES:.o=.d)

tuman: $(FILES)
	mkdir -p obj
	g++ -g $(FILES) -o tuman -lcpr -lcurl -lssl -lcrypto

obj/%.o: src/%.cpp
	g++ -c -g $< -o $@ -MMD -MP

clean:
	rm -f obj/* tuman

-include $(DEP_FILES)
