CXX = g++
CXXFLAGS = -O2 -std=c++17

all: lab1 lab2 lab3_O0 lab3_O2 homework

lab1: lab1_chrono.cpp
	$(CXX) $(CXXFLAGS) -o lab1 lab1_chrono.cpp

lab2: lab2_constref.cpp
	$(CXX) $(CXXFLAGS) -o lab2 lab2_constref.cpp

lab3_O0: lab3_primes.cpp
	$(CXX) -O0 -std=c++17 -o lab3_O0 lab3_primes.cpp

lab3_O2: lab3_primes.cpp
	$(CXX) $(CXXFLAGS) -o lab3_O2 lab3_primes.cpp

homework: homework_timer.cpp
	$(CXX) $(CXXFLAGS) -o homework homework_timer.cpp

run:
	@echo "=== Lab1: chrono ==="
	./lab1
	@echo ""
	@echo "=== Lab2: const& ==="
	./lab2
	@echo ""
	@echo "=== Lab3: C++ -O0 ==="
	./lab3_O0
	@echo ""
	@echo "=== Lab3: C++ -O2 ==="
	./lab3_O2
	@echo ""
	@echo "=== Lab3: Python ==="
	python3 lab3_primes.py
	@echo ""
	@echo "=== Homework: Timer + MovieManager ==="
	./homework | grep -E "\[Timer\]|검색|추천|총"

clean:
	rm -f lab1 lab2 lab3_O0 lab3_O2 homework