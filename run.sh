g++ -std=c++17 -c src/ray.cpp -o bin/ray.o
g++ -std=c++17 -c src/rectangle.cpp -o bin/rectangle.o
g++ -std=c++17 main.cpp bin/*.o -lsfml-graphics -lsfml-window -lsfml-system -o main

./main