# makefile
# Project 1
# Samuel Lamb

STLHOME   = /home/courses/cop4530p/LIB
STLCPP    = $(STLHOME)/cpp
STLTCPP   = $(STLHOME)/tcpp
AREA51 = $(STLHOME)/area51
STLTESTS  = $(STLHOME)/tests

CC     = g++ -std=c++11 -Wall -Wextra 
INC    = -I. -I$(STLCPP) -I$(STLTCPP)
#CC     = clang++ -std=c++11 -I. -I$(STLCPP) -I$(STLTCPP)

all: flist2c.x mlist2c.x flist.x mlist.x

flist2c.x: flist2c.cpp list2c.h list2c.cpp
	$(CC) -o flist2c.x $(INC) flist2c.cpp

mlist2c.x: mlist2c.cpp list2c.h list2c.cpp
	$(CC) -o mlist2c.x $(INC) mlist2c.cpp

flist.x: 
	$(CC) -o flist2c.x $(INC) flist.cpp 

mlist.x: 
	$(CC) -o mlist2c.x $(INC) mlist.cpp 


# makefile2c
# Project 1
# Samuel Lamb

#STLHOME   = /STLHOME/courses/cop4530p/LIB
#STLCPP    = $(STLHOME)/cpp
#STLTCPP   = $(STLHOME)/tcpp
#AREA51 = $(STLHOME)/area51
#STLTESTS  = $(STLHOME)/tests

#CC     = g++ -std=c++11 -Wall -Wextra -I. -I$(STLCPP) -I$(STLTCPP)
#CC     = clang++ -std=c++11 -I. -I$(STLCPP) -I$(STLTCPP)

#all: flist2c.x  mlist2c.x flist.x mlist.x

#flist2c.x: flist2c.cpp list2c.h $(STLTCPP)/ansicodes.h $(STLTCPP)/compare.h $(STLCPP)/xstring.cpp $(STLCPP)/xstring.h
#	$(CC) -o flist2c.x flist2c.cpp

#mlist2c.x: mlist2c.cpp list2c.h $(STLCPP)/xran.h
#	$(CC) -o mlist2c.x mlist2c.cpp

#flist.x: $(STLTESTS)/flist.cpp $(STLTCPP)/list.h $(STLTCPP)/ansicodes.h $(STLTCPP)/compare.h\
$(STLCPP)/xstring.cpp $(STLCPP)/xstring.h
#	$(CC) -o flist.x $(STLTESTS)/flist.cpp 

#mlist.x: $(STLTESTS)/mlist.cpp $(STLTCPP)/list.h $(STLCPP)/xran.h $(STLCPP)/xranxstr.h $(STLCPP)/xstring.h
#	$(CC) -o mlist.x $(STLTESTS)/mlist.cpp 
