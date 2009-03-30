#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Debug/MinGW-Windows

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../OPSCrossPlatformCppLib/dist/Debug/MinGW-Windows -lopscrossplatformcpplib -lws2_32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/MinGW-Windows/testopscrossplatformcpplib.exe

dist/Debug/MinGW-Windows/testopscrossplatformcpplib.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/MinGW-Windows
	${LINK.cc} -o dist/Debug/MinGW-Windows/testopscrossplatformcpplib ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../OPSCrossPlatformCppLib/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/MinGW-Windows/testopscrossplatformcpplib.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
include .dep.inc
