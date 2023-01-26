CXX ?= g++

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -g
else
    CXXFLAGS += -O2

endif

tictactoe: main.cpp  ./GameHandler.cpp
	$(CXX) -o tictactoe  $^ $(CXXFLAGS)  -I/games/tgbot-cpp/include -lTgBot -lboost_system -lssl -lcrypto -lpthread

clean:
	rm  -r tictactoe