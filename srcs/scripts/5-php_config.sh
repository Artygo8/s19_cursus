#!/bin/bash
chmod -R 755 /var/www/*
chown -R www-data:www-data /var/www/*
nginx -t
service nginx reload
