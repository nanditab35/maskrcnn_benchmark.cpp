add_library(utils STATIC registry.cpp tovec.cpp timer.cpp bisect.cpp metric_logger.cpp checkpoint.cpp jit_to_cpp.cpp)
target_include_directories(utils 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../include/rcnn/utils/)
target_link_libraries(utils modeling solver)