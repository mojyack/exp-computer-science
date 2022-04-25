CXX = clang++ -pipe -O3 -march=native -mrtm -std=c++20

all: out/1 out/2 out/3 out/4 out/5 out/6 out/7 out/8 out/9 out/10 out/11 out/12 out/13 out/14 out/15 out/16 out/18 out/24

out/1: 1/main.cpp
	$(CXX) -o $@ $^

out/2: 2/main.cpp
	$(CXX) -o $@ $^

out/3: 3/main.cpp
	$(CXX) -o $@ $^

out/4: 4/main.cpp
	$(CXX) -o $@ $^

out/5: 5/main.cpp
	$(CXX) -o $@ $^

out/6: 6/main.cpp
	$(CXX) -o $@ $^

out/7: 7/main.cpp
	$(CXX) -o $@ $^

out/8: 8/main.cpp
	$(CXX) -o $@ $^

out/9: 9/main.cpp
	$(CXX) -o $@ $^

out/10: 10/main.cpp
	$(CXX) -o $@ $^

out/11: 11/main.cpp
	$(CXX) -o $@ $^

out/12: 12/main.cpp
	$(CXX) -o $@ $^

out/13: 13/main.cpp
	$(CXX) -o $@ $^

out/14: 14/main.cpp
	$(CXX) -o $@ $^

out/15: 15/main.cpp
	$(CXX) -o $@ $^

out/16: 16/main.cpp
	$(CXX) -o $@ $^

out/18: 18/main.cpp
	$(CXX) -o $@ $^

out/24: 24/main.cpp
	$(CXX) -o $@ $^

clean:
	rm out/*
