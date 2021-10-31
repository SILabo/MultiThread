# CMakeList.txt : 最上位の CMake プロジェクト ファイル。グローバル構成を行います
# また、サブプロジェクトをここに含めます。
#
cmake_minimum_required (VERSION 3.8)

file(GLOB SOURCE *.h *.hpp *.cpp)
#file(GLOB LIB_SOURCE libs/*.h libs/*.cpp)

add_executable(MultiThread
 ${SOURCE}
# ${LIB_SOURCE}
)

include_directories(/usr/include)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
target_link_libraries(MultiThread pthread)
