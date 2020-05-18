FROM ubuntu
RUN apt update && echo 'Y' | apt install cmake git make build-essential linux-source linux-headers-5.4.0-26-generic
