#!/bin/bash

firstline=$(head -n 1 source/changelog.md)
read -a splitfirstline <<< $firstline
version=${splitfirstline[1]}
echo "Version: " $version
while true
do
  echo -e 'Do you want to continue? (enter "1" for yes, "0" for no) \U2754 \U2753 \U2754'
  read versioncontinue
  if [ $versioncontinue -eq 1 ]
  then
    for file in source/*
    do
      echo $file " is being copied"
      cp $file build/.
      if [ "$file" == "source/secretinfo.md" ]
      then
        sed -i 's/42/XX/' build/secretinfo.md
      fi
    done
    break
  elif [ $versioncontinue -eq 0 ]
  then
    echo "Please come back when you are ready"
    break
  fi
done

cd build/
echo "Files in the build directory (at version $version):"
ls

cd ..
