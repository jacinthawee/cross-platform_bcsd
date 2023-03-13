
int ECDSA_sign_ex(int type,uchar *dgst,int dgstlen,uchar *sig,uint *siglen,BIGNUM *kinv,BIGNUM *rp,
                 EC_KEY *eckey)

{
  EC_KEY *pEVar1;
  int iVar2;
  ECDSA_SIG *sig_00;
  uint uVar3;
  
  pEVar1 = eckey;
  RAND_seed(dgst,dgstlen);
  iVar2 = ecdsa_check(pEVar1);
  if (iVar2 != 0) {
    sig_00 = (ECDSA_SIG *)(**(code **)(*(int *)(iVar2 + 0xc) + 4))(dgst,dgstlen,kinv,rp,pEVar1);
    if (sig_00 != (ECDSA_SIG *)0x0) {
      uVar3 = i2d_ECDSA_SIG(sig_00,&sig);
      *siglen = uVar3;
      ECDSA_SIG_free(sig_00);
      return 1;
    }
  }
  *siglen = 0;
  return 0;
}

