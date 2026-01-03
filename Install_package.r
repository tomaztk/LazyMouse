install.packages("remotes")
remotes::install_github("tomaztk/LazyMouse")


library(LazyMouse)

LazyMouse::lazy_mouse(
  number_of_repetitions = 5,      # number of loops
  time_between_repetitions = 10,  # time in seconds between each loop
  pixels = 150                    # random change of x-axis / y-axis mouse position
)
