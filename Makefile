CXX = g++
CXXFLAGS = -O3 -std=c++20 -Wall -Wextra -pedantic
INCLUDE = -I $(DNEST4_PATH)
LINK = -L $(DNEST4_PATH)/DNest4/code

default:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c Collection.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c MyModel.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c main.cpp
	$(CXX) $(LINK) -o main *.o -ldnest4

