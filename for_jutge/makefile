OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: program.o poblacio.o individu.o parell_cromosomes.o especie.o
	g++ -o program.exe *.o

poblacio.o: poblacio.cc poblacio.hh individu.hh
	g++ -c poblacio.cc $(OPCIONS)

individu.o: individu.cc individu.hh parell_cromosomes.hh especie.hh
	g++ -c individu.cc $(OPCIONS)

parell_cromosomes.o: parell_cromosomes.cc parell_cromosomes.hh
	g++ -c parell_cromosomes.cc $(OPCIONS)

especie.o: especie.cc especie.hh
	g++ -c especie.cc $(OPCIONS)

program.o: program.cc poblacio.hh 
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
