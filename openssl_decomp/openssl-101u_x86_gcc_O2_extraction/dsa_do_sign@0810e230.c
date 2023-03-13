
DSA_SIG * dsa_do_sign(uchar *param_1,int param_2,DSA *param_3)

{
  BIGNUM *pBVar1;
  bool bVar2;
  BIGNUM *r;
  BN_CTX *ctx_in;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  DSA_SIG *pDVar6;
  int in_GS_OFFSET;
  BIGNUM *local_50;
  BIGNUM *local_4c;
  BIGNUM local_48;
  BIGNUM local_34;
  int local_20;
  
  local_50 = (BIGNUM *)0x0;
  local_4c = (BIGNUM *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_init(&local_48);
  BN_init(&local_34);
  if (((param_3->p == (BIGNUM *)0x0) || (param_3->q == (BIGNUM *)0x0)) ||
     (param_3->g == (BIGNUM *)0x0)) {
    iVar5 = 0x65;
    r = (BIGNUM *)0x0;
  }
  else {
    r = BN_new();
    if ((r != (BIGNUM *)0x0) && (ctx_in = BN_CTX_new(), ctx_in != (BN_CTX *)0x0)) {
      do {
        pBVar3 = param_3->kinv;
        if ((pBVar3 == (BIGNUM *)0x0) || (pBVar1 = param_3->r, pBVar1 == (BIGNUM *)0x0)) {
          iVar5 = DSA_sign_setup(param_3,ctx_in,&local_50,&local_4c);
          if (iVar5 != 0) {
            bVar2 = false;
            goto LAB_0810e3b5;
          }
LAB_0810e410:
          iVar5 = 3;
          goto LAB_0810e415;
        }
        param_3->kinv = (BIGNUM *)0x0;
        param_3->r = (BIGNUM *)0x0;
        bVar2 = true;
        local_50 = pBVar3;
        local_4c = pBVar1;
LAB_0810e3b5:
        iVar4 = BN_num_bits(param_3->q);
        iVar5 = iVar4 + 7;
        if (iVar4 + 7 < 0) {
          iVar5 = iVar4 + 0xe;
        }
        if (iVar5 >> 3 < param_2) {
          iVar5 = BN_num_bits(param_3->q);
          param_2 = iVar5 + 7;
          if (iVar5 + 7 < 0) {
            param_2 = iVar5 + 0xe;
          }
          param_2 = param_2 >> 3;
        }
        pBVar3 = BN_bin2bn(param_1,param_2,&local_48);
        if (((pBVar3 == (BIGNUM *)0x0) ||
            (iVar5 = BN_mod_mul(&local_34,param_3->priv_key,local_4c,param_3->q,ctx_in), iVar5 == 0)
            ) || ((iVar5 = BN_add(r,&local_34,&local_48), iVar5 == 0 ||
                  (((iVar5 = BN_cmp(r,param_3->q), 0 < iVar5 &&
                    (iVar5 = BN_sub(r,r,param_3->q), iVar5 == 0)) ||
                   (iVar5 = BN_mod_mul(r,r,local_50,param_3->q,ctx_in), iVar5 == 0))))))
        goto LAB_0810e410;
        if ((local_4c->top != 0) && (r->top != 0)) {
          pDVar6 = DSA_SIG_new();
          if (pDVar6 == (DSA_SIG *)0x0) goto LAB_0810e410;
          pDVar6->s = r;
          pDVar6->r = local_4c;
          goto LAB_0810e445;
        }
      } while (!bVar2);
      iVar5 = 0x6e;
LAB_0810e415:
      pDVar6 = (DSA_SIG *)0x0;
      ERR_put_error(10,0x70,iVar5,"dsa_ossl.c",0xd1);
      BN_free(local_4c);
      BN_free(r);
LAB_0810e445:
      BN_CTX_free(ctx_in);
      goto LAB_0810e451;
    }
    iVar5 = 3;
  }
  pDVar6 = (DSA_SIG *)0x0;
  ERR_put_error(10,0x70,iVar5,"dsa_ossl.c",0xd1);
  BN_free(local_4c);
  BN_free(r);
LAB_0810e451:
  BN_clear_free(&local_48);
  BN_clear_free(&local_34);
  if (local_50 != (BIGNUM *)0x0) {
    BN_clear_free(local_50);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pDVar6;
}

