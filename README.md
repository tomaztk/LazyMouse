
# LazyMouse <a href="https://github.com/tomaztk/LazyMouse"><img src="/figures/LazyMousePackage.png" align="right" height="138" /></a>

<span style="font-size: xx-large; font-weight: normal;">`LayzMouse`
is an R package with single function for randomly moving mouse cursor in your favorite R IDE. 
For every R developer, R data scientists and  all those everyday R users, that 
also need a break.</span>

<!-- badges: start -->
<div align="left">
      <p>
	    <a name="stars"><img src="https://img.shields.io/github/stars/tomaztk/LazyMouse?style=for-the-badge"></a>
	    <a name="forks"><img src="https://img.shields.io/github/forks/tomaztk/LazyMouse?logoColor=green&style=for-the-badge"></a>
      <a name="license"><img src="https://img.shields.io/github/license/tomaztk/LazyMouse?style=for-the-badge"></a>

   </p>
</div>
<!-- badges: end -->


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


## Contributing

Thanks to these wonderful community people testing, providing feedback and making the library better! For contributing please read the [contributing file](CONTRIBUTING.md).

## License

MIT license
