
int SSL_read(SSL *ssl,void *buf,int num)

{
  int iVar1;
  
  if (ssl->handshake_func == (_func_3149 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xdf,0x114,"ssl_lib.c",0x3c3);
    return -1;
  }
  if ((ssl->shutdown & 2U) != 0) {
    ssl->rwstate = 1;
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x004a8028. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*ssl->method->ssl_read)(ssl,buf,num);
  return iVar1;
}

