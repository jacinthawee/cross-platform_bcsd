
int SSL_read(SSL *ssl,void *buf,int num)

{
  int iVar1;
  
  if (ssl->handshake_func == (_func_3149 *)0x0) {
    ERR_put_error(0x14,0xdf,0x114,"ssl_lib.c",0x3c1);
    iVar1 = -1;
  }
  else {
    if (-1 < ssl->shutdown << 0x1e) {
                    /* WARNING: Could not recover jumptable at 0x000609ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*ssl->method->ssl_read)(ssl,buf,num);
      return iVar1;
    }
    iVar1 = 0;
    ssl->rwstate = 1;
  }
  return iVar1;
}

