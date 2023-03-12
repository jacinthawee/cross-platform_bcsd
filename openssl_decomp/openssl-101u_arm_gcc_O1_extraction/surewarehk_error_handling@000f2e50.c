
void surewarehk_error_handling(char *param_1,int param_2,undefined4 param_3)

{
  size_t len;
  
  switch(param_3) {
  case 1:
    *param_1 = '\0';
    return;
  case 0xfffffffb:
    ERR_put_error(0x26,param_2,0x6a,"e_sureware.c",0x27b);
    break;
  case 0xfffffffc:
    ERR_put_error(0x26,param_2,0x67,"e_sureware.c",0x278);
    break;
  case 0xfffffffd:
    ERR_put_error(0x26,param_2,0x68,"e_sureware.c",0x272);
    break;
  case 0xfffffffe:
    ERR_put_error(0x26,param_2,0x66,"e_sureware.c",0x275);
    break;
  default:
    ERR_put_error(0x26,param_2,0x65,"e_sureware.c",0x27e);
  }
  if ((*param_1 != '\0') && (ERR_add_error_data(1,param_1), logstream != (BIO *)0x0)) {
    CRYPTO_lock(9,0x15,"e_sureware.c",0x286);
    len = strlen(param_1);
    BIO_write(logstream,param_1,len);
    CRYPTO_lock(10,0x15,"e_sureware.c",0x288);
    return;
  }
  return;
}

