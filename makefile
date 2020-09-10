CXX = g++					  #compiler
CXXFLAGS = -std=c++11		  #compiler standard
CXXFLAGS += -Wall             #turns on all warnings
CXXFLAGS += -pedantic-errors  #stick to std, notify if vilate
CXXFLAGS += -g                #for debugging
CXXFLAGS += -O3               #for optimization, off while debugging mode    
LDFLAGS = -lboost_date_time

#Protect against file names matching those listed
.PHONY: clean zip

#Source files
SRCS = Space.cpp MainRoom.cpp Room1.cpp Room2.cpp Room3.cpp Room4.cpp \
BananaRoom.cpp Game.cpp Menu.cpp ValidateNum.cpp main.cpp

#Object file created for each source file
OBJS = $(SRCS:.cpp=.o)

#Header files:
HEADERS = Space.hpp MainRoom.hpp Room1.hpp Room2.hpp Room3.hpp Room4.hpp \
BananaRoom.hpp Game.hpp Menu.hpp ValidateNum.hpp

monkeyMind: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o monkeyMind

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

#Removes executable and object files. NOTE: must type 'make clean'
clean:
	-rm monkeyMind $(OBJS)