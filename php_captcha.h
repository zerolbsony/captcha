#ifndef PHP_CAPTCHA_H
#define PHP_CAPTCHA_H

#define PHP_CAPTCHA_EXTNAME   "captcha"
#define PHP_CAPTCHA_EXTVER    "1.0"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

extern zend_module_entry captcha_module_entry;
#define phpext_captcha_ptr &captcha_module_entry;
/*extern zend_module_entry captcha_module_entry;*/

#endif
