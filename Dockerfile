FROM ubuntu:20.04
MAINTAINER Marcel Vilalta <marcel.vilalta@gmail.com>

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y install tzdata

RUN apt-get update \
  && apt-get install -y build-essential \
      gcc \
      g++ \
      gdb \
      clang \
      make \
      ninja-build \
      cmake \
      autoconf \
      automake \
      locales-all \
      dos2unix \
      rsync \
      tar \
      git  \
      wget \
      python2-dev  \
      curl \
      unzip \
      mesa-utils \
      libegl1-mesa  \
      libegl1-mesa-dev  \
      libgbm-dev \
      libgbm1  \
      libgl1-mesa-dev \
      libgl1-mesa-dri  \
      libgl1-mesa-glx  \
      libglu1-mesa  \
      libglu1-mesa-dev \
      glew-utils \
      libglew-dev  \
      libglew2.1 \
    && apt-get clean

RUN cd /home && wget -O boost_1_61_0.tar.gz http://sourceforge.net/projects/boost/files/boost/1.61.0/boost_1_61_0.tar.gz/download && \
    tar -xf boost_1_61_0.tar.gz && \
    cd boost_1_61_0 && \
    mkdir boost-build && \
    ./bootstrap.sh --prefix=./boost-build --with-libraries=regex -with-libraries=system && \    
    # ./bootstrap.sh --prefix=/usr/local && \    
    ./b2 install && \
    cd /home


# RUN apt-get install -y qt5-default qttools5-dev-tools

RUN apt-get install -y qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools

RUN apt remove -y cmake && \
  apt purge --auto-remove -y cmake && \
  wget https://cmake.org/files/v3.10/cmake-3.10.3.tar.gz && \
  tar -xzvf cmake-3.10.3.tar.gz && \
  cd cmake-3.10.3/ && \
  ./bootstrap && \
  make -j4 && \
  make install && \
  cd ../..

RUN curl -sL https://github.com/opencv/opencv/archive/refs/tags/3.4.14.zip > opencv.zip && \
unzip opencv.zip && \
  cd opencv-3.4.14 && \
  mkdir release && \
  cd release && \
  cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local .. && \
  make -j4  && \
  make install && \
  sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf' && \
  ldconfig && \
  cd ../..

RUN apt-get install -y '^libxcb.*-dev' \
    libx11-xcb-dev \
    libglu1-mesa-dev libxrender-dev  \
    libxi-dev  \
    libxkbcommon-dev  \
    libxkbcommon-x11-dev \
    libxkbcommon-x11-0 \
    libxcb-xinerama0

ENV QT_DEBUG_PLUGINS 1

ENV QT_DEBUG_PLUGINS=1
ENV QT_QPA_PLATFORM=xcb
ENV QT_QPA_PLATFORM_PLUGIN_PATH=/usr/lib/aarch64-linux-gnu/qt5/plugins/platforms
ENV QT_PLUGIN_PATH=/usr/lib/aarch64-linux-gnu/qt5/plugins
#ENV DISPLAY=:0
ENV QT_X11_NO_MITSHM=1
ENV QT_GRAPHICSSYSTEM="native"

# https://github.com/openalea/docker-stacks/issues/6
# https://mfix.netl.doe.gov/forum/t/mfix-21-4-rhel-7-5-with-x11-starts-and-fails-to-open-glew-could-not-be-initialized-missing-gl-version/3629/18

ENV LIBGL_ALWAYS_INDIRECT=1
ENV QT_MAC_WANTS_LAYER=1

RUN apt-get install -y


