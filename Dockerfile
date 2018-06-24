FROM ubuntu
MAINTAINER Marcel Vilalta <marcel.vilalta@gmail.com>

RUN apt-get update && apt-get install -y git g++ make wget python-dev

RUN cd /home && wget -O boost_1_61_0.tar.gz http://sourceforge.net/projects/boost/files/boost/1.61.0/boost_1_61_0.tar.gz/download && \
    tar -xf boost_1_61_0.tar.gz && \
    cd boost_1_61_0 && \
    mkdir boost-build && \
    ./bootstrap.sh --prefix=/usr/local --with-libraries=program_options && \
    ./b2 install && \
    cd /home && rm -rf boost_1_61_0

