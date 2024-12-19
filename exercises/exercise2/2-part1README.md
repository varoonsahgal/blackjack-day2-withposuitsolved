
# Pull refactored code from lab 1
Make sure that you pull the updated code from lab 1 so that everyone is on the same starting point.


# Setup to Add tests
Without adequate tests, the risks of breaking things while refactoring are increased.  We need to add some tests to our code.

We will use Google Test to write some test cases in C++, but first we need to install it.


# Installing Google Test on **macOS** and **Windows**:

---

## **Installing Google Test on macOS**

### 1. Install Google Test Using Homebrew
Homebrew makes it easy to install Google Test:
```bash
brew install googletest
```

### 2. Locate the Installation Path
After installation, Homebrew stores Google Test in the `Cellar` directory. To locate the installed files:
```bash
brew info googletest
```

You will see a path like:
```
/opt/homebrew/Cellar/googletest/1.x.x
```

### 3. Verify Installation
Ensure the headers and libraries are available:
```bash
ls /opt/homebrew/Cellar/googletest/1.x.x/include
ls /opt/homebrew/Cellar/googletest/1.x.x/lib
```

### 4. Update Your Build System
- Add `/opt/homebrew/Cellar/googletest/1.x.x/include` to your compiler's **include path**.
- Add `/opt/homebrew/Cellar/googletest/1.x.x/lib` to your linker flags.

For example, in a Makefile:
```makefile
CXXFLAGS = -std=c++17 -I/opt/homebrew/Cellar/googletest/1.x.x/include
LDFLAGS = -L/opt/homebrew/Cellar/googletest/1.x.x/lib -lgtest -lgtest_main -pthread
```


A sample Makefile that works for me is here - note that you will likely have to make modifications to the GTEST_LIBS variable to point to
your installation of googletest:
```makefile
# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++17 -I/opt/homebrew/Cellar/googletest/1.15.2/include -I./src

# Directories
SRC_DIR = src
TEST_DIR = src/tests
BUILD_DIR = build

# Google Test Libraries (installed via Homebrew)
GTEST_LIBS = -L/opt/homebrew/Cellar/googletest/1.15.2/lib -lgtest -lgtest_main -pthread


# Source Files
APP_SRC_FILES = $(SRC_DIR)/blackjack.cpp $(SRC_DIR)/card.cpp $(SRC_DIR)/compatible.cpp \
                $(SRC_DIR)/dealer.cpp $(SRC_DIR)/deck.cpp $(SRC_DIR)/game.cpp \
                $(SRC_DIR)/human.cpp $(SRC_DIR)/player.cpp $(SRC_DIR)/print.cpp $(SRC_DIR)/statistics.cpp
TEST_SRC_FILES = $(SRC_DIR)/card.cpp $(TEST_DIR)/card_test.cpp

# Output Binaries
APP_BIN = $(BUILD_DIR)/blackjack
TEST_BIN = $(BUILD_DIR)/card_test

# Rules
all: app test

# Build the main application
app: $(APP_BIN)

$(APP_BIN): $(APP_SRC_FILES)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build and run tests
test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC_FILES)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_LIBS)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)
```

---

## **Installing Google Test on Windows**

