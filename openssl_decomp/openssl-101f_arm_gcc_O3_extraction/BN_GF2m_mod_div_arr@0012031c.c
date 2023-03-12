
undefined4
BN_GF2m_mod_div_arr(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                   BN_CTX *param_5)

{
  BIGNUM *a;
  undefined4 uVar1;
  int iVar2;
  
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  if (a != (BIGNUM *)0x0) {
    BN_set_word(a,0);
    iVar2 = *param_4;
    while( true ) {
      if (iVar2 == -1) {
        uVar1 = BN_GF2m_mod_div(param_1,param_2,param_3,a,param_5);
        BN_CTX_end(param_5);
        return uVar1;
      }
      iVar2 = BN_set_bit(a,iVar2);
      if (iVar2 == 0) break;
      param_4 = param_4 + 1;
      iVar2 = *param_4;
    }
  }
  BN_CTX_end(param_5);
  return 0;
}

