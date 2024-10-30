#!/bin/bash

# Loop through all files in the current directory that match the pattern 'test<integer>.in'
for file in test*.out; {
  # Extract the integer from the file name using parameter expansion
  new_name="${file#test}"

  # Rename the file
  mv "$file" "${new_name}"

  echo ${new_name}
}

