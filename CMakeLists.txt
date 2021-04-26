cmake_minimum_required(VERSION 3.10)

project(blackjack VERSION 0.0.1)

set(TARGET_BLACKJACK blackjack)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

#add_executable(${TARGET_BLACKJACK} ${SOURCE_DIR}/player.cpp ${SOURCE_DIR}/cards.cpp ${SOURCE_DIR}/hand.cpp ${SOURCE_DIR}/blackjack.cpp)
add_executable(${TARGET_BLACKJACK} ${SOURCE_DIR}/cards.cpp ${SOURCE_DIR}/hand.cpp ${SOURCE_DIR}/blackjack.cpp)

target_include_directories(${TARGET_BLACKJACK} PRIVATE ${HEADER_DIR})

set_target_properties(
	${TARGET_BLACKJACK} PROPERTIES
	CXX_STANDARD 17	#Собирать в соответствии со стандартом c17
	C_STANDARD	11
	)

