##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=FinalProject809Y
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws"
ProjectPath            :="C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=i raja srinivas
Date                   :=11/05/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :="C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe"
SharedObjectLinkerName :="C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe" -shared -fPIC
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
RcCompilerName         :="C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/windres.exe"
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
AR       := "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/ar.exe" rcu
CXX      := "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe"
CC       := "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe"
CXXFLAGS := -std=c++14 -Wall -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Maze_maze.cpp$(ObjectSuffix) $(IntermediateDirectory)/LeftState.cpp$(ObjectSuffix) $(IntermediateDirectory)/UpState.cpp$(ObjectSuffix) $(IntermediateDirectory)/RobotState.cpp$(ObjectSuffix) $(IntermediateDirectory)/RobotModel_TrackedRobot.cpp$(ObjectSuffix) $(IntermediateDirectory)/RightState.cpp$(ObjectSuffix) $(IntermediateDirectory)/RobotModel_WheeledRobot.cpp$(ObjectSuffix) $(IntermediateDirectory)/DownState.cpp$(ObjectSuffix) $(IntermediateDirectory)/RobotModel_MobileRobot.cpp$(ObjectSuffix) \
	



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Maze_maze.cpp$(ObjectSuffix): Maze/maze.cpp $(IntermediateDirectory)/Maze_maze.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y/Maze/maze.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Maze_maze.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Maze_maze.cpp$(DependSuffix): Maze/maze.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Maze_maze.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Maze_maze.cpp$(DependSuffix) -MM Maze/maze.cpp

$(IntermediateDirectory)/Maze_maze.cpp$(PreprocessSuffix): Maze/maze.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Maze_maze.cpp$(PreprocessSuffix) Maze/maze.cpp

$(IntermediateDirectory)/LeftState.cpp$(ObjectSuffix): LeftState.cpp $(IntermediateDirectory)/LeftState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y/LeftState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LeftState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LeftState.cpp$(DependSuffix): LeftState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LeftState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LeftState.cpp$(DependSuffix) -MM LeftState.cpp

$(IntermediateDirectory)/LeftState.cpp$(PreprocessSuffix): LeftState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LeftState.cpp$(PreprocessSuffix) LeftState.cpp

$(IntermediateDirectory)/UpState.cpp$(ObjectSuffix): UpState.cpp $(IntermediateDirectory)/UpState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y/UpState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/UpState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/UpState.cpp$(DependSuffix): UpState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/UpState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/UpState.cpp$(DependSuffix) -MM UpState.cpp

$(IntermediateDirectory)/UpState.cpp$(PreprocessSuffix): UpState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/UpState.cpp$(PreprocessSuffix) UpState.cpp

$(IntermediateDirectory)/RobotState.cpp$(ObjectSuffix): RobotState.cpp $(IntermediateDirectory)/RobotState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y/RobotState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RobotState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RobotState.cpp$(DependSuffix): RobotState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RobotState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RobotState.cpp$(DependSuffix) -MM RobotState.cpp

$(IntermediateDirectory)/RobotState.cpp$(PreprocessSuffix): RobotState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RobotState.cpp$(PreprocessSuffix) RobotState.cpp

$(IntermediateDirectory)/RobotModel_TrackedRobot.cpp$(ObjectSuffix): RobotModel/TrackedRobot.cpp $(IntermediateDirectory)/RobotModel_TrackedRobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y/RobotModel/TrackedRobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RobotModel_TrackedRobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RobotModel_TrackedRobot.cpp$(DependSuffix): RobotModel/TrackedRobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RobotModel_TrackedRobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RobotModel_TrackedRobot.cpp$(DependSuffix) -MM RobotModel/TrackedRobot.cpp

$(IntermediateDirectory)/RobotModel_TrackedRobot.cpp$(PreprocessSuffix): RobotModel/TrackedRobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RobotModel_TrackedRobot.cpp$(PreprocessSuffix) RobotModel/TrackedRobot.cpp

$(IntermediateDirectory)/RightState.cpp$(ObjectSuffix): RightState.cpp $(IntermediateDirectory)/RightState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y/RightState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RightState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RightState.cpp$(DependSuffix): RightState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RightState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RightState.cpp$(DependSuffix) -MM RightState.cpp

$(IntermediateDirectory)/RightState.cpp$(PreprocessSuffix): RightState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RightState.cpp$(PreprocessSuffix) RightState.cpp

$(IntermediateDirectory)/RobotModel_WheeledRobot.cpp$(ObjectSuffix): RobotModel/WheeledRobot.cpp $(IntermediateDirectory)/RobotModel_WheeledRobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y/RobotModel/WheeledRobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RobotModel_WheeledRobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RobotModel_WheeledRobot.cpp$(DependSuffix): RobotModel/WheeledRobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RobotModel_WheeledRobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RobotModel_WheeledRobot.cpp$(DependSuffix) -MM RobotModel/WheeledRobot.cpp

$(IntermediateDirectory)/RobotModel_WheeledRobot.cpp$(PreprocessSuffix): RobotModel/WheeledRobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RobotModel_WheeledRobot.cpp$(PreprocessSuffix) RobotModel/WheeledRobot.cpp

$(IntermediateDirectory)/DownState.cpp$(ObjectSuffix): DownState.cpp $(IntermediateDirectory)/DownState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y/DownState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DownState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DownState.cpp$(DependSuffix): DownState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DownState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DownState.cpp$(DependSuffix) -MM DownState.cpp

$(IntermediateDirectory)/DownState.cpp$(PreprocessSuffix): DownState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DownState.cpp$(PreprocessSuffix) DownState.cpp

$(IntermediateDirectory)/RobotModel_MobileRobot.cpp$(ObjectSuffix): RobotModel/MobileRobot.cpp $(IntermediateDirectory)/RobotModel_MobileRobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/i raja srinivas/Documents/final809y/FinalProject809y_ws/FinalProject809Y/RobotModel/MobileRobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RobotModel_MobileRobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RobotModel_MobileRobot.cpp$(DependSuffix): RobotModel/MobileRobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RobotModel_MobileRobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RobotModel_MobileRobot.cpp$(DependSuffix) -MM RobotModel/MobileRobot.cpp

$(IntermediateDirectory)/RobotModel_MobileRobot.cpp$(PreprocessSuffix): RobotModel/MobileRobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RobotModel_MobileRobot.cpp$(PreprocessSuffix) RobotModel/MobileRobot.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


