
long SSL_get_default_timeout(SSL *s)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000609c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*s->method->get_timeout)();
  return lVar1;
}

