cmake_minimum_required(VERSION 2.8) #проверка версии cmake

set(PROJECT ImageRecognition) #присваиваем переменной PROJECT значение ImageRecognition

project(${PROJECT})

set(OpenCV_DIR C:/opencv/build)
message(${OpenCV_DIR})

macro(add_app_executable BUILD_TYPE) #макрос, выполняющий сборку с необходимыми параметрами в зависимости от значения входной переменной
	if (${BUILD_TYPE} STREQUAL "release")#если значение входной переменной равно Debug, то
		aux_source_directory("./sources" SOURCES)#задаем папки в которых хранятся исходники
		include_directories("C:/OpenCV")
		link_directories("C:/OpenCV/bin")
		add_library(${PROJECT} SHARED ${SOURCES}) #создаем динамическую библиотеку
		set_target_properties(${PROJECT} PROPERTIES COMPILE_FLAGS "-O2 -std=c++11 -pedantic -Wall -Wextra")#задаем ключи компилятора и макросы для цели ${PROJECT}
		target_link_libraries(${PROJECT} shlwapi opencv_core249 opencv_highgui249 opencv_imgproc249 opencv_objdetect249)
		add_custom_command(TARGET ${PROJECT} POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E make_directory ${BUILD_TYPE}
			COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT}> ${BUILD_TYPE}
			COMMAND ${CMAKE_COMMAND} -E remove $<TARGET_FILE:${PROJECT}>)
	endif ()

	if (${BUILD_TYPE} STREQUAL "debug")#если значение входной переменной равно Debug, то
		aux_source_directory("./sources" SOURCES)#задаем папки в которых хранятся исходники
		include_directories("C:/OpenCV")
		link_directories("C:/OpenCV/bin")
		add_library(${PROJECT}_debug SHARED ${SOURCES}) #создаем динамическую библиотеку
		set_target_properties(${PROJECT}_debug PROPERTIES COMPILE_FLAGS "-O0 -std=c++11 -g3 -pedantic -Wall -Wextra -D__IMAGE_RECOGNITION_DEBUG__")#задаем ключи компилятора и макросы для цели ${PROJECT}
		target_link_libraries(${PROJECT}_debug shlwapi opencv_core249 opencv_highgui249 opencv_imgproc249 opencv_objdetect249)
		add_custom_command(TARGET ${PROJECT}_debug POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E make_directory ${BUILD_TYPE}
			COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT}_debug> ${BUILD_TYPE}
			COMMAND ${CMAKE_COMMAND} -E remove $<TARGET_FILE:${PROJECT}_debug>)
	endif ()

	if (${BUILD_TYPE} STREQUAL "release_test")#если значение входной переменной равно Debug, то
		aux_source_directory("./sources" SOURCES_TEST)#задаем папки в которых хранятся исходники
		aux_source_directory("./tests" SOURCES_TEST)#задаем папки в которых хранятся исходники
		include_directories("C:/OpenCV" "C:/gtest")
		link_directories("C:/gtest" "C:/OpenCV/bin")
		add_executable(${PROJECT}_test ${SOURCES_TEST}) #создаем динамическую библиотеку
		set_target_properties(${PROJECT}_test PROPERTIES COMPILE_FLAGS "-O2 -std=c++11 -pedantic -Wall -Wextra -D__IMAGE_RECOGNITION_TEST__")#задаем ключи компилятора и макросы для цели ${PROJECT}
		target_link_libraries(${PROJECT}_test gtest gtest_main shlwapi opencv_core249 opencv_highgui249 opencv_imgproc249 opencv_objdetect249)
		add_custom_command(TARGET ${PROJECT}_test POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E make_directory ${BUILD_TYPE}
			COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT}_test> ${BUILD_TYPE}
			COMMAND ${CMAKE_COMMAND} -E remove $<TARGET_FILE:${PROJECT}_test>)
		run_test(${PROJECT}_test)
	endif ()

	if (${BUILD_TYPE} STREQUAL "debug_test")#если значение входной переменной равно Debug, то
		aux_source_directory("./sources" SOURCES_TEST)#задаем папки в которых хранятся исходники
		aux_source_directory("./tests" SOURCES_TEST)#задаем папки в которых хранятся исходники
		include_directories("C:/OpenCV" "C:/gtest")
		link_directories("C:/gtest" "C:/OpenCV/bin")
		add_executable(${PROJECT}_debug_test ${SOURCES_TEST}) #создаем динамическую библиотеку
		set_target_properties(${PROJECT}_debug_test PROPERTIES COMPILE_FLAGS "-O0 -g3 -std=c++11 -pedantic -Wall -Wextra -D__IMAGE_RECOGNITION_TEST__ -D__IMAGE_RECOGNITION_DEBUG__")#задаем ключи компилятора и макросы для цели ${PROJECT}
		target_link_libraries(${PROJECT}_debug_test gtest gtest_main shlwapi opencv_core249 opencv_highgui249 opencv_imgproc249 opencv_objdetect249)
		add_custom_command(TARGET ${PROJECT}_debug_test POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E make_directory ${BUILD_TYPE}
			COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT}_debug_test> ${BUILD_TYPE}
			COMMAND ${CMAKE_COMMAND} -E remove $<TARGET_FILE:${PROJECT}_debug_test>)
		run_test(${PROJECT}_debug_test)
	endif ()
endmacro()

add_custom_target(test)
macro(run_test TEST_TARGET)
	add_custom_target(${TEST_TARGET}_run_test
		COMMAND ${TEST_TARGET}
		DEPENDS ${TEST_TARGET}
		WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
	add_dependencies(test ${TEST_TARGET}_run_test)
endmacro()

#add_app_executable("debug")
#add_app_executable("release")
add_app_executable("debug_test")
#add_app_executable("release_test")
