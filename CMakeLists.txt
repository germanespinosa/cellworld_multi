cmake_minimum_required( VERSION 3.10 )

set(CMAKE_CXX_STANDARD 17)

project( cellworld_multi
        VERSION 2019.1.0
        DESCRIPTION "Cellworld simulation"
        LANGUAGES CXX)

find_package(Cellworld_tools REQUIRED)

set (cellworld_multi_files
        src/predator.cpp
        src/planner.cpp
        src/poi_prey.cpp
        src/simulation.cpp
        src/particle_filter.cpp
        src/reward.cpp
        src/static_data.cpp
        src/search_tree.cpp
        )

add_library( cellworld_multi ${cellworld_multi_files})

target_link_libraries ( cellworld_multi ${CELLWORLD_TOOLS_LIBRARIES})

target_include_directories(cellworld_multi
        PUBLIC
        include )

add_executable(cellworld_run src/run.cpp)
target_link_libraries( cellworld_run  cellworld_multi)


###
### TESTS
###
find_package(CatchTests CONFIG QUIET)


###
### SIMULATION INSTALLATION
###

if (CMAKE_BUILD_TYPE MATCHES Release)

    include(GNUInstallDirs)

    install(TARGETS cellworld_run
            RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

endif()