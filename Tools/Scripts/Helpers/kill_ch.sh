#!/bin/bash
#################################################
#	CNCN RTFI Channel Kill Script				#
#################################################
#	This script find pid and kill, also wait	#
#		some time to db flush its queries		#
#################################################
server_dir="../../../Server"
channels_dir="${server_dir}/Channels"
hline()
{
	printf '%*s\n' "${COLUMNS:-$(tput cols)}" '' | tr ' ' -
}
kill_pid()
{
	if [[ $1 == 1 ]] || [[ $1 == 2 ]] || [[ $1 == 3 ]] || [[ $1 == 4 ]]; then
		hline
		for q in 1 2 3 4
		do
			pid_dir=${channels_dir}/Ch_{1}/C_${q}
			pid=${pid_dir}/pid
			if [[ -e ${pid} ]]; then
				pid_value=`cat ${pid}`
				if ps -p ${pid_value} > /dev/null
				then
					echo -e "\e[1mChannel ${1} Core ${q}\e[0m\t\t\e[32mCLOSING...\e[0m"
					kill -9 ${pid_value} > /dev/null & wait ${pid_value} 2>/dev/null
				else
					echo -e "\e[1mChannel ${1} Core ${q}\e[0m\t\t\e[33mNOT RUNNNING...\e[0m"
				fi
			else
				echo -e "\e[1mChannel ${1} Core ${q}\e[0m\t\t\e[33mNOT RUNNNING...\e[0m"
			fi
		done
	elif [[ "$1" = "dev" ]] || [[ "$1" = "auth" ]] || [[ "$1" == 99 ]] || [[ "$1" = "db" ]]; then
		hline
		pid_dir=${channels_dir}/Ch_${1}
		pid=${pid_dir}/pid
		if [[ -e ${pid} ]];then
			pid_value=`cat ${pid}`
			if ps -p ${pid_value} > /dev/null
			then
				echo -e "\e[1mChannel ${1}\e[0m\t\t\e[32mCLOSING...\e[0m"
				kill -9 ${pid_value} > /dev/null & wait ${pid_value} 2>/dev/null
			else
				echo -e "\e[1mChannel ${1}\e[0m\t\t\e[33mNOT RUNNNING...\e[0m"
			fi
		else
			echo -e "\e[1mChannel ${1}\e[0m\t\t\e[33mNOT RUNNNING...\e[0m"
		fi
	else
		clear
		echo -e "\e[1m${1}\e[0m\t\t\e[31mERROR\e[0m"
		hline
	fi
}
kill_pid "${1}"