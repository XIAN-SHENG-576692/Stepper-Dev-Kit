#!/bin/bash

SCRIPT_DIR=$(cd $(dirname $0); pwd)

ENV_DIR="${SCRIPT_DIR}/env"
CONFIG_ENV="${ENV_DIR}/config.env"

cat <<EOF > "${CONFIG_ENV}"
PYTHON_ENV_DIR="${ENV_DIR}/python"
PYTHON_REQUIREMENTS_TXT="\${PYTHON_ENV_DIR}/requirements.txt"
PYTHON_VENV="\${PYTHON_ENV_DIR}/venv"
PYTHON_VENV_ACTIVATE="\${PYTHON_VENV}/bin/activate"
EOF
