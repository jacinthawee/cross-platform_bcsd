
int ec_GFp_mont_field_encode(int param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  BN_MONT_CTX *mont;
  int iVar1;
  
  mont = *(BN_MONT_CTX **)(param_1 + 0xa0);
  if (mont != (BN_MONT_CTX *)0x0) {
    iVar1 = BN_mod_mul_montgomery(param_2,param_3,&mont->RR,mont,param_4);
    return iVar1;
  }
  ERR_put_error(0x10,0x86,0x6f,"ecp_mont.c",0x124);
  return 0;
}

