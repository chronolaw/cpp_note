# Dockerfile
# chrono@2021-03

# curl -fsSL https://get.docker.com | bash -s docker --mirror Aliyun
# sudo service docker start
# sudo usermod -aG docker ${USER}

# docker build -f docker/Dockerfile -t chronolaw/cpp_note .
# docker build -f docker/Dockerfile -t chronolaw/cpp_note:gcc7 .
# docker build -f docker/Dockerfile -t chronolaw/cpp_note:gcc10 .

# docker build -t chronolaw/cpp_note .

# SRC_IMAGE=gcc:7  docker build -t chronolaw/cpp_note:gcc7  .
# SRC_IMAGE=gcc:10 docker build -t chronolaw/cpp_note:gcc10 .

# docker run -it --rm chronolaw/cpp_note

ARG SRC_IMAGE="chronolaw/cpp_base:gcc7"
#ARG SRC_IMAGE="chronolaw/cpp_base:gcc10"

FROM ${SRC_IMAGE}

#WORKDIR /root
WORKDIR /root/cpp_note

COPY setup.sh /tmp

#COPY env ./cpp_note/env
#COPY common ./cpp_note/common
#COPY docker/setup.sh /tmp

RUN /tmp/setup.sh

CMD ["/bin/bash"]
