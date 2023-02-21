#!/user/bin/env bash

python -m pip install --upgrade pip setuptools wheel

python setup.py sdist bdist_wheel

pip install ./dist/ai42-1.0.0.tar.gz
