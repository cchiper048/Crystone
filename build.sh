if [ ! -d "./build" ]
then
    mkdir build
fi

g++ -O0 -g -Wall -Wextra $(find ./ -name '*.cpp') -o build/main -lSDL2
./build/main


# g++ -O3 -s -DNDEBUG $(find ./ -name '*.cpp') -o build/main -lSDL2 && ./build/main
