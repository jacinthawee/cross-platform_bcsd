
int SSL_read(SSL *ssl,void *buf,int num)

{
  int iVar1;
  
  if (ssl->handshake_func == (_func_3149 *)0x0) {
    ERR_put_error(0x14,0xdf,0x114,"ssl_lib.c",0x3c3);
    iVar1 = -1;
  }
  else {
    if ((*(byte *)&ssl->shutdown & 2) == 0) {
                    /* WARNING: Could not recover jumptable at 0x080bdea6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*ssl->method->ssl_read)(ssl,buf,num);
      return iVar1;
    }
    ssl->rwstate = 1;
    iVar1 = 0;
  }
  return iVar1;
}

