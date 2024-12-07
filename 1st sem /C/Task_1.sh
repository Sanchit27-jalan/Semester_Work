#1/bin/bash
function gcd(){
    if [ $2 -eq 0];
    then 
        return $1
    else
        a=$(($1%$2))
        return gcd $2 $a
}
read a
read b
c=gcd $a $b
echo GCD: $c 