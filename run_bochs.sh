#!/bin/zsh

sudo losetup /dev/loop0 ./artifacts/floppy.img
sudo bochs -qf bochsrc
sudo losetup -d /dev/loop0
