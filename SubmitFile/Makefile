CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = bb7k
OBJECTS = main.o Controller.o View.o Board.o TextDisplay.o Square.o Building.o AcademicBuilding.o CoopFee.o DCTimsLine.o Department.o GooseNesting.o GoToTims.o Gym.o NeedlesHall.o OSAP.o Player.o Residence.o SLC.o Tuition.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
