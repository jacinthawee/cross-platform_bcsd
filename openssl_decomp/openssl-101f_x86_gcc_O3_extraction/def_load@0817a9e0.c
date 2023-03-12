
undefined4 def_load(undefined4 param_1,char *param_2,undefined4 param_3)

{
  BIO *a;
  undefined4 uVar1;
  ulong uVar2;
  int reason;
  int line;
  
  a = BIO_new_file(param_2,"rb");
  if (a != (BIO *)0x0) {
    uVar1 = def_load_bio(param_1,a,param_3);
    BIO_free(a);
    return uVar1;
  }
  uVar2 = ERR_peek_last_error();
  if ((uVar2 & 0xfff) == 0x80) {
    line = 0xc5;
    reason = 0x72;
  }
  else {
    line = 199;
    reason = 2;
  }
  ERR_put_error(0xe,0x78,reason,"conf_def.c",line);
  return 0;
}

