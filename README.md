# push-swap
My Push-Swap Project for 42 Berlin

Commands for testing with embedded random int generator:

# Test with 5 numbers (1-5):
ARGS=$(seq 1 5 | shuf | tr '\n' ' '); ./push_swap $ARGS | ./checker_linux $ARGS

# Test with 100 random numbers (1-100):
ARGS=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARGS | ./checker_linux $ARGS

# Test with 500 random numbers (0-1000):
ARGS=$(shuf -i 0-1000 -n 500 | tr '\n' ' '); ./push_swap $ARGS | ./checker_linux $ARGS

# Test with 100 random numbers (negative to positive):
ARGS=$(seq -50 50 | shuf | tr '\n' ' '); ./push_swap $ARGS | ./checker_linux $ARGS
