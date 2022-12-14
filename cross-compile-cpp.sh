#!/bin/bash
make -C tool/cpp/requirements install-requirements
make -C tool/cpp cross-compile
