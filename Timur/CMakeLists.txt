cmake_minimum_required(VERSION 3.10)

project(blackjack VERSION 0.0.1)

set(TARGET_GAME cards)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${TARGET_GAME} ${SOURCE_DIR}/Card.cpp ${SOURCE_DIR}/Hand.cpp ${SOURCE_DIR}/House.cpp ${SOURCE_DIR}/Player.cpp ${SOURCE_DIR}/Deck.cpp ${SOURCE_DIR}/GenericPlayer.cpp ${SOURCE_DIR}/Game.cpp ${SOURCE_DIR}/Modules.cpp)

target_include_directories(${TARGET_GAME} PRIVATE ${HEADER_DIR})

set_target_properties(
	${TARGET_GAME} PROPERTIES
	CXX_STANDARD 17	#Собирать в соответствии со стандартом c17
	C_STANDARD	11
	)
