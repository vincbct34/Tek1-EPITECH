#!/bin/sh
sed -e 's/theo1/Wile E. Coyote/' | sed -e 's/steven1/Daffy Duck/' | sed -e 's/arnaud1/Porky Pig/' | sed -e 's/pierre-jean/Marvin the Martian/' | grep -e "Wile E. Coyote" -e "Daffy Duck" -e "Porky Pig" -e "Marvin the Martian"
