CXX = g++
SRC_DIR = src
INC_DIR = include
LIB_DIR = libs
CXXFLAGS = -c -Wall -std=c++17 -I$(INC_DIR)

SFML_DIR = C:/SFML-3.0.2
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

EXTERNAL_LIBS = $(SFML_LIBS) -lm

LIB_CORE = libcore.a
LIB_GAME = libgame.a

CORE_SRCS = card.cpp rank.cpp suit.cpp
CORE_OBJS = $(CORE_SRCS:.cpp=.o)

GAME_SRCS = deck.cpp player.cpp
GAME_OBJS = $(GAME_SRCS:.cpp=.o)

APP_SRCS = main.cpp game_engine.cpp painter.cpp
APP_OBJS = $(APP_SRCS:.cpp=.o)

EXECUTABLE = CardGameDurak

all: $(LIB_DIR)/$(LIB_CORE) $(LIB_DIR)/$(LIB_GAME) $(EXECUTABLE)

$(EXECUTABLE): $(APP_OBJS) $(LIB_DIR)/$(LIB_CORE) $(LIB_DIR)/$(LIB_GAME)
	$(CXX) -o $(EXECUTABLE) $(APP_OBJS) -L$(LIB_DIR) -L$(SFML_DIR)/lib -lgame -lcore $(EXTERNAL_LIBS)

$(LIB_DIR)/$(LIB_CORE): $(CORE_OBJS) | $(LIB_DIR)
	ar rcs $@ $(CORE_OBJS)

$(LIB_DIR)/$(LIB_GAME): $(GAME_OBJS) | $(LIB_DIR)
	ar rcs $@ $(GAME_OBJS)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(CORE_OBJS) $(GAME_OBJS) $(APP_OBJS) $(EXECUTABLE)
	rm -rf $(LIB_DIR)

.PHONY: all clean