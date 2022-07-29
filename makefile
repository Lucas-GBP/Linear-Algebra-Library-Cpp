CC = clang++
OUT_FILES = $(addsuffix .o,$(addprefix out/, main $(notdir $(basename $(wildcard libs/*.cpp)))))

executable.exe: $(OUT_FILES)
	$(CC) $(OUT_FILES) -o executable.exe

out/main.o: main.cpp main.hpp
	$(CC) -o out/main.o main.cpp -c

out/%.o: libs/%.cpp libs/%.hpp
	$(CC) -o $@ $< -c

run: executable.exe
	./executable.exe

clean:
	rm out/*.o executable.exe
	clear