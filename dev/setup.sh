#!/bin/bash

SCRIPT_DIR=$(cd $(dirname $0); pwd)

${SCRIPT_DIR}/gen_env.sh

CONFIG_ENV="${SCRIPT_DIR}/env/config.env"
. "${CONFIG_ENV}"

apt install -y \
    clang \
    libclang-16-dev \
    python3 \
    python3-pip \
    python3-venv \
    && python3 -m venv "${PYTHON_VENV}" \
    && source "${PYTHON_VENV_ACTIVATE}" \
    && pip3 install -r "${PYTHON_REQUIREMENTS_TXT}" \
    && pip3 list \
    && deactivate
