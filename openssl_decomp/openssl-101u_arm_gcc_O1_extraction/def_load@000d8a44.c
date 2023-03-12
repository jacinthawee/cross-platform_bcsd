
BIO * def_load(undefined4 param_1,char *param_2,undefined4 param_3)

{
  BIO *a;
  BIO *pBVar1;
  ulong uVar2;
  
  a = BIO_new_file(param_2,"rb");
  if (a == (BIO *)0x0) {
    uVar2 = ERR_peek_last_error();
    if ((uVar2 & 0xfff) != 0x80) {
      ERR_put_error(0xe,0x78,2,"conf_def.c",0xc5);
      return (BIO *)0x0;
    }
    ERR_put_error(0xe,0x78,0x72,"conf_def.c",0xc3);
  }
  else {
    pBVar1 = (BIO *)def_load_bio(param_1,a,param_3);
    BIO_free(a);
    a = pBVar1;
  }
  return a;
}

