#!/bin/bash
#################################################
#	CNCN RTFI Controller Script	    			#
#################################################
imhere=${PWD}
clear
echo -e "\e[32m                      -//:'            \e[0m"
echo -e "\e[32m                     -hhhhhh+           \e[0m"
echo -e "\e[32m                     shhhhhhh'          \e[0m"
echo -e "\e[32m                  .:ohddhhhy:           \e[0m"
echo -e "\e[32m               .oyhddddddd.             \e[0m"
echo -e "\e[32m              'yhhdddmmmddo             \e[0m"
echo -e "\e[32m              shhhh-mmmmddhyo:'         \e[0m"
echo -e "\e[32m             .hhhh:ommmdhdhhhhh/        \e[0m"
echo -e "\e[32m              .::..dmmmo '-/sso.    VERSIYON = 1.0.0    \e[0m"
echo -e "\e[32m                  +dddd.                \e[0m"
echo -e "\e[32m                 :hdddh/'               \e[0m"
echo -e "\e[32m               'shhddddhho.             \e[0m"
echo -e "\e[32m              :hhhhy:+hhhhhs:           \e[0m"
echo -e "\e[32m            .ohhhh+'  ':shhhho          \e[0m"
echo -e "\e[32m         -+yhhhhy-      .hhhh/          \e[0m"
echo -e "\e[32m      -+hhhhhho:'       +hhhy'          \e[0m"
echo -e "\e[32m    .hhhhhho-           hhhho           \e[0m"
echo -e "\e[32m    :hhhh-             -hhhhs'          \e[0m"
echo -e "\e[32m     -+/.              -yhhhy.          \e[0m"
echo -e "\e[32m                         '..            \e[0m"
echo -e "\e[32m\e[0m"
read -t 20 -p  "Enter your commands : " command_1 command_2
clear
if [[ ${command_1} = "close" ]] || [[ ${command_1} = "kapat" ]];then
	cd ./Helpers && bash ./kill_ch.sh ${command_2} 2>/dev/null
elif [[ ${command_1} = "start" ]] || [[ ${command_1} = "baslat" ]];then
	cd ./Helpers && bash ./start_ch.sh ${command_2}
fi
