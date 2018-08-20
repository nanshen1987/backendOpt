cmake_minimum_required(VERSION 3.5)
project(backendOpt)

set(CMAKE_CXX_STANDARD 11)

# find_package(OpenCV 4.0 REQUIRED)
# include_directories(${OpenCV_INCLUDE_DIRS})

# include_directories("/usr/include/eigen3/")

# find_package(Sophus REQUIRED)
# include_directories(${Sophus_INCLUDE_DIRS})

# find_package( G2O REQUIRED )
# include_directories(
        # ${G2O_INCLUDE_DIRS}
# )

add_executable(backendOpt main.cpp common/flags/CommandArgs.cpp common/flags/CommandArgs.h common/BundleParams.h common/projection.h common/BALProblem.cpp common/BALProblem.h)