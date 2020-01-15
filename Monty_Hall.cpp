#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <Windows.h>


int main (){

    /*Introduction*/
    std::cout<< "Welcome to Let's Make a Deal!" <<std::endl;
    std::cout<< "Would you like to Play or Simulate? Type in one of the options and press Enter." <<std::endl;

    /*Initialize Random Seed*/
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,2);

    /*Asking if user wants to play or simulate*/
    std::string answer{};
    std::cin >> answer;

    if(answer == "Play" || answer == "play"){
        /*Play*/
        float score = 0;
        float attempts = 0;
        float win_percent = 0;
        int status = 1;

        while(status == 1){
            std::cout << "Let's play" <<std::endl;
            
            {
                /*Generate Doors*/
                int Door1{};
                int Door2{};
                int Door3{};
                std::vector<int> door_vec {Door1, Door2, Door3};

                /*Randomly put 1 behind one of the doors*/
                unsigned int index = distribution(generator);
                door_vec.at(index) = 1;

                Sleep(2000);
                std::cout<< "There are three doors, behind one of them is $1,000,000 and behind the other two is a goat." << std::endl;
                Sleep(3000);
                std::cout<< "Now, guess which door has the $1,000,000 behind it by typing 1, 2, or 3 and then press Enter."<<std::endl;

                /*User guesses door*/
                unsigned int guess {};
                int input {};
                unsigned int not_behind {};
                while (input == 0){
                    std::cin >> input;
                    if(input > 3 || input < 1){
                        std::cout << "Sorry, that is not a valid guess. Please try again."<<std::endl;
                        input = 0;
                    }else{
                        guess = input - 1;//Store the index of the door not the door number
                    }//else-if
                }//while

                Sleep(2000);
                std::cout << "Ok, so you have selected door number " << guess + 1 <<std::endl;

                /*Find a door with nothing behind it that is also not the guess*/
                for(unsigned int i = 0; i < door_vec.size(); i++){
                    if(door_vec.at(i) == 0 && (i) != guess){
                        not_behind = (i+1);
                        i = door_vec.size();
                    }//if
                }//for

                Sleep(2000);
                std::cout << "Good thing you didn't select door " << not_behind << " because you would have been wrong"<<std::endl;
                Sleep(2000);
                std::cout << "Would you like to change your guess, Y/N?"<<std::endl;

                /*Switch or Keep*/
                std::string answer2 {};
                std::cin >> answer2;
                if(answer2 == "Y" || answer2 == "y"){
                    for(unsigned int i = 0; i < door_vec.size(); i++){
                        if(i != guess && i != (not_behind - 1)){
                            guess = i;
                            i = 4;
                        }//if
                    }
                }
                std::cout << "Ok, so your final guess is door number " << guess + 1 <<std::endl;
                Sleep(2000);
                std::cout << "Let's see what is behind door number " << guess + 1 <<std::endl;
                Sleep(2000);
                std::cout << "Opening door..."<<std::endl;
                Sleep(4000);
                if(door_vec.at(guess) == 1){
                    std::cout << "Congratulations! You have won $1,000,000! Thank you for playing Let's Make a Deal!" << std::endl;
                    score ++;
                    attempts ++;
                    win_percent = score*100/attempts;
                    std::cout << "Your win percentage is " << score << "/" << attempts << " or " << win_percent << "% Would you like to play again, Y/N?" << std::endl;

                    std::string answer3 {};
                    std::cin >> answer3;
                    if (answer3 == "N" || answer3 == "n"){
                        status = 0;
                        std::cout << "Ok, thank you for playing!" << std::endl;
                    }//Break the play while loop

                }else{
                    std::cout << "Sorry, unfortunatley you have lost. Thank you for playing Let's Make a Deal." << std::endl;
                    attempts ++;
                    win_percent = score*100/attempts;
                    std::cout << "Your win percentage is " << score << "/" << attempts << " or " << win_percent << "% Would you like to play again, Y/N?" << std::endl;

                    std::string answer3 {};
                    std::cin >> answer3;
                    if (answer3 == "N" || answer3 == "n"){
                        status = 0;
                        std::cout << "Ok, thank you for playing!" << std::endl;
                    }//Break the play while loop

                }
            }//Artificial scope

        }//PLay while loop    





    /*Simulate*/
    }else if(answer == "Simulate" || answer == "simulate"){
        std::cout << "Fantastic, let's simulate!"<<std::endl;
        std::cout << "How many times would you like to simulate? Please type in a number between 1 and 1,000,000" << std::endl;

        unsigned int sim_number {};
        std::cin >> sim_number;

        std::cout << "And would you like to have the guess changed, Y/N?" << std::endl;
        std::string answer4 {};
        std::cin >> answer4;

        /*Initializations*/
        float attempts2 {};
        float wins2 {};
        float win_percent2 {};



        /*Simulation Loop*/
        for(unsigned int i = 0; i < sim_number; i++){

            /*Generate Doors*/
                int Door1{};
                int Door2{};
                int Door3{};
                std::vector<int> door_vec {Door1, Door2, Door3};

                /*Randomly put 1 behind one of the doors*/
                unsigned int index = distribution(generator);
                door_vec.at(index) = 1;

                /*Randomly Guess*/
                unsigned int guess = distribution(generator);

                /*Switch door if required*/

                /*Find a door with nothing behind it that is also not the guess*/
                

                if(answer4 == "Y" || answer4 == "y"){
                    unsigned int not_behind2 {};
                    for(unsigned int j = 0; j < door_vec.size(); j++){
                        if(door_vec.at(j) == 0 && (j) != guess){
                            not_behind2 = (j+1);
                            j = door_vec.size();
                        }//if
                    }//for

                    for(unsigned int k = 0; k < door_vec.size(); k++){
                        if(k != guess && k != (not_behind2 - 1)){
                            guess = k;
                            k = 4;
                        }//if
                    }
                }//Outer if

                if(door_vec.at(guess) == 1){
                    wins2 ++;
                    attempts2 ++;
                }else{
                    attempts2 ++;
                }

        }

        win_percent2 = wins2*100/attempts2;
        std::cout << "Ok, so for " << sim_number << " simulation(s) and switching = " << answer4 << " the game was won " << wins2 << " times for a win percentage of " << win_percent2 << "%" <<std::endl;

        

    }else{
        std::cout << "Sorry please type Play or Simulate"<<std::endl;
    }

    return 0;
}