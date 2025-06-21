# Собираем статическую библиотеку для работы с игровыми данными
add_library(dataLib STATIC
    DataManager.cpp
    ResourceLoader.cpp
    DialogueDatabase.cpp
)

# Делаем заголовки публичными для подключения в других модулях
target_include_directories(dataLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/config
)

# Зависимости: dataLib использует json и configLib
target_link_libraries(dataLib PUBLIC
    configLib
    nlohmann_json::nlohmann_json
)
