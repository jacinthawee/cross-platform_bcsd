
int DSA_sign_setup(DSA *dsa,BN_CTX *ctx_in,BIGNUM **kinvp,BIGNUM **rp)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*dsa->meth->dsa_sign_setup)(dsa,ctx_in,kinvp,rp);
  return iVar1;
}