### 1. Install Google Test Using vcpkg
Use **vcpkg**, a popular package manager for C++ libraries:
1. Install vcpkg by following the instructions at [vcpkg GitHub](https://github.com/microsoft/vcpkg).
2. Install Google Test:
   ```bash
   vcpkg install gtest
   ```
3. Integrate vcpkg with your project:
   ```bash
   vcpkg integrate install
   ```

### 2. Locate the Installation Path
After installation, the libraries and headers will be located in the `vcpkg/installed/` directory:
- Headers: `vcpkg/installed/x64-windows/include`
- Libraries: `vcpkg/installed/x64-windows/lib`

### 3. Update Your Build System
Configure your build system (e.g., Visual Studio, Makefile, or CMake) to include these paths:
- Add `vcpkg/installed/x64-windows/include` to the **include paths**.
- Add `vcpkg/installed/x64-windows/lib` to the **library paths**.

---

## **Sample Test Case**

Here is an example test file `tests/card_test.cpp` for your Blackjack project:

```cpp
#include "headers/card.h"
#include <gtest/gtest.h>

TEST(CardTest, DefaultConstructor) {
    Card c;
    EXPECT_EQ(c.getNumber(), 0);
    EXPECT_EQ(c.getSuit(), '\0');
    EXPECT_FALSE(c.getBlock());
}

TEST(CardTest, ParameterizedConstructor) {
    Card c(10, 'H'); // 10 of Hearts
    EXPECT_EQ(c.getNumber(), 10);
    EXPECT_EQ(c.getSuit(), 'H');
    EXPECT_FALSE(c.getBlock());
}

TEST(CardTest, GetSetMethods) {
    Card c;
    c.setNumber(5);
    c.setSuit('D');
    c.setBlock(true);

    EXPECT_EQ(c.getNumber(), 5);
    EXPECT_EQ(c.getSuit(), 'D');
    EXPECT_TRUE(c.getBlock());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

---

## **Compiling and Running the Test**

### Using a Makefile (macOS/Linux)
1. Add the test files to your Makefile:
```makefile
CXX = g++
CXXFLAGS = -std=c++17 -I/opt/homebrew/Cellar/googletest/1.x.x/include
LDFLAGS = -L/opt/homebrew/Cellar/googletest/1.x.x/lib -lgtest -lgtest_main -pthread

test: tests/card_test.cpp src/card.cpp
	$(CXX) $(CXXFLAGS) $^ -o test $(LDFLAGS)
	./test
```
2. Run the tests:
```bash
make test
```

### Using Visual Studio (Windows)
1. Add `tests/card_test.cpp` to your project.
2. Go to **Project Properties** and:
   - Add `vcpkg/installed/x64-windows/include` to **Include Directories**.
   - Add `vcpkg/installed/x64-windows/lib` to **Library Directories**.
   - Link `gtest.lib` and `gtest_main.lib`.
3. Build and run your tests.

---
Note, you may need to update the include paths, hence the instructions here...


Here’s how you can set up **Google Test** in both **VS Code** and **Visual Studio Professional**, including how to add the include paths:

---

## **Adding Include Paths in VS Code**

### Step 1: Open `c_cpp_properties.json`
1. Open VS Code.
2. Open the Command Palette (`Ctrl + Shift + P` or `Cmd + Shift + P` on macOS).
3. Search for **C/C++: Edit Configurations (JSON)** and select it.

### Step 2: Add Include Paths
1. In the `c_cpp_properties.json` file, locate the `"includePath"` array.
2. Add the path to the Google Test headers. For example:
   ```json
   {
       "configurations": [
           {
               "name": "Mac",
               "includePath": [
                   "${workspaceFolder}/**",
                   "/opt/homebrew/Cellar/googletest/1.x.x/include"
               ],
               "defines": [],
               "compilerPath": "/usr/bin/clang++",
               "cStandard": "c17",
               "cppStandard": "c++17",
               "intelliSenseMode": "macos-clang-x64"
           },
           {
               "name": "Win32",
               "includePath": [
                   "${workspaceFolder}/**",
                   "C:/path/to/vcpkg/installed/x64-windows/include"
               ],
               "defines": [],
               "compilerPath": "C:/path/to/your/compiler.exe",
               "cStandard": "c17",
               "cppStandard": "c++17",
               "intelliSenseMode": "windows-msvc-x64"
           }
       ],
       "version": 4
   }
   ```

### Step 3: Save and Reload
1. Save the file.
2. Reload the VS Code window (`Ctrl + Shift + P` → **Reload Window**).

---

## **Adding Include Paths in Visual Studio Professional**

In Visual Studio Pro, you Google Test should come preconfigured/integrated with the IDE: https://learn.microsoft.com/en-us/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2022

In case it does not - read below!:

### Step 1: Open Project Properties
1. Open your project in Visual Studio Professional.
2. Right-click on the project in the **Solution Explorer** and select **Properties**.

### Step 2: Configure Include Directories
1. Navigate to:
   - **Configuration Properties** → **C/C++** → **General** → **Additional Include Directories**.
2. Add the path to the Google Test headers:
   - For Homebrew (macOS): `/opt/homebrew/Cellar/googletest/1.x.x/include`
   - For vcpkg (Windows): `C:/path/to/vcpkg/installed/x64-windows/include`
3. Click **OK** to save changes.

### Step 3: Configure Library Directories
1. Navigate to:
   - **Configuration Properties** → **Linker** → **General** → **Additional Library Directories**.
2. Add the path to the Google Test libraries:
   - For Homebrew (macOS): `/opt/homebrew/Cellar/googletest/1.x.x/lib`
   - For vcpkg (Windows): `C:/path/to/vcpkg/installed/x64-windows/lib`

### Step 4: Link Google Test Libraries
1. Navigate to:
   - **Configuration Properties** → **Linker** → **Input** → **Additional Dependencies**.
2. Add the following libraries:
   - For Homebrew (macOS): `libgtest.a` and `libgtest_main.a`
   - For vcpkg (Windows): `gtest.lib` and `gtest_main.lib`

### Step 5: Save and Build
1. Click **OK** to save your configuration.
2. Build your project by selecting **Build Solution** from the **Build** menu (`Ctrl + Shift + B`).

---

## **Test the Setup**

### Create a Test File
Create a test file, such as `tests/card_test.cpp`, and add this content:
```cpp
#include "card.h"
#include <gtest/gtest.h>

TEST(CardTest, DefaultConstructor) {
    Card c;
    EXPECT_EQ(c.getNumber(), 0);
    EXPECT_EQ(c.getSuit(), '\0');
    EXPECT_FALSE(c.getBlock());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### Build and Run
- **VS Code**: Use your `Makefile` to build and run tests:
  ```bash
  make test
  ```
- **Visual Studio Professional**:
  1. Set the test project as the startup project.
  2. Press `F5` to build and run.

---

