
int SSL_peek(SSL *ssl,void *buf,int num)

{
  int iVar1;
  
  if (ssl->handshake_func == (_func_3149 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10e,0x114,"ssl_lib.c",0x3d1);
    return -1;
  }
  if ((ssl->shutdown & 2U) != 0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x004a80a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*ssl->method->ssl_peek)(ssl,buf,num);
  return iVar1;
}

