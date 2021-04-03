# Dockerfile
# chrono@2021-03

# curl -fsSL https://get.docker.com | bash -s docker --mirror Aliyun
# sudo service docker start
# sudo usermod -aG docker ${USER}

# docker build -t chronolaw/cpp_note .
# SRC_IMAGE=gcc:7  docker build -f Dockerfile -t chronolaw/cpp_base:gcc7  .
# SRC_IMAGE=gcc:10 docker build -f Dockerfile -t chronolaw/cpp_base:gcc10 .

# docker run -it --rm chronolaw/cpp_note

ARG SRC_IMAGE="gcc:7"
#ARG SRC_IMAGE="gcc:10"

FROM ${SRC_IMAGE}

WORKDIR /root

#RUN DEBIAN_FRONTEND=noninteractive apt-get update \
#    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
#        vim cmake gdb pstack strace  \
#        libmsgpack-dev protobuf-compiler libprotobuf-dev libprotoc-dev \
#        libcurl4-openssl-dev libzmq3-dev \
#        python3-dev python3-pip \
#        google-perftools libgoogle-perftools-dev \
#    && pip3 install pybind11 \
#    && DEBIAN_FRONTEND=noninteractive apt-get autoremove -y

COPY setup.sh /tmp

RUN /tmp/setup.sh

CMD ["/bin/bash"]
