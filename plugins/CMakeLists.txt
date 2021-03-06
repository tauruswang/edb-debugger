cmake_minimum_required (VERSION 3.0)

add_definitions(-DQT_PLUGIN)

add_subdirectory(DebuggerCore)
add_subdirectory(Analyzer)
add_subdirectory(Assembler)
add_subdirectory(BinaryInfo)
add_subdirectory(Bookmarks)
add_subdirectory(BreakpointManager)
add_subdirectory(CheckVersion)
add_subdirectory(OpcodeSearcher)
add_subdirectory(ProcessProperties)
add_subdirectory(ROPTool)
add_subdirectory(References)
add_subdirectory(SymbolViewer)
add_subdirectory(Backtrace)
add_subdirectory(DumpState)
add_subdirectory(FunctionFinder)
add_subdirectory(DebuggerErrorConsole)
add_subdirectory(BinarySearcher)
add_subdirectory(InstructionInspector)

# NOTE(eteran): this is deprecated, will be removed at some point in the future...
if(${BUILD_SIMPLE_REGISTER_VIEW})
	add_subdirectory(SimpleRegView)
endif()

if(TARGET_ARCH_FAMILY_X86)
	add_subdirectory(HardwareBreakpoints)
endif()

if(TARGET_PLATFORM_LINUX)
    add_subdirectory(HeapAnalyzer)
endif()

if (NOT TARGET_COMPILER_MSVC)
	# TODO(eteran): having a hard time getting these to compile under MSVC
	add_subdirectory(ODbgRegisterView)
endif()



