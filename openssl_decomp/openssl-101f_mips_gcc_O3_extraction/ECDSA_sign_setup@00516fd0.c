
int ECDSA_sign_setup(EC_KEY *eckey,BN_CTX *ctx,BIGNUM **kinv,BIGNUM **rp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ecdsa_check_006a9890)();
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00517040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)(iVar1 + 0xc) + 8))(eckey,ctx,kinv,rp);
    return iVar1;
  }
  return 0;
}

