find . -type f -name "*.sh" -print | sed 's#.*/##' | sed 's/\.[^.]*$//'
