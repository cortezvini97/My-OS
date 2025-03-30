# My OS

Simple Kernel development x86

## Install Packages

```bash
sudo apt update && sudo apt install -y \
    build-essential \
    g++ \
    gcc \
    gdb \
    ghex \
    git \
    grub2-common \
    grub-pc-bin \
    lcov \
    libgtest-dev \
    nasm \
    xorriso \
    python3 \
    python3-pip \
    qemu \
    qemu-kvm \
    qemu-system-x86 \
    qemu-utils \
    bridge-utils \
    libvirt-daemon-system \
    libvirt-clients

```

## Build Project

```bash
make build
```
## Clean project

```bash
make clean
```

## Run Project

```bash
make run
make runbuild
```