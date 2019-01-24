cmake_minimum_required(VERSION 3.13)
project(std_lib_facilities_mac_xcodeproj)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(project.xcworkspace)
include_directories(xcuserdata)

add_executable(std_lib_facilities_mac_xcodeproj
        project.xcworkspace/xcshareddata/IDEWorkspaceChecks.plist
        project.xcworkspace/xcuserdata/larsmusaus.xcuserdatad/UserInterfaceState.xcuserstate
        project.xcworkspace/contents.xcworkspacedata
        xcuserdata/larsmusaus.xcuserdatad/xcschemes/xcschememanagement.plist
        project.pbxproj)
