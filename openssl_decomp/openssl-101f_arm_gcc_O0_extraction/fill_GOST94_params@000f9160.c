
undefined4 fill_GOST94_params(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  puVar2 = R3410_paramset;
  if (R3410_paramset._0_4_ == 0) {
LAB_000f9186:
    ERR_GOST_error(0x66,0x82,"gost_sign.c",0xdd,param_4);
    return 0;
  }
  if (R3410_paramset._0_4_ != param_2) {
    do {
      puVar2 = (undefined1 *)((int)puVar2 + 0x10);
      if (*(int *)puVar2 == 0) goto LAB_000f9186;
    } while (*(int *)puVar2 != param_2);
  }
  if (*(BIGNUM **)(param_1 + 0xc) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0xc));
  }
  pcVar1 = *(char **)((int)puVar2 + 8);
  *(BIGNUM **)(param_1 + 0xc) = (BIGNUM *)0x0;
  BN_dec2bn((BIGNUM **)(param_1 + 0xc),pcVar1);
  if (*(BIGNUM **)(param_1 + 0x10) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0x10));
  }
  pcVar1 = *(char **)((int)puVar2 + 0xc);
  *(BIGNUM **)(param_1 + 0x10) = (BIGNUM *)0x0;
  BN_dec2bn((BIGNUM **)(param_1 + 0x10),pcVar1);
  if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0x14));
  }
  pcVar1 = *(char **)((int)puVar2 + 4);
  *(BIGNUM **)(param_1 + 0x14) = (BIGNUM *)0x0;
  BN_dec2bn((BIGNUM **)(param_1 + 0x14),pcVar1);
  return 1;
}

