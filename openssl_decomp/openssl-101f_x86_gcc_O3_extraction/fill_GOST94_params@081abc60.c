
undefined4 fill_GOST94_params(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (R3410_paramset._0_4_ == 0) {
LAB_081abc95:
    ERR_GOST_error(0x66,0x82,"gost_sign.c",0xdd);
    return 0;
  }
  puVar1 = R3410_paramset;
  if (param_2 != R3410_paramset._0_4_) {
    do {
      puVar1 = (undefined1 *)((int)puVar1 + 0x10);
      if (*(int *)puVar1 == 0) goto LAB_081abc95;
    } while (*(int *)puVar1 != param_2);
  }
  if (*(BIGNUM **)(param_1 + 0xc) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0xc));
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  BN_dec2bn((BIGNUM **)(param_1 + 0xc),*(char **)((int)puVar1 + 8));
  if (*(BIGNUM **)(param_1 + 0x10) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  BN_dec2bn((BIGNUM **)(param_1 + 0x10),*(char **)((int)puVar1 + 0xc));
  if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0x14));
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  BN_dec2bn((BIGNUM **)(param_1 + 0x14),*(char **)((int)puVar1 + 4));
  return 1;
}

