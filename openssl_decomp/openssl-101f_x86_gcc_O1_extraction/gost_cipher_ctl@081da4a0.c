
undefined4 gost_cipher_ctl(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 6) {
    iVar1 = RAND_bytes((uchar *)param_4,*(int *)(param_1 + 0x58));
    if (0 < iVar1) {
      return 1;
    }
    ERR_GOST_error(0x6f,0x7b,"gost_crypt.c",0x18e);
    uVar2 = 0xffffffff;
  }
  else if (param_2 == 7) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x32a;
      return 1;
    }
    uVar2 = 0;
  }
  else {
    ERR_GOST_error(0x6f,0x81,"gost_crypt.c",0x19c);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

