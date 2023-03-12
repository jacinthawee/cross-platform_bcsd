
DSA_SIG * dsa_do_sign(uchar *param_1,int param_2,DSA *param_3)

{
  bool bVar1;
  BN_CTX *ctx_in;
  int iVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  DSA_SIG *pDVar6;
  BIGNUM *a;
  BIGNUM *local_50;
  BIGNUM *local_4c;
  BIGNUM BStack_48;
  BIGNUM BStack_34;
  
  local_50 = (BIGNUM *)0x0;
  local_4c = (BIGNUM *)0x0;
  BN_init(&BStack_48);
  BN_init(&BStack_34);
  a = param_3->p;
  if (((a == (BIGNUM *)0x0) || (a = param_3->q, a == (BIGNUM *)0x0)) ||
     (a = param_3->g, a == (BIGNUM *)0x0)) {
    iVar2 = 0x65;
  }
  else {
    a = BN_new();
    if ((a != (BIGNUM *)0x0) && (ctx_in = BN_CTX_new(), ctx_in != (BN_CTX *)0x0)) {
      do {
        pBVar5 = param_3->kinv;
        if ((pBVar5 == (BIGNUM *)0x0) || (pBVar4 = param_3->r, pBVar4 == (BIGNUM *)0x0)) {
          iVar2 = DSA_sign_setup(param_3,ctx_in,&local_50,&local_4c);
          if (iVar2 != 0) {
            bVar1 = false;
            goto LAB_0009841e;
          }
LAB_000984be:
          iVar2 = 3;
          goto LAB_000984c0;
        }
        bVar1 = true;
        param_3->kinv = (BIGNUM *)0x0;
        param_3->r = (BIGNUM *)0x0;
        local_50 = pBVar5;
        local_4c = pBVar4;
LAB_0009841e:
        iVar3 = BN_num_bits(param_3->q);
        iVar2 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          iVar2 = iVar3 + 0xe;
        }
        if (iVar2 >> 3 < param_2) {
          iVar2 = BN_num_bits(param_3->q);
          param_2 = iVar2 + 0xe;
          if (-1 < iVar2 + 7) {
            param_2 = iVar2 + 7;
          }
          param_2 = param_2 >> 3;
          pBVar5 = BN_bin2bn(param_1,param_2,&BStack_48);
          if (pBVar5 != (BIGNUM *)0x0) goto LAB_00098442;
          goto LAB_000984be;
        }
        pBVar5 = BN_bin2bn(param_1,param_2,&BStack_48);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_000984be;
LAB_00098442:
        iVar2 = BN_mod_mul(&BStack_34,param_3->priv_key,local_4c,param_3->q,ctx_in);
        if (((iVar2 == 0) || (iVar2 = BN_add(a,&BStack_34,&BStack_48), iVar2 == 0)) ||
           ((iVar2 = BN_cmp(a,param_3->q), 0 < iVar2 && (iVar2 = BN_sub(a,a,param_3->q), iVar2 == 0)
            ))) goto LAB_000984be;
        iVar2 = BN_mod_mul(a,a,local_50,param_3->q,ctx_in);
        if (iVar2 == 0) goto LAB_000984be;
        if ((local_4c->top != 0) && (a->top != 0)) {
          pDVar6 = DSA_SIG_new();
          if (pDVar6 == (DSA_SIG *)0x0) goto LAB_000984be;
          pDVar6->r = local_4c;
          pDVar6->s = a;
          goto LAB_000984e2;
        }
      } while (!bVar1);
      iVar2 = 0x6e;
LAB_000984c0:
      ERR_put_error(10,0x70,iVar2,"dsa_ossl.c",0xd1);
      BN_free(local_4c);
      pDVar6 = (DSA_SIG *)0x0;
      BN_free(a);
LAB_000984e2:
      BN_CTX_free(ctx_in);
      goto LAB_000984e8;
    }
    iVar2 = 3;
  }
  ERR_put_error(10,0x70,iVar2,"dsa_ossl.c",0xd1);
  BN_free(local_4c);
  pDVar6 = (DSA_SIG *)0x0;
  BN_free(a);
LAB_000984e8:
  BN_clear_free(&BStack_48);
  BN_clear_free(&BStack_34);
  if (local_50 != (BIGNUM *)0x0) {
    BN_clear_free(local_50);
  }
  return pDVar6;
}

