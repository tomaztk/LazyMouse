# LazyMouse

<span style="font-size: xx-large; font-weight: normal;">`LayzMouse`
is an R package with single function for moving mouse cursor in your favorite R IDE. 
For every R developer, R data scientists and  all those everyday R users, that 
also need a break.</span>


<img src="figures/UURlogo.jpg" align="right" width="300" />

<!-- badges: start -->
![](https://img.shields.io/badge/tomaztk%2FLazyMouse-repo-blue%3Flogo%3Dgithub?logo=github)

![](https://img.shields.io/github/forks/tomaztk/lazymouse?style=social)
<!-- badges: end -->


## Contributors and co-authors

Thanks to these wonderful community people making and helping this useless R functions better. Contributions of any kind is highly appreciated!




## Install the package from the Github:

```
install.packages("remotes")
remotes::install_github("tomaztk/LazyMouse/LazyMouse"")
```

## Using function lazy_mouse():

```
library(LazyMouse)

LazyMouse::lazy_mouse(
  number_of_repetitions = 5,      # number of loops
  time_between_repetitions = 10,  # time in seconds between each loop
  pixels = 150                    # general change of x-axis and/or y-axis mouse position
)
```

## Cloning  /  fork the repository
You can follow the steps below to clone the repository.
```
git clone https://github.com/tomaztk/LazyMouse.git
```
