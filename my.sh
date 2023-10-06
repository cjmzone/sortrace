echo My Generate Script
sleep 1
echo generating 10 numbers
./generate 10 1 100
echo Generated Numbers!
more numbers.dat
sleep 1
echo Sorting
./mysort numbers.dat sorted.out
echo Sorted:
more sorted.out
echo completed!
