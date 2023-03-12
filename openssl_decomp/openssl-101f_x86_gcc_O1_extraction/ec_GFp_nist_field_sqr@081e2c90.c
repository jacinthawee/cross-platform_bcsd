
bool ec_GFp_nist_field_sqr(int param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  int iVar1;
  BN_CTX *ctx;
  bool bVar2;
  
  if ((param_2 == (BIGNUM *)0x0 || param_3 == (BIGNUM *)0x0) || (param_1 == 0)) {
    ERR_put_error(0x10,0xc9,0x86,"ecp_nist.c",0xca);
  }
  else if (param_4 == (BN_CTX *)0x0) {
    ctx = BN_CTX_new();
    if (ctx != (BN_CTX *)0x0) {
      iVar1 = BN_sqr(param_2,param_3,ctx);
      if (iVar1 == 0) {
        bVar2 = false;
      }
      else {
        iVar1 = (**(code **)(param_1 + 0xa8))(param_2,param_2,param_1 + 0x48,ctx);
        bVar2 = iVar1 != 0;
      }
      BN_CTX_free(ctx);
      return bVar2;
    }
  }
  else {
    iVar1 = BN_sqr(param_2,param_3,param_4);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(param_1 + 0xa8))(param_2,param_2,param_1 + 0x48,param_4);
      return iVar1 != 0;
    }
  }
  return false;
}

