rm ./tests/test_output/output* ./tests/test_output/real*

echo "remove done"

valgrind cat ./tests/mike_5star.txt | ./bin/movie_db >> ./tests/test_output/output_mike_5star.txt
valgrind cat ./tests/simple.txt | ./bin/movie_db >> ./tests/test_output/output_simple.txt
valgrind cat ./tests/test_2.txt | ./bin/movie_db >> ./tests/test_output/output_test_2.txt
valgrind cat ./tests/test_quotes.txt | ./bin/movie_db >> ./tests/test_output/output_test_quotes.txt

cat ./tests/mike_5star.txt | ./movie_db_sample >> ./tests/test_output/real_mike_5star.txt
cat ./tests/simple.txt | ./movie_db_sample >> ./tests/test_output/real_simple.txt
cat ./tests/test_2.txt | ./movie_db_sample >> ./tests/test_output/real_test_2.txt
cat ./tests/test_quotes.txt | ./movie_db_sample >> ./tests/test_output/real_test_quotes.txt

echo "done, now comparing"

echo "comparing mike_5star"
diff ./tests/test_output/output_mike_5star.txt ./tests/test_output/real_mike_5star.txt

echo "comparing simple"
diff ./tests/test_output/output_simple.txt ./tests/test_output/real_simple.txt
echo "comparing test2"
diff ./tests/test_output/output_test_2.txt ./tests/test_output/real_test_2.txt
echo "comparing test_quotes"
diff ./tests/test_output/output_test_quotes.txt ./tests/test_output/real_test_quotes.txt

echo "done"