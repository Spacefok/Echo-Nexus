# Echo Nexus

Echo Nexus — это консольная текстовая RPG в жанре dungeon crawler, в которой игрок управляет подопытным, сбежавшим из криокапсулы в секретной лаборатории. Исследуя её тёмные коридоры, он сражается с мутировавшими экспериментальными подопытными и ищет выход. Основная цель игрока — уничтожить или поглотить Куб теней, ядро лаборатории, определяя судьбу себя и остальных подопытных. Реализована на C++17 с использованием CMake.

📄 Документация

* \[Дизайн-документ (GDD)]\(public/Echo Nexus - GDD.pdf)
* \[Архитектурное представление]\(public/Echo Nexus - Arch.pdf)

🚀 Быстрый старт

```bash
git clone https://github.com/Spacefok/EchoNexus.git
cd EchoNexus
mkdir build && cd build
# Через CMake CLI
cmpcmake ..
cmake --build . --config Debug
ctest -C Debug --output-on-failure
```

**Через CMake GUI (Windows):**

1. Where is the source code: папка с CMakeLists.txt.
2. Where to build the binaries: .../EchoNexus/build.
3. Нажать Configure, выбрать генератор (Visual Studio 2022) и toolset.
4. Нажать Generate, затем Open Project для сборки в VS.

🗂 Структура проекта

```text
EchoNexus/
├── CMakeLists.txt       # Конфигурация сборки
├── config/              # Загрузка конфигурации игры
├── entities/            # Классы Entity, Player, Drone и др.
├── core/                # GameWorld, GameLoop, EventSystem
├── ai/                  # Модуль AI: EnemyAIController, DecisionEngine
├── render/              # ASCII-рендерер и HUD
├── ui/                  # UIManager и экраны (CombatLog)
├── procedural/          # Генераторы уровней и событий
├── data/                # DataManager, файлы JSON с данными
├── narrative/           # NarrativeManager, фрагменты памяти, квесты
├── save/                # SaveManager для сохранения прогресса
├── tests/               # Unit-тесты (ServiceLocatorTest)
├── assets/              # Ресурсы (заглушки)
├── docs/                # Документация и спецификации
├── build/               # Папка для сборки (игнорируется Git)
└── .gitignore           # Правила игнорирования
```

⚙️ Зависимости

* CMake >= 3.16
* Компилятор C++17 kompatible:

  * MSVC (Visual Studio 2022)
  * GCC 7+
  * Clang 5+
* Библиотека JSON: nlohmann/json (FetchContent)

📝 Roadmap

* Наполнение контентом: JSON-файлы уровней и фрагментов.
* Расширение UI/ввода: взаимодействие и меню.
* Дополнительные тесты: DataManager, ConfigLoader и др.
* CI/CD: автоматическая сборка и тестирование.

© 2025 Echo Nexus — проект на горе-разработчиках, ночами кодящих в темноте в поисках смысла жизни (spoiler: его нет).

