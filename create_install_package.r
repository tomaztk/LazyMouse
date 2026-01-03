#setwd("/Users/tomazkastrun/Documents/tomaztk_github/LazyMouse")

install.packages(c("usethis", "Rcpp", "devtools"))

usethis::create_package("LazyMouse")
usethis::use_rcpp()
usethis::use_git()



