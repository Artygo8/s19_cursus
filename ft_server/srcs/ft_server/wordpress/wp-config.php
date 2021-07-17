<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'wordpressuser' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', '192.168.99.116:2376' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
 define('AUTH_KEY',         'b5Xg;Fd0( rR@OzWBEBpjRRbQC*E2@i-x_LFg`|.+I!G^DG28H3idIU^eK>Lv=yc');
 define('SECURE_AUTH_KEY',  'M/,PN16tCh^wY(h>:-i=u{W=2F{!$eJUrWkRMM{@-$v/pJ`(d6C2K[zzeiE7aiyS');
 define('LOGGED_IN_KEY',    'Xzx](q}PD2@%|4i6>*0&|lg@7-*USQMnD <$4/7!j4ctb?gO,rG;|VVWnPEAe?2%');
 define('NONCE_KEY',        '+wypN3_5q:wJjmEa=1pnuMxq/Z9:H.erlL8uj!3m$elK}Mad_t3nCl=R~P#78<,`');
 define('AUTH_SALT',        'e-^jp=S=L_k>t>L%oCP-C:>H|9,;w6Xb|-Apr}I|a-U.{D6!|%2U!(at8EWE|Pgp');
 define('SECURE_AUTH_SALT', ' IHrXcH5g3gv}X/Wr)-ob=N~B[i!^t_+C)+ _1%k25;FZLJ]?vjB34^1vwaRu47$');
 define('LOGGED_IN_SALT',   'DAt)XD!U@@HIiS%kkV6z46{04FG]bcDzFR{a|jn+V&A3T>-BtebqQVk^K4e i_a ');
 define('NONCE_SALT',       'D]zX%o8!r#3xy|oDIKD3Ye!MMlba/]d`~yGJW|ydH `f%Jg7+xKnC%{Dw~Si(!}e');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
