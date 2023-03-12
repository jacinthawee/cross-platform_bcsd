
BIGNUM * dsa_do_sign(uchar *param_1,int param_2,DSA *param_3)

{
  bool bVar1;
  BIGNUM *ctx_in;
  int iVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *r;
  BIGNUM *pBVar6;
  BIGNUM *local_58;
  BIGNUM *local_54;
  BIGNUM BStack_50;
  BIGNUM BStack_3c;
  
  pBVar6 = (BIGNUM *)0x0;
  local_58 = (BIGNUM *)0x0;
  local_54 = (BIGNUM *)0x0;
  BN_init(&BStack_50);
  BN_init(&BStack_3c);
  r = param_3->p;
  if (((r == (BIGNUM *)0x0) || (r = param_3->q, r == (BIGNUM *)0x0)) ||
     (r = param_3->g, r == (BIGNUM *)0x0)) {
    iVar2 = 0x65;
    ctx_in = r;
LAB_00099d6e:
    ERR_put_error(10,0x70,iVar2,"dsa_ossl.c",0xcc);
    BN_free(local_54);
    BN_free(r);
    if (ctx_in == (BIGNUM *)0x0) goto LAB_00099cf4;
    pBVar6 = (BIGNUM *)0x0;
  }
  else {
    r = BN_new();
    if (r == (BIGNUM *)0x0) {
      iVar2 = 3;
      ctx_in = r;
      goto LAB_00099d6e;
    }
    ctx_in = (BIGNUM *)BN_CTX_new();
    if (ctx_in == (BIGNUM *)0x0) {
LAB_00099d6c:
      iVar2 = 3;
      goto LAB_00099d6e;
    }
    do {
      pBVar5 = param_3->kinv;
      if ((pBVar5 == (BIGNUM *)0x0) || (pBVar4 = param_3->r, pBVar4 == (BIGNUM *)0x0)) {
        iVar2 = DSA_sign_setup(param_3,(BN_CTX *)ctx_in,&local_58,&local_54);
        if (iVar2 != 0) {
          bVar1 = false;
          goto LAB_00099c64;
        }
LAB_00099d32:
        if (pBVar6 == (BIGNUM *)0x0) {
          ERR_put_error(10,0x70,3,"dsa_ossl.c",0xcc);
          BN_free(local_54);
          BN_free(r);
        }
        break;
      }
      bVar1 = true;
      param_3->kinv = (BIGNUM *)0x0;
      param_3->r = (BIGNUM *)0x0;
      local_58 = pBVar5;
      local_54 = pBVar4;
LAB_00099c64:
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
        pBVar5 = BN_bin2bn(param_1,param_2,&BStack_50);
        if (pBVar5 != (BIGNUM *)0x0) goto LAB_00099c88;
        goto LAB_00099d32;
      }
      pBVar5 = BN_bin2bn(param_1,param_2,&BStack_50);
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_00099d32;
LAB_00099c88:
      iVar2 = BN_mod_mul(&BStack_3c,param_3->priv_key,local_54,param_3->q,(BN_CTX *)ctx_in);
      if ((((iVar2 == 0) || (iVar2 = BN_add(r,&BStack_3c,&BStack_50), iVar2 == 0)) ||
          ((iVar2 = BN_cmp(r,param_3->q), 0 < iVar2 && (iVar2 = BN_sub(r,r,param_3->q), iVar2 == 0))
          )) || (iVar2 = BN_mod_mul(r,r,local_58,param_3->q,(BN_CTX *)ctx_in), iVar2 == 0))
      goto LAB_00099d32;
      pBVar6 = (BIGNUM *)DSA_SIG_new();
      if (pBVar6 == (BIGNUM *)0x0) goto LAB_00099d6c;
      if ((local_54->top != 0) && (r->top != 0)) {
        pBVar6->d = (ulong *)local_54;
        pBVar6->top = (int)r;
        break;
      }
    } while (!bVar1);
  }
  BN_CTX_free((BN_CTX *)ctx_in);
  ctx_in = pBVar6;
LAB_00099cf4:
  BN_clear_free(&BStack_50);
  BN_clear_free(&BStack_3c);
  if (local_58 != (BIGNUM *)0x0) {
    BN_clear_free(local_58);
  }
  return ctx_in;
}

