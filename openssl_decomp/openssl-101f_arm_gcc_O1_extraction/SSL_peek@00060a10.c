
int SSL_peek(SSL *ssl,void *buf,int num)

{
  int iVar1;
  
  if (ssl->handshake_func == (_func_3149 *)0x0) {
    ERR_put_error(0x14,0x10e,0x114,"ssl_lib.c",0x3d1);
    iVar1 = -1;
  }
  else {
    if (-1 < ssl->shutdown << 0x1e) {
                    /* WARNING: Could not recover jumptable at 0x00060a32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*ssl->method->ssl_peek)(ssl,buf,num);
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

