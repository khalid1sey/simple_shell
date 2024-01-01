#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "Maximum pid(pid_max): $pid_max"