TARGET = main
OBJS = main.o

CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

.cpp.o:
	$(CXX) -c -o $@ $< $(CFLAGS)

clean:
	$(RM) $(TARGET) $(OBJS) *~