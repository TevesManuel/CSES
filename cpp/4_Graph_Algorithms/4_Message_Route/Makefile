default:
	g++ ./src/app.cpp -o ./out/app -Wall -Werror -pedantic
	./out/app < ./tests/1.in && echo "Expected 3" && echo "1 4 5"
	./out/app < ./tests/2.in && echo "Expected IMPOSSIBLE"
	./out/app < ./tests/3.in && echo "Expected" && echo "5" && echo "1 4 5 8 10"