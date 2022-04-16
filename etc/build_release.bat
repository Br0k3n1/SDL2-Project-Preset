set "parentDir=%CD%"

::Updates res folder in release
del "bin/release/res" /-p
xcopy res "bin/release/res" /y /e

::Builds src files in release
cd bin/release
g++ -c %parentDir%/src/*.cpp -std=c++14 -O3 -Wall -m64 -I%parentDir%/include -I%parentDir%/include/sdl -I%parentDir%include/headers 
g++ *.o -o main -s -L%parentDir%/lib/SDL2 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 
cd ../..

::Runs main.exe
start bin/release/main.exe