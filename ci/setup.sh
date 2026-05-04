#!/bin/sh

# Configuration
SCRIPT_DIR=$(cd $(dirname $0); pwd)

ENV_DIR="${SCRIPT_DIR}/../env"

chmod +x "${ENV_DIR}/*.sh"
"${ENV_DIR}/gen_env.sh"

# Installation
sudo apt update -y && sudo apt install -y \
    build-essential \
    cmake \
    zip \
    && sudo rm -rf /var/lib/apt/lists/*
