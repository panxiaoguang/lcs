#' @importFrom Rcpp evalCpp
#' @useDynLib lcs
NULL

#' Get the longest common substring
#'
#' @param s1 a character, the one of characters
#' @param s2 a character, the other character
#'
#' @return a character contain the longest common substring between s1 and s2
#' @export CalLCS
#' @examples
#' library(lcs)
#' CalLCS("AGCAT","ACGGCAT")
CalLCS <- function(s1,s2){
  if (missing(s1) || missing(s2) || s1 == "" || s2 == "") {
    stop("Both strings must be provided and non-empty.")
  }else{
    longest_common_substring(s1, s2)
  }
}
