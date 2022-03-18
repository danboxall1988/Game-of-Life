#OBJS specifies which files to compile as part of the project 
OBJS = cell.cpp main.cpp board.cpp
#CC specifies which compiler we're using - specify path to msys2 if needed 
CC = g++ 
#INCLUDE_PATHS specifies the additional include paths we'll need 
#INCLUDE_PATHS = -I C:\SDL2\include\ 
#LIBRARY_PATHS specifies the additional library paths we'll need 
LIBRARY_PATHS = -L /usr/lib
#COMPILER_FLAGS specifies the additional compilation options we're using 
# -w suppresses all warnings 
# -Wl,-subsystem,windows gets rid of the console window 
COMPILER_FLAGS = #-Wl,-subsystem,windows 
#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = main
#This is the target that compiles our executable 
all : $(OBJS) 
	$(CC) $(OBJS) $(LIBRARY_PATHS) $(LINKER_FLAGS) $(COMPILER_FLAGS) -o $(OBJ_NAME)


