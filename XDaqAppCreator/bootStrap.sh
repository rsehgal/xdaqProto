#!/bin/sh
SRCDIR=`pwd`
echo "#!/bin/sh" > env.sh
echo "export SRCDIR="$SRCDIR >> env.sh
