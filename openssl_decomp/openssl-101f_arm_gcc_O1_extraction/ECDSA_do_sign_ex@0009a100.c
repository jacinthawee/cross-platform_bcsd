
ECDSA_SIG * ECDSA_do_sign_ex(uchar *dgst,int dgstlen,BIGNUM *kinv,BIGNUM *rp,EC_KEY *eckey)

{
  int iVar1;
  ECDSA_SIG *pEVar2;
  
  iVar1 = ecdsa_check(eckey);
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0009a12e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pEVar2 = (ECDSA_SIG *)(**(code **)(*(int *)(iVar1 + 0xc) + 4))(dgst,dgstlen,kinv,rp);
    return pEVar2;
  }
  return (ECDSA_SIG *)0x0;
}
