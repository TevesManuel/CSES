default:
	g++ ./src/app.cpp -o ./out/app -Wall -Werror -pedantic
	./out/app < ./tests/1.in && echo "Expected 3"
	./out/app < ./tests/3.in && echo "Expected -1"
	./out/app < ./tests/4.in && echo "Expected 11"
	./out/app < ./tests/2.in && echo "Expected 4"