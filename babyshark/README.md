# Babyshark Problem Creation Walkthrough

## Overview

This problem uses a container as a service host and presents this service
through a port. This problem is adapted from the live picoGym problem, [Picker-I](https://play.picoctf.org/practice/challenge/400).

This problem can be used as a template for any challenge that needs to host a
service that players connect to with netcat.

The following walkthrough will touch on new problem files and then look at how
to debug a Dockerfile by running it with Docker instead of cmgr.

## Walkthrough

### File Listing

1. [babyshark.exe](/babyshark/babyshark.exe) this is the executable that will be downloaded and analyzed by the players.

1. [challenge.py](/babyshark/challenge.py) this is the script that we will run on the container to match the binary flag and give out a random flag.

1. [Project2](/babyshark/Project2/Project2/win32.cpp) this is the main source code of our executable. To build it, install visual studio and the Desktop Development with C++ workload.

1. [start.sh](babyshark/start.sh) starts a listener
   that receives connections. This script is ran as the last step in the
   Dockerfile. For this problem, we use socat to connect the output of our
   vulnerable script to a port, allowing users to interact with our script
   through the network.

1. [setup-challenge.py](babyshark/setup-challenge.py)
   This script generates the flag for the problem and saves it in the important
   file, `/challenge/metadata.json`, which is required for every cmgr problem.

1. [Dockerfile](babyshark/Dockerfile) this is the main
   setup for our problem. We pull down a pinned Ubuntu image, update it and
   install the required packages. We create the `/challenge` directory with
   specific permissions so only root can access it. `/challenge` is an
   important directory and contains files that cmgr needs to deploy a problem.
   We add `artifacts.tar.gz` to this directory as well, which contains a copy
   of the source for the service being run on the container.
