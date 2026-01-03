#' Randomly move the mouse cursor
#'
#' @param number_of_repetitions Number of movements
#' @param time_between_repetitions Seconds between movements
#' @param pixels Maximum pixel movement per step
#'
#' @export
lazy_mouse <- function(
    number_of_repetitions = 10,
    time_between_repetitions = 10,
    pixels = 50
) {

  stopifnot(
    number_of_repetitions > 0,
    time_between_repetitions > 0,
    pixels > 0
  )

  for (i in seq_len(number_of_repetitions)) {
    move_mouse_random(pixels)
    Sys.sleep(time_between_repetitions)
  }

}
