YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

for txt in $(ls ./map | grep "err");
do
    echo "${YELLOW}++++++++++++++++++++${txt}++++++++++++++++++++${NC}"
	./so_long map/${txt}
	echo exit code is $?
    echo "${BLUE}============VALGRIND REPORT============${NC}"
    valgrind --leak-check=full --show-leak-kinds=all ./so_long map/${txt} > /dev/null 2> leaks.txt
	if grep "LEAK SUMMARY:" leaks.txt >/dev/null; then
    	cat leaks.txt | sed -n -e '/.*LEAK SUMMARY:.*/,$p'
	else
    	cat leaks.txt | sed -n -e '/.*HEAP SUMMARY:.*/,$p'
    rm leaks.txt
	fi
	sleep 0.5;
done