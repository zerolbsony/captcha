#include "php_captcha.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

PHP_FUNCTION(generate_captcha)
{
     zval dictpath;
     zval amount;
     FILE *fp;
     char *dictdata;
     zval data;
     int i;
     if(0 == zend_get_constant("CAPTCHA_DICTPATH", 16, &dictpath TSRMLS_CC)){
		char *s1 = '0';
     }else{
        if(Z_TYPE(dictpath) == IS_STRING){
			char *s1 = Z_STRVAL(dictpath);
		}
     }
     if(0 == zend_get_constant("CAPTCHA_AMOUNT", 14, &amount TSRMLS_CC)){
		int amt = 5;
     }else{
        if(Z_TYPE(amount) == IS_LONG){
			int amt = Z_LVAL(amount);
		}
     }
   
     if(s1 == '0'){
		php_printf(s1);
	 }else{
		char s2[10];
		int j;
		memset(s2, 0, sizeof(s2));
		for(i=0; i<amt; i++){
			j = rand() % Z_STRLEN(dictpath);
			memcpy(s2, s1+j, 1);
			php_printf(s2);
			memset(s2, 0, sizeof(s2));
		}
	 }
}

static zend_function_entry php_captcha_functions[] = {
     PHP_FE(generate_captcha, NULL)
     {NULL, NULL, NULL}
};

zend_module_entry captcha_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
     STANDARD_MODULE_HEADER,
#endif
     PHP_CAPTCHA_EXTNAME,
     php_captcha_functions,
     NULL,               /* Module init callback */
     NULL,           /* Module shutdown callback */
     NULL,               /* Request init callback */
     NULL,           /* Request shutdown callback */
     NULL,
#if ZEND_MODULE_API_NO >= 20010901
     PHP_CAPTCHA_EXTVER,
#endif
     STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(captcha)
