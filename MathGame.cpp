# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>

int generateRandomNumber() {

    int min_number = 1;
    int max_number = 100;
    int random_number = rand() % (max_number + 1 - min_number) + min_number;
    return random_number;

}

void gameSession(int durationSession) {

    while(durationSession < 5){

         int num_1 = generateRandomNumber();
         int num_2 = generateRandomNumber();
         int exampleResult = num_1 + num_2;
         int userResult;

         std::cout << "\n"  << std::to_string(num_1) << " + " << std::to_string(num_2) << " = ";
         std::cin >> userResult;

         if(userResult == exampleResult){
            std::cout << "\nВерно\n";
         } else {
            std::cout << "\nНеверно\n";
         }

         ++durationSession;
    };

}

int profiler(void (*function)(int)) {

    int argProfileFunction = 0;

    int startTime = std::time(nullptr);
    function(argProfileFunction);
    int finishTime = std::time(nullptr);

    return finishTime - startTime;

}

int main() {

    std::string separator = "_____________________________________\n";

    std::cout << separator << "\nMATHGAME v 1.0.0\nРешите 5 примеров как можно быстрее\n" << separator << "\n";

    int result = profiler(gameSession);

    std::cout << "\n" << separator << "\n" << "Решение примеров заняло " << result << " секунд" << "\n\n";

}
