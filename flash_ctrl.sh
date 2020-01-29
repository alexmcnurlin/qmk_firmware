#! /usr/bin/env bash

LOADER_DIR="/mnt/c/Users/alexmcnurlin/Google Drive/Misc/Portable Programs/Ctrl Flasher/"

ls "$LOADER_DIR"
FILENAME="massdrop_ctrl_alexmcnu.bin"

make massdrop/ctrl:alexmcnu || exit
mv "$FILENAME" "$LOADER_DIR"
pushd "$LOADER_DIR"

./mdloader_windows.exe --first --download "$FILENAME" --restart

popd


