
int ECDSA_sign_setup(EC_KEY *eckey,BN_CTX *ctx,BIGNUM **kinv,BIGNUM **rp)

{
  int iVar1;
  
  iVar1 = ecdsa_check();
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000989ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)(iVar1 + 0xc) + 8))(eckey,ctx,kinv,rp);
    return iVar1;
  }
  return 0;
}

