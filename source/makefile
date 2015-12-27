WORKDIR = %cd%

CC = gcc
CXX = g++
AR = ar
LD = g++

WINDRES = windres

INC = -I. -Ilib -Ivaultlib
CFLAGS = -pedantic-errors -pedantic -Wfatal-errors -Wextra -Wall -std=gnu++1y
CFLAGSEXT =
RESINC =
RCFLAGS = -F pe-i386
LIBDIR =
LIB = -Llib\\RakNet -Llib\\iniparser -Lvaultlib -Llib\\ufmod
LDFLAGS = -m32 -lvaultlib -liniparser -lRakNet -lufmod -lshlwapi -lcomctl32 -lwinmm -lws2_32 -lz -limagehlp -static -mwindows

INC_DEBUG = $(INC) -Ilib\\stack_trace\\include
CFLAGS_DEBUG = $(CFLAGS) -gstabs -DVAULTMP_DEBUG -DPACKAGE -DPACKAGE_VERSION
CFLAGSEXT_DEBUG = $(CFLAGSEXT)
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = -lbfd -liberty $(LDFLAGS)
OBJDIR_DEBUG = .objs\\Debug
DEP_DEBUG =
OUT_DEBUG = vaultmpd.exe

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2 -DNDEBUG
CFLAGSEXT_RELEASE = $(CFLAGSEXT) -O2 -DNDEBUG
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = -s $(LDFLAGS)
OBJDIR_RELEASE = .objs\\Release
DEP_RELEASE =
OUT_RELEASE = vaultmp.exe

OBJ_DEBUG = \
$(OBJDIR_DEBUG)\\lib\\stack_trace\\src\\stack.o \
$(OBJDIR_DEBUG)\\Pipe.o \
$(OBJDIR_DEBUG)\\Reference.o \
$(OBJDIR_DEBUG)\\vaultmp.o \
$(OBJDIR_DEBUG)\\vaultmprc.o \
$(OBJDIR_DEBUG)\\GameFactory.o \
$(OBJDIR_DEBUG)\\Game.o \
$(OBJDIR_DEBUG)\\Bethesda.o \
$(OBJDIR_DEBUG)\\Actor.o \
$(OBJDIR_DEBUG)\\API.o \
$(OBJDIR_DEBUG)\\Player.o \
$(OBJDIR_DEBUG)\\Object.o \
$(OBJDIR_DEBUG)\\NetworkClient.o \
$(OBJDIR_DEBUG)\\Interface.o \
$(OBJDIR_DEBUG)\\Base.o \
$(OBJDIR_DEBUG)\\Item.o \
$(OBJDIR_DEBUG)\\Container.o \
$(OBJDIR_DEBUG)\\ItemList.o \
$(OBJDIR_DEBUG)\\components\\Window.o \
$(OBJDIR_DEBUG)\\components\\Button.o \
$(OBJDIR_DEBUG)\\components\\Text.o \
$(OBJDIR_DEBUG)\\components\\Edit.o \
$(OBJDIR_DEBUG)\\components\\Checkbox.o \
$(OBJDIR_DEBUG)\\components\\RadioButton.o \
$(OBJDIR_DEBUG)\\components\\ListItem.o \
$(OBJDIR_DEBUG)\\components\\List.o

OBJ_RELEASE = \
$(OBJDIR_RELEASE)\\Pipe.o \
$(OBJDIR_RELEASE)\\Reference.o \
$(OBJDIR_RELEASE)\\vaultmp.o \
$(OBJDIR_RELEASE)\\vaultmprc.o \
$(OBJDIR_RELEASE)\\GameFactory.o \
$(OBJDIR_RELEASE)\\Game.o \
$(OBJDIR_RELEASE)\\Bethesda.o \
$(OBJDIR_RELEASE)\\Actor.o \
$(OBJDIR_RELEASE)\\API.o \
$(OBJDIR_RELEASE)\\Player.o \
$(OBJDIR_RELEASE)\\Object.o \
$(OBJDIR_RELEASE)\\NetworkClient.o \
$(OBJDIR_RELEASE)\\Interface.o \
$(OBJDIR_RELEASE)\\Base.o \
$(OBJDIR_RELEASE)\\Item.o \
$(OBJDIR_RELEASE)\\Container.o \
$(OBJDIR_RELEASE)\\ItemList.o \
$(OBJDIR_RELEASE)\\components\\Window.o \
$(OBJDIR_RELEASE)\\components\\Button.o \
$(OBJDIR_RELEASE)\\components\\Text.o \
$(OBJDIR_RELEASE)\\components\\Edit.o \
$(OBJDIR_RELEASE)\\components\\Checkbox.o \
$(OBJDIR_RELEASE)\\components\\RadioButton.o \
$(OBJDIR_RELEASE)\\components\\ListItem.o \
$(OBJDIR_RELEASE)\\components\\List.o

all: debug release

clean: clean_debug clean_release

