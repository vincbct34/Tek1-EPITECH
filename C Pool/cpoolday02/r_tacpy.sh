#!/bin/sh
cut -d ":" -f1 | sed -n 2~2p | rev | sort -r | sed -n "$MY_LINE1","$MY_LINE2"p | sed -ze "s/\n/, /g" | sed -ze "s/, $/.\n/"
