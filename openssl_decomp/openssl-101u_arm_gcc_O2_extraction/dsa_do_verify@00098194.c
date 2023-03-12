
undefined4 dsa_do_verify(uchar *param_1,int param_2,BIGNUM **param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  BN_CTX *ctx;
  BIGNUM *pBVar3;
  BN_MONT_CTX *m_ctx;
  undefined4 uVar4;
  code *pcVar5;
  BIGNUM BStack_5c;
  BIGNUM BStack_48;
  BIGNUM BStack_34;
  
  if (((*(int *)(param_4 + 0xc) == 0) || (*(BIGNUM **)(param_4 + 0x10) == (BIGNUM *)0x0)) ||
     (*(int *)(param_4 + 0x14) == 0)) {
    ERR_put_error(10,0x71,0x65,"dsa_ossl.c",0x148);
    return 0xffffffff;
  }
  uVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if (((uVar1 & 0xffffffbf) != 0xa0) && (uVar1 != 0x100)) {
    ERR_put_error(10,0x71,0x66,"dsa_ossl.c",0x14f);
    return 0xffffffff;
  }
  iVar2 = BN_num_bits(*(BIGNUM **)(param_4 + 0xc));
  if (10000 < iVar2) {
    ERR_put_error(10,0x71,0x67,"dsa_ossl.c",0x154);
    return 0xffffffff;
  }
  BN_init(&BStack_5c);
  BN_init(&BStack_48);
  BN_init(&BStack_34);
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) goto LAB_00098316;
  pBVar3 = *param_3;
  if (((pBVar3->top == 0) || (pBVar3->neg != 0)) ||
     ((iVar2 = BN_ucmp(pBVar3,*(BIGNUM **)(param_4 + 0x10)), -1 < iVar2 ||
      (((pBVar3 = param_3[1], pBVar3->top == 0 || (pBVar3->neg != 0)) ||
       (iVar2 = BN_ucmp(pBVar3,*(BIGNUM **)(param_4 + 0x10)), -1 < iVar2)))))) {
    uVar4 = 0;
LAB_00098206:
    ERR_put_error(10,0x71,3,"dsa_ossl.c",0x19b);
    if (ctx == (BN_CTX *)0x0) goto LAB_00098226;
  }
  else {
    pBVar3 = BN_mod_inverse(&BStack_48,param_3[1],*(BIGNUM **)(param_4 + 0x10),ctx);
    if (pBVar3 == (BIGNUM *)0x0) {
LAB_00098316:
      uVar4 = 0xffffffff;
      goto LAB_00098206;
    }
    iVar2 = (int)uVar1 >> 3;
    if (param_2 <= (int)uVar1 >> 3) {
      iVar2 = param_2;
    }
    pBVar3 = BN_bin2bn(param_1,iVar2,&BStack_5c);
    if (((pBVar3 == (BIGNUM *)0x0) ||
        (iVar2 = BN_mod_mul(&BStack_5c,&BStack_5c,&BStack_48,*(BIGNUM **)(param_4 + 0x10),ctx),
        iVar2 == 0)) ||
       ((iVar2 = BN_mod_mul(&BStack_48,*param_3,&BStack_48,*(BIGNUM **)(param_4 + 0x10),ctx),
        iVar2 == 0 ||
        ((m_ctx = (BN_MONT_CTX *)(*(uint *)(param_4 + 0x28) & 1), m_ctx != (BN_MONT_CTX *)0x0 &&
         (m_ctx = BN_MONT_CTX_set_locked
                            ((BN_MONT_CTX **)(param_4 + 0x2c),8,*(BIGNUM **)(param_4 + 0xc),ctx),
         m_ctx == (BN_MONT_CTX *)0x0)))))) goto LAB_00098316;
    pcVar5 = *(code **)(*(int *)(param_4 + 0x3c) + 0x10);
    if (pcVar5 == (code *)0x0) {
      iVar2 = BN_mod_exp2_mont(&BStack_34,*(BIGNUM **)(param_4 + 0x14),&BStack_5c,
                               *(BIGNUM **)(param_4 + 0x18),&BStack_48,*(BIGNUM **)(param_4 + 0xc),
                               ctx,m_ctx);
    }
    else {
      iVar2 = (*pcVar5)(param_4,&BStack_34,*(undefined4 *)(param_4 + 0x14),&BStack_5c,
                        *(undefined4 *)(param_4 + 0x18),&BStack_48,*(undefined4 *)(param_4 + 0xc),
                        ctx,m_ctx);
    }
    if ((iVar2 == 0) ||
       (iVar2 = BN_div((BIGNUM *)0x0,&BStack_5c,&BStack_34,*(BIGNUM **)(param_4 + 0x10),ctx),
       iVar2 == 0)) goto LAB_00098316;
    iVar2 = BN_ucmp(&BStack_5c,*param_3);
    if (iVar2 == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
      ERR_put_error(10,0x71,3,"dsa_ossl.c",0x19b);
    }
  }
  BN_CTX_free(ctx);
LAB_00098226:
  BN_free(&BStack_5c);
  BN_free(&BStack_48);
  BN_free(&BStack_34);
  return uVar4;
}

