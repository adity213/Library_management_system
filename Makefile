CXX = g++
CXXFLAGS = -std=c++11 -Iinclude

SRCS = src/main.cpp src/LMS.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = LibrarySystem

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
