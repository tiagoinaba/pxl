CC = g++
CFLAGS = -Wall -Wextra -g
LIBS = -lSDL2
SRCS = src/main.cpp src/RenderEngine.cpp src/Cursor.cpp src/Pixel.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = pxl

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) src/*.o *~ $(MAIN)

