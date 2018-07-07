FROM ubuntu
MAINTAINER Marcel Vilalta <marcel.vilalta@gmail.com>

RUN apt-get update && apt-get install -y git g++ make wget python-dev curl cmake unzip build-essential

RUN cd /home && wget -O boost_1_61_0.tar.gz http://sourceforge.net/projects/boost/files/boost/1.61.0/boost_1_61_0.tar.gz/download && \
    tar -xf boost_1_61_0.tar.gz && \
    cd boost_1_61_0 && \
    mkdir boost-build && \
    ./bootstrap.sh --prefix=./boost-build --with-libraries=regex -with-libraries=system && \    
    # ./bootstrap.sh --prefix=/usr/local && \    
    ./b2 install && \
    cd /home


RUN apt-get install -y qt5-default qttools5-dev-tools

RUN apt remove -y cmake && \
  apt purge --auto-remove -y cmake && \
  wget https://cmake.org/files/v3.10/cmake-3.10.3.tar.gz && \
  tar -xzvf cmake-3.10.3.tar.gz && \
  cd cmake-3.10.3/ && \
  ./bootstrap && \
  make -j4 && \
  make install && \
  cd ../..

RUN curl -sL https://github.com/opencv/opencv/archive/3.4.1.zip > opencv.zip && \
  unzip opencv.zip && \
  cd opencv-3.4.1 && \
  mkdir release && \
  cd release && \
  cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local .. && \
  make -j4  && \
  make install && \
  sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf' && \
  ldconfig && \
  cd ../..
  