before_debug:
	cmd /c if not exist $(OBJDIR_DEBUG) md $(OBJDIR_DEBUG)
	cmd /c if not exist $(OBJDIR_DEBUG)\\lib\\stack_trace\\src md $(OBJDIR_DEBUG)\\lib\\stack_trace\\src
	cmd /c if not exist $(OBJDIR_DEBUG)\\components md $(OBJDIR_DEBUG)\\components

after_debug:

debug: before_debug out_debug after_debug

out_debug: $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) $(OBJ_DEBUG) $(LIB_DEBUG) -o $(OUT_DEBUG) $(LDFLAGS_DEBUG)

$(OBJDIR_DEBUG)\\lib\\stack_trace\\src\\stack.o: lib\\stack_trace\\src\\stack.cpp
	$(CXX) $(CFLAGSEXT_DEBUG) $(INC_DEBUG) -c lib\\stack_trace\\src\\stack.cpp -o $(OBJDIR_DEBUG)\\lib\\stack_trace\\src\\stack.o

$(OBJDIR_DEBUG)\\Pipe.o: Pipe.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Pipe.cpp -o $(OBJDIR_DEBUG)\\Pipe.o

$(OBJDIR_DEBUG)\\Reference.o: Reference.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Reference.cpp -o $(OBJDIR_DEBUG)\\Reference.o

$(OBJDIR_DEBUG)\\vaultmp.o: resources\\vaultmp.rc vaultmp.cpp
	$(WINDRES) $(RCFLAGS_DEBUG) $(RESINC_DEBUG) -o $(OBJDIR_DEBUG)\\vaultmprc.o resources\\vaultmp.rc
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c vaultmp.cpp -o $(OBJDIR_DEBUG)\\vaultmp.o

$(OBJDIR_DEBUG)\\GameFactory.o: GameFactory.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c GameFactory.cpp -o $(OBJDIR_DEBUG)\\GameFactory.o

$(OBJDIR_DEBUG)\\Game.o: Game.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Game.cpp -o $(OBJDIR_DEBUG)\\Game.o

$(OBJDIR_DEBUG)\\Bethesda.o: Bethesda.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Bethesda.cpp -o $(OBJDIR_DEBUG)\\Bethesda.o

$(OBJDIR_DEBUG)\\Actor.o: Actor.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Actor.cpp -o $(OBJDIR_DEBUG)\\Actor.o

$(OBJDIR_DEBUG)\\API.o: API.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c API.cpp -o $(OBJDIR_DEBUG)\\API.o

$(OBJDIR_DEBUG)\\Player.o: Player.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Player.cpp -o $(OBJDIR_DEBUG)\\Player.o

$(OBJDIR_DEBUG)\\Object.o: Object.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Object.cpp -o $(OBJDIR_DEBUG)\\Object.o

$(OBJDIR_DEBUG)\\NetworkClient.o: NetworkClient.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c NetworkClient.cpp -o $(OBJDIR_DEBUG)\\NetworkClient.o

$(OBJDIR_DEBUG)\\Interface.o: Interface.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Interface.cpp -o $(OBJDIR_DEBUG)\\Interface.o

$(OBJDIR_DEBUG)\\Base.o: Base.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Base.cpp -o $(OBJDIR_DEBUG)\\Base.o

$(OBJDIR_DEBUG)\\Item.o: Item.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Item.cpp -o $(OBJDIR_DEBUG)\\Item.o

$(OBJDIR_DEBUG)\\Container.o: Container.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Container.cpp -o $(OBJDIR_DEBUG)\\Container.o

$(OBJDIR_DEBUG)\\ItemList.o: ItemList.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ItemList.cpp -o $(OBJDIR_DEBUG)\\ItemList.o

$(OBJDIR_DEBUG)\\components\\Window.o: components\\Window.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c components\\Window.cpp -o $(OBJDIR_DEBUG)\\components\\Window.o

$(OBJDIR_DEBUG)\\components\\Button.o: components\\Button.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c components\\Button.cpp -o $(OBJDIR_DEBUG)\\components\\Button.o

$(OBJDIR_DEBUG)\\components\\Text.o: components\\Text.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c components\\Text.cpp -o $(OBJDIR_DEBUG)\\components\\Text.o

$(OBJDIR_DEBUG)\\components\\Edit.o: components\\Edit.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c components\\Edit.cpp -o $(OBJDIR_DEBUG)\\components\\Edit.o

$(OBJDIR_DEBUG)\\components\\Checkbox.o: components\\Checkbox.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c components\\Checkbox.cpp -o $(OBJDIR_DEBUG)\\components\\Checkbox.o

$(OBJDIR_DEBUG)\\components\\RadioButton.o: components\\RadioButton.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c components\\RadioButton.cpp -o $(OBJDIR_DEBUG)\\components\\RadioButton.o

$(OBJDIR_DEBUG)\\components\\ListItem.o: components\\ListItem.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c components\\ListItem.cpp -o $(OBJDIR_DEBUG)\\components\\ListItem.o

