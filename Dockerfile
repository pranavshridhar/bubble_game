FROM ubuntu:22.04

ARG MODE=release

RUN apt update && apt install -y \
  build-essential \
  gdb \
  libgtest-dev \
  git \
  cmake \
  && rm -rf /var/lib/apt/lists/*

# Build and install GoogleTest
RUN cd /usr/src/gtest && cmake . && make && cp lib/*.a /usr/lib

WORKDIR /app

# Conditionally build based on mode
RUN if [ "$MODE" = "debug" ]; \
then make debug; \
else make; \
fi

# Conditionally run based on mode
CMD if [ "$MODE" = "debug" ]; \
  then gdb ./bubblepop_debug; \
  else ./bubblepop; fi
