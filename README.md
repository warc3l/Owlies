[![Build Status](https://travis-ci.org/warc3l/Owlies.svg?branch=master)](https://travis-ci.org/warc3l/Owlies)


## Introduction

**Owlies** is a basic image-manipulation open-source software. Implemented in C++11, **Owlies** uses OpenCV and Qt frameworks. 
It can be used to learn about these two frameworks, and basic Deep Neuron Network to recognize some objects on the image.

<div align="center">
    <img src="https://image.ibb.co/c1iPK8/Screenshot_from_2018_07_07_23_09_13.png"><br><br>
</div>


## Installation

All the dependencies to compile it are listed on the Dockerfile. You can copy the container warc3l/owlies from Docker Hub to get all necessary dependencies, 
and then generate the executable with make. Execute the following commands to create Owlies:

``` shell
$ docker pull warc3l/owlies
$ git clone https://www.github.com/warc3l/Owlies <repository_path>/Owlies
$ docker run -v <repository_path>/Owlies:/Owlies -it warc3l/owlies
$ cd Owlies && cmake . && make
$ exit
```
To execute Owlies, go to <repository_path>/Owlies, outside the container, and execute:
```shell
./Owlies
``` 

Enjoy!

## Author

All the software has been written by Marcel Vilalta i Soler (marcel.vilalta@gmail.com). Any question, suggestion, or simply meet, contact with me.
