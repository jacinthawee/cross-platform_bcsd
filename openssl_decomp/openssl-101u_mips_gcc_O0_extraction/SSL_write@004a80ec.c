
int SSL_write(SSL *ssl,void *buf,int num)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = PTR_ERR_put_error_006a7f34;
  if (ssl->handshake_func == (_func_3149 *)0x0) {
    uVar4 = 0x114;
    uVar3 = 0x3de;
  }
  else {
    if ((ssl->shutdown & 1U) == 0) {
                    /* WARNING: Could not recover jumptable at 0x004a8120. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*ssl->method->ssl_write)(ssl,buf,num);
      return iVar2;
    }
    uVar4 = 0xcf;
    ssl->rwstate = 1;
    uVar3 = 0x3e4;
  }
  (*(code *)puVar1)(0x14,0xd0,uVar4,"ssl_lib.c",uVar3);
  return -1;
}

