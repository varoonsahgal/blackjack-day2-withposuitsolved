# ♠️ Blackjack (C++)
Demo:

<img alt="Blackjack Demo" style="display: block; margin-left: auto; margin-right: auto; width: fit-content;" src="data/demo.gif" />


## 🔧 Setup


### Building / Compiling

```sh
$ cd ..             # if you are in the build directory
$ make              # builds executable based on Makefile, which uses the g++ compiler
$ ./blackjack       # this will run the blackjack program
```

#### g++ compiler - to run it directly:
```sh
$ cd ..             # if you are in the build directory
$ g++ src/blackjack.cpp src/card.cpp src/compatible.cpp src/dealer.cpp src/deck.cpp src/game.cpp src/human.cpp src/player.cpp src/print.cpp src/statistics.cpp -std=c++17 -o blackjack
statistics.cpp -o blackjack
$ ./blackjack       # voila!
```

