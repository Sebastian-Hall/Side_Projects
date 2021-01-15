#!/bin/bash

# variables
amz_link="https://www.amazon.com/PlayStation-5-Console/dp/B08FC5L3RG/ref=sr_1_1"
bb_link="https://www.bestbuy.com/site/sony-playstation-5-console/6426149.p?skuId=6426149"
wal_link="https://www.walmart.com/ip/PlayStation-5-Console/363472942"

amz_file="amazon.html"
bb_file="bestbuy.html"
wal_file="walmart.html"

#amz_cnt=0
bb_cnt=0
wal_cnt=0

sleep_time=15

# Loop infinitely
while true; do

# Download files
printf "downloading pages...\n\n"
wget -q -T 30 -O $amz_file -U "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.79 Safari/537.36" $amz_link
wget -q -T 30 -O $bb_file $bb_link # For some reason it takes about 10 seconds to download from best buy?
wget -q -T 30 -O $wal_file -U "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.79 Safari/537.36" $wal_link


# Parse files for unique identifier of being out of stock
amz=$(grep "Currently unavailable" $amz_file)
bb=$(grep "btn-disabled" $bb_file)
wal=$(grep -o "<b>Out of stock</b>" $wal_file)

# Check status of amazon
if [[ -z $amz ]]
then
       	echo "Item at amazon"
	if [[ $amz_cnt -eq 0 ]]
	then
      		firefox $amz_link &
		((amz_cnt = amz_cnt + 1))
	fi
else
       echo "No Amazon"
fi

# Check status of best buy
if [[ -z $bb ]]
then
       	echo "Item at best buy"
	if [[ $bb_cnt -eq 0 ]]
	then
       		firefox $bb_link &
		((bb_cnt = bb_cnt + 1))
	fi
else
       echo "No Best Buy"
fi

# Check status of walmart
if [[ -z $wal ]]
then
       	echo "Item at walmart"
	if [[ $wal_cnt -eq 0 ]]
	then
       		firefox $wal_link &
		((wal_cnt = wal_cnt + 1))
	fi
else
       echo "No Walmart"
fi


# Sleep until next parse
printf "\nsleeping $sleep_time \n\n\n\n\n"
sleep $sleep_time

done
