CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -O3

TARGET = program
SRCS = main.cpp graph.cpp routing.cpp simulation.cpp
OBJS = $(SRCS:%.cpp=objects/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

objects/%.o: %.cpp
	@mkdir -p objects
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf objects

.PHONY: all clean
