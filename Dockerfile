FROM ubuntu:22.04

RUN apt update && apt install -y \
  build-essential \
  gdb \
  libgtest-dev \
  git \
  cmake \
  && rm -rf /var/lib/apt/lists/*

RUN cd /usr/src/gtest && cmake . && make && cp lib/*.a /usr/lib
WORKDIR /app

COPY . .

RUN make

RUN echo "🧭 CURRENT DIR:" && pwd && echo "📂 CONTENTS:" && ls -al && sleep 10

CMD ["./bubblepop"]