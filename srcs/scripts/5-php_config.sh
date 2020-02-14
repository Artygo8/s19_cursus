#!/bin/bash
echo -e "\033[42mPhp stuffs\t\t\t\t\033[0m"
apt install -y php-{mbstring,zip,gd,xml,pear,gettext,cgi}

echo -e "\033[42mphpmyadmin\t\t\t\t\033[0m"
	echo "$cfg['blowfish_secret'] = 'STRINGOFTHIRTYTWORANDOMCHARACTERS';" >> \
	/var/www/html/phpmyadmin/config.inc.php
	echo "$cfg['TempDir'] = '/var/lib/phpmyadmin/tmp';" >> \
	/var/www/html/phpmyadmin/config.inc.php
	chmod 660 /var/www/html/phpmyadmin/config.inc.php
	chown -R www-data:www-data /var/www/html/phpmyadmin
