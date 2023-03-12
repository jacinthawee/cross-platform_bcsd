
int SSL_pending(SSL *s)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0005e450. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*s->method->ssl_pending)(s);
  return iVar1;
}

