captcha
=======

php扩展实现的验证码生成函数
shell>/usr/local/php/bin/phpize
shell>./configure --with-php-config=/usr/local/php/bin/php-config
如有问题可使用下面的：
./configure --enable-captcha-zts --with-php-config=/usr/local/php/bin/php-config
shell>make && make install

配置php.ini
[captcha]
extension=captcha.so

下面是php代码示例：
<?php
//定义要生成的验证码个数
define('CAPTCHA_AMOUNT', 5);
//验证码词库
define('CAPTCHA_DICTPATH', 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789');
echo generate_captcha();
?>