$(OBJDIR_DEBUG)\\components\\List.o: components\\List.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c components\\List.cpp -o $(OBJDIR_DEBUG)\\components\\List.o

clean_debug:
	cmd /c del /f $(OBJ_DEBUG) $(OUT_DEBUG)
	cmd /c rd /s/q $(OBJDIR_DEBUG)

before_release:
	cmd /c if not exist $(OBJDIR_RELEASE) md $(OBJDIR_RELEASE)
	cmd /c if not exist $(OBJDIR_RELEASE)\\components md $(OBJDIR_RELEASE)\\components

after_release:

release: before_release out_release after_release

out_release: $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) $(OBJ_RELEASE) $(LIB_RELEASE) -o $(OUT_RELEASE) $(LDFLAGS_RELEASE)

$(OBJDIR_RELEASE)\\Pipe.o: Pipe.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Pipe.cpp -o $(OBJDIR_RELEASE)\\Pipe.o

$(OBJDIR_RELEASE)\\Reference.o: Reference.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Reference.cpp -o $(OBJDIR_RELEASE)\\Reference.o

$(OBJDIR_RELEASE)\\vaultmp.o: resources\\vaultmp.rc vaultmp.cpp
	$(WINDRES) $(RCFLAGS_RELEASE) $(RESINC_RELEASE) -o $(OBJDIR_RELEASE)\\vaultmprc.o resources\\vaultmp.rc
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c vaultmp.cpp -o $(OBJDIR_RELEASE)\\vaultmp.o

$(OBJDIR_RELEASE)\\GameFactory.o: GameFactory.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c GameFactory.cpp -o $(OBJDIR_RELEASE)\\GameFactory.o

$(OBJDIR_RELEASE)\\Game.o: Game.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Game.cpp -o $(OBJDIR_RELEASE)\\Game.o

$(OBJDIR_RELEASE)\\Bethesda.o: Bethesda.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Bethesda.cpp -o $(OBJDIR_RELEASE)\\Bethesda.o

$(OBJDIR_RELEASE)\\Actor.o: Actor.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Actor.cpp -o $(OBJDIR_RELEASE)\\Actor.o

$(OBJDIR_RELEASE)\\API.o: API.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c API.cpp -o $(OBJDIR_RELEASE)\\API.o

$(OBJDIR_RELEASE)\\Player.o: Player.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Player.cpp -o $(OBJDIR_RELEASE)\\Player.o

$(OBJDIR_RELEASE)\\Object.o: Object.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Object.cpp -o $(OBJDIR_RELEASE)\\Object.o

$(OBJDIR_RELEASE)\\NetworkClient.o: NetworkClient.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c NetworkClient.cpp -o $(OBJDIR_RELEASE)\\NetworkClient.o

$(OBJDIR_RELEASE)\\Interface.o: Interface.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Interface.cpp -o $(OBJDIR_RELEASE)\\Interface.o

$(OBJDIR_RELEASE)\\Base.o: Base.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Base.cpp -o $(OBJDIR_RELEASE)\\Base.o

$(OBJDIR_RELEASE)\\Item.o: Item.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Item.cpp -o $(OBJDIR_RELEASE)\\Item.o

$(OBJDIR_RELEASE)\\Container.o: Container.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Container.cpp -o $(OBJDIR_RELEASE)\\Container.o

$(OBJDIR_RELEASE)\\ItemList.o: ItemList.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ItemList.cpp -o $(OBJDIR_RELEASE)\\ItemList.o

$(OBJDIR_RELEASE)\\components\\Window.o: components\\Window.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c components\\Window.cpp -o $(OBJDIR_RELEASE)\\components\\Window.o

$(OBJDIR_RELEASE)\\components\\Button.o: components\\Button.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c components\\Button.cpp -o $(OBJDIR_RELEASE)\\components\\Button.o

$(OBJDIR_RELEASE)\\components\\Text.o: components\\Text.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c components\\Text.cpp -o $(OBJDIR_RELEASE)\\components\\Text.o

$(OBJDIR_RELEASE)\\components\\Edit.o: components\\Edit.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c components\\Edit.cpp -o $(OBJDIR_RELEASE)\\components\\Edit.o

$(OBJDIR_RELEASE)\\components\\Checkbox.o: components\\Checkbox.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c components\\Checkbox.cpp -o $(OBJDIR_RELEASE)\\components\\Checkbox.o

$(OBJDIR_RELEASE)\\components\\RadioButton.o: components\\RadioButton.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c components\\RadioButton.cpp -o $(OBJDIR_RELEASE)\\components\\RadioButton.o

$(OBJDIR_RELEASE)\\components\\ListItem.o: components\\ListItem.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c components\\ListItem.cpp -o $(OBJDIR_RELEASE)\\components\\ListItem.o

$(OBJDIR_RELEASE)\\components\\List.o: components\\List.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c components\\List.cpp -o $(OBJDIR_RELEASE)\\components\\List.o

clean_release:
	cmd /c del /f $(OBJ_RELEASE) $(OUT_RELEASE)
	cmd /c rd /s/q $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

