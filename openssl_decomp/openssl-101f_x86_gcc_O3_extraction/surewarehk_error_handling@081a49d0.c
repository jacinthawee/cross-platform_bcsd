
void __regparm3 surewarehk_error_handling(char *param_1,int param_2,undefined4 param_3)

{
  size_t len;
  int mode;
  
  switch(param_3) {
  case 1:
    *param_1 = '\0';
    return;
  case 0xfffffffb:
    ERR_put_error(0x26,param_2,0x6a,"e_sureware.c",0x254);
    break;
  case 0xfffffffc:
    ERR_put_error(0x26,param_2,0x67,"e_sureware.c",0x251);
    break;
  case 0xfffffffd:
    ERR_put_error(0x26,param_2,0x68,"e_sureware.c",0x24b);
    break;
  case 0xfffffffe:
    ERR_put_error(0x26,param_2,0x66,"e_sureware.c",0x24e);
    break;
  default:
    ERR_put_error(0x26,param_2,0x65,"e_sureware.c",599);
  }
  if ((*param_1 != '\0') && (ERR_add_error_data(1,param_1), logstream != (BIO *)0x0)) {
    CRYPTO_lock((int)logstream,9,(char *)0x15,(int)"e_sureware.c");
    len = strlen(param_1);
    mode = BIO_write(logstream,param_1,len);
    CRYPTO_lock(mode,10,(char *)0x15,(int)"e_sureware.c");
    return;
  }
  return;
}

