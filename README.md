# LazyMouse

Lazy Mouse mover for R developers


Install the package from the Github:

```
install.packages("remotes")
remotes::install_github("tomaztk/LazyMouse/LazyMouse"")
```

Run command:

```
library(LazyMouse)

LazyMouse::lazy_mouse(
  number_of_repetitions = 5,      # number of loops
  time_between_repetitions = 10,  # time in seconds between each loop
  pixels = 150                    # general change of x-axis mouse position
)
```
