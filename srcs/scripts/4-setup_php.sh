#!/bin/bash
sudo apt-get install -y php7.3-fpm
echo "$cfg['blowfish_secret'] = 'STRINGOFTHIRTYTWORANDOMCHARACTERS';" >> \
/var/www/html/phpmyadmin/config.inc.php
echo "$cfg['TempDir'] = '/var/www/html/phpmyadmin/tmp';" >> \
/var/www/html/phpmyadmin/config.inc.php
service php7.3-fpm start
#php7.3-cli php7.3-mysql php7.3-gd php7.3-imagick php7.3-recode php7.3-tidy php7.3-xmlrpc
