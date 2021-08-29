CC=g++ -std=c++11
CFLAGS=-Wall -g
TARGET=PA2


#sets C_SRCS equal to any c files found in the folder/folders automatically 
C++_SRCS := \
	$(wildcard *.cpp) \
	$(wildcard src/*.cpp) \
	$(wildcard src/**/*.cpp)
#sets HDRS equal to any header files found in the folder/folders automatically 
HDRS := \
	$(wildcard *.h) \
	$(wildcard src/*.h) \
	$(wildcard src/**/*.h)

#Link all built objects this compiles our code
build:
				$(CC) $(CFLAGS) $(C++_SRCS) -o $(TARGET)


#this removes the lab4 executable and bin folder
clean:
				rm $(TARGET)

#this runs the executable lab4 aka ./lab4
run: build

				./$(TARGET) watercraft.txt

# this prints out to the terminal the sources, headers, and 
#objs that the makefile has found in the folders
which:
				@echo "FOUND SOURCES: ${C++_SRCS}"
				@echo "FOUND HEADERS: ${HDRS}"