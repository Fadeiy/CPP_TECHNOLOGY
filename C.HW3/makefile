CPPFLAGS     = -std=c++17
LDFLAGS      = -L. -lmylib
CXX          = g++
DEFINE_NAME  = -DNAME=\"Sergey\"
STATIC_LIB   = libmylib.a
LIB_NAME     = mylib
LIB_OBJECTS  = hello.o here.o bye.o
EXECUTABLE   = result
 
all: $(EXECUTABLE)
 
$(EXECUTABLE): main.o
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^
 
$(STATIC_LIB): $(LIB_OBJECTS)
	ar rcs $@ $^
 
main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $^
 
hello.o: hello.cpp
	$(CXX) $(CPPFLAGS) $(DEFINE_NAME) -c -o $@ $^
 
here.o: here.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $^
 
bye.o: bye.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $^
 
 
dynamic_lib : $(LIB_OBJECTS)
	$(CXX) $(CPPFLAGS) -dynamiclib -o lib$(LIB_NAME).dylib $^
 
clean:
	rm -rf *.o *.a lib$(LIB_NAME).* result
