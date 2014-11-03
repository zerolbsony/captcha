PHP_ARG_ENABLE(captcha,
  [Whether to enable the "captcha" extension],
  [  enable-captcha        Enable "captcha" extension support])

if test $PHP_CAPTCHA != "no"; then
  PHP_SUBST(CAPTCHA_SHARED_LIBADD)
  PHP_NEW_EXTENSION(captcha, captcha.c, $ext_shared)
fi
