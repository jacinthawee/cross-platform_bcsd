
bool ec_GFp_nist_field_mul
               (int param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  int iVar1;
  BN_CTX *ctx;
  bool bVar2;
  
  if ((((param_1 == 0) || (param_2 == (BIGNUM *)0x0)) || (param_3 == (BIGNUM *)0x0)) ||
     (param_4 == (BIGNUM *)0x0)) {
    ERR_put_error(0x10,200,0x43,"ecp_nist.c",0xb1);
  }
  else if (param_5 == (BN_CTX *)0x0) {
    ctx = BN_CTX_new();
    if (ctx != (BN_CTX *)0x0) {
      bVar2 = false;
      iVar1 = BN_mul(param_2,param_3,param_4,ctx);
      if (iVar1 != 0) {
        iVar1 = (**(code **)(param_1 + 0xa8))(param_2,param_2,param_1 + 0x48,ctx);
        bVar2 = iVar1 != 0;
      }
      BN_CTX_free(ctx);
      return bVar2;
    }
  }
  else {
    iVar1 = BN_mul(param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(param_1 + 0xa8))(param_2,param_2,param_1 + 0x48,param_5);
      return iVar1 != 0;
    }
  }
  return false;
}

