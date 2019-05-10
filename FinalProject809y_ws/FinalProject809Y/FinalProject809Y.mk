##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=FinalProject809Y
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Brenda/Documents/final809y/FinalProject809y_ws
ProjectPath            :=C:/Users/Brenda/Documents/final809y/FinalProject809y_ws/FinalProject809Y
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Brenda
Date                   :=10/05/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="FinalProject809Y.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/ar.exe rcu
CXX      := C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe
CC       := C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe
CXXFLAGS := -std=c++14 -Wall -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Maze_maze.cpp$(ObjectSuffix) $(IntermediateDirectory)/RobotModel_wheeledRobot.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/RobotModel_trackedRobot.cpp$(ObjectSuffix) $(IntermediateDirectory)/RobotModel_mobilerobot.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Maze_maze.cpp$(ObjectSuffix): Maze/maze.cpp $(IntermediateDirectory)/Maze_maze.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Brenda/Documents/final809y/FinalProject809y_ws/FinalProject809Y/Maze/maze.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Maze_maze.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Maze_maze.cpp$(DependSuffix): Maze/maze.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Maze_maze.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Maze_maze.cpp$(DependSuffix) -MM Maze/maze.cpp

$(IntermediateDirectory)/Maze_maze.cpp$(PreprocessSuffix): Maze/maze.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Maze_maze.cpp$(PreprocessSuffix) Maze/maze.cpp

$(IntermediateDirectory)/RobotModel_wheeledRobot.cpp$(ObjectSuffix): RobotModel/wheeledRobot.cpp $(IntermediateDirectory)/RobotModel_wheeledRobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Brenda/Documents/final809y/FinalProject809y_ws/FinalProject809Y/RobotModel/wheeledRobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RobotModel_wheeledRobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RobotModel_wheeledRobot.cpp$(DependSuffix): RobotModel/wheeledRobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RobotModel_wheeledRobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RobotModel_wheeledRobot.cpp$(DependSuffix) -MM RobotModel/wheeledRobot.cpp

$(IntermediateDirectory)/RobotModel_wheeledRobot.cpp$(PreprocessSuffix): RobotModel/wheeledRobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RobotModel_wheeledRobot.cpp$(PreprocessSuffix) RobotModel/wheeledRobot.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Brenda/Documents/final809y/FinalProject809y_ws/FinalProject809Y/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/RobotModel_trackedRobot.cpp$(ObjectSuffix): RobotModel/trackedRobot.cpp $(IntermediateDirectory)/RobotModel_trackedRobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Brenda/Documents/final809y/FinalProject809y_ws/FinalProject809Y/RobotModel/trackedRobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RobotModel_trackedRobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RobotModel_trackedRobot.cpp$(DependSuffix): RobotModel/trackedRobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RobotModel_trackedRobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RobotModel_trackedRobot.cpp$(DependSuffix) -MM RobotModel/trackedRobot.cpp

$(IntermediateDirectory)/RobotModel_trackedRobot.cpp$(PreprocessSuffix): RobotModel/trackedRobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RobotModel_trackedRobot.cpp$(PreprocessSuffix) RobotModel/trackedRobot.cpp

$(IntermediateDirectory)/RobotModel_mobilerobot.cpp$(ObjectSuffix): RobotModel/mobilerobot.cpp $(IntermediateDirectory)/RobotModel_mobilerobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Brenda/Documents/final809y/FinalProject809y_ws/FinalProject809Y/RobotModel/mobilerobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RobotModel_mobilerobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RobotModel_mobilerobot.cpp$(DependSuffix): RobotModel/mobilerobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RobotModel_mobilerobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RobotModel_mobilerobot.cpp$(DependSuffix) -MM RobotModel/mobilerobot.cpp

$(IntermediateDirectory)/RobotModel_mobilerobot.cpp$(PreprocessSuffix): RobotModel/mobilerobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RobotModel_mobilerobot.cpp$(PreprocessSuffix) RobotModel/mobilerobot.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


