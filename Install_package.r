install.packages("remotes")
detach("package:LazyMouse", unload=TRUE)
remotes::install_github("tomaztk/LazyMouse")

# Check version
PackageVersion(LazyMouse)

library(LazyMouse)

LazyMouse::lazy_mouse(
  number_of_repetitions = 5,      # number of loops
  time_between_repetitions = 10,  # time in seconds between each loop
  pixels = 150                    # random change of x-axis / y-axis mouse position
)
