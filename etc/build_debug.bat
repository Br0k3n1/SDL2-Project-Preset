set "parentDir=%CD%"

::Updates res folder in debug
del "bin/debug/res" /-p
xcopy res "bin/debug/res" /y /e

::Builds src files in debug
cd bin/debug
g++ -c %parentDir%/src/*.cpp -std=c++14 -g -Wall -m64 -I%parentDir%/include -I%parentDir%/include/sdl -I%parentDir%/include/headers
g++ *.o -o main -L%parentDir%/lib/SDL2 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
cd ../..

::Runs main.exe
start bin/debug/main.exe