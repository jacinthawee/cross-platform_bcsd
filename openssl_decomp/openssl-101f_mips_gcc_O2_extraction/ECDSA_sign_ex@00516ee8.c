
int ECDSA_sign_ex(int type,uchar *dgst,int dgstlen,uchar *sig,uint *siglen,BIGNUM *kinv,BIGNUM *rp,
                 EC_KEY *eckey)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uchar *local_resc;
  
  local_resc = sig;
  RAND_seed(dgst,dgstlen);
  iVar2 = (*(code *)PTR_ecdsa_check_006a9890)(eckey);
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*(int *)(iVar2 + 0xc) + 4))(dgst,dgstlen,kinv,rp,eckey);
    if (iVar2 != 0) {
      uVar3 = (*(code *)PTR_i2d_ECDSA_SIG_006a9894)(iVar2,&local_resc);
      puVar1 = PTR_ECDSA_SIG_free_006a9898;
      *siglen = uVar3;
      (*(code *)puVar1)(iVar2);
      return 1;
    }
  }
  *siglen = 0;
  return 0;
}

