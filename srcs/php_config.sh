#!/bin/bash
echo "$cfg['blowfish_secret'] = 'STRINGOFTHIRTYTWORANDOMCHARACTERS';" >> \
	/usr/share/phpmyadmin/config.inc.php
echo "$cfg['TempDir'] = '/var/lib/phpmyadmin/tmp';" >> \
	/usr/share/phpmyadmin/config.inc.php
