CXX = g++
CXXFLAGS = -std=c++20 -Iinclude

SRCS = $(wildcard src/*.cpp)
OBJS = $(addprefix build/, $(notdir $(SRCS:.cpp=.o)))
EXEC = build/astar

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)

