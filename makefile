OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: all.o
	g++ -o program.exe *.o $(OPCIONS)

all.o:
	g++ -c *.cc $(OPCIONS)
	

clean:
	rm *.o
	rm *.exe
