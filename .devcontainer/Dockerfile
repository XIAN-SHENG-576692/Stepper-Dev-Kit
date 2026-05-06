FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive

WORKDIR /workspace

RUN apt-get update -y && apt-get install -y \
    build-essential \
    cmake \
    clang-format \
    git \
    zip \
    && rm -rf /var/lib/apt/lists/*

CMD ["sleep", "infinity"]
