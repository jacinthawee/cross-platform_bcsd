
int SSL_write(SSL *ssl,void *buf,int num)

{
  int iVar1;
  
  if (ssl->handshake_func == (_func_3149 *)0x0) {
    ERR_put_error(0x14,0xd0,0x114,"ssl_lib.c",0x3e0);
  }
  else {
    if ((*(byte *)&ssl->shutdown & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x080c0843. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*ssl->method->ssl_write)(ssl,buf,num);
      return iVar1;
    }
    ssl->rwstate = 1;
    ERR_put_error(0x14,0xd0,0xcf,"ssl_lib.c",999);
  }
  return -1;
}

