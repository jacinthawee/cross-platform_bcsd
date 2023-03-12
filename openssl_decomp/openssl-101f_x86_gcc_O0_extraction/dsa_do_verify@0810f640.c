
uint dsa_do_verify(uchar *param_1,int param_2,BIGNUM **param_3,int param_4)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  BN_CTX *ctx;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  int iVar6;
  BN_MONT_CTX *m_ctx;
  int in_GS_OFFSET;
  BN_CTX *pBVar7;
  BIGNUM local_5c;
  BIGNUM local_48;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((*(int *)(param_4 + 0xc) == 0) || (*(BIGNUM **)(param_4 + 0x10) == (BIGNUM *)0x0)) ||
     (*(int *)(param_4 + 0x14) == 0)) {
    iVar6 = 0x13c;
    iVar3 = 0x65;
  }
  else {
    uVar2 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
    if (((uVar2 & 0xffffffbf) == 0xa0) || (uVar2 == 0x100)) {
      iVar3 = BN_num_bits(*(BIGNUM **)(param_4 + 0xc));
      if (iVar3 < 0x2711) {
        BN_init(&local_5c);
        BN_init(&local_48);
        BN_init(&local_34);
        ctx = BN_CTX_new();
        if (ctx == (BN_CTX *)0x0) {
LAB_0810f910:
          uVar2 = 0xffffffff;
          ERR_put_error(10,0x71,3,"dsa_ossl.c",0x188);
          if (ctx != (BN_CTX *)0x0) goto LAB_0810f72c;
        }
        else {
          pBVar4 = *param_3;
          if (((pBVar4->top != 0) && (pBVar4->neg == 0)) &&
             ((iVar3 = BN_ucmp(pBVar4,*(BIGNUM **)(param_4 + 0x10)), iVar3 < 0 &&
              (((pBVar4 = param_3[1], pBVar4->top != 0 && (pBVar4->neg == 0)) &&
               (iVar3 = BN_ucmp(pBVar4,*(BIGNUM **)(param_4 + 0x10)), iVar3 < 0)))))) {
            pBVar4 = BN_mod_inverse(&local_48,param_3[1],*(BIGNUM **)(param_4 + 0x10),ctx);
            if (pBVar4 != (BIGNUM *)0x0) {
              iVar3 = (int)uVar2 >> 3;
              if (param_2 < (int)uVar2 >> 3) {
                iVar3 = param_2;
              }
              pBVar4 = &local_5c;
              pBVar7 = ctx;
              pBVar5 = BN_bin2bn(param_1,iVar3,&local_5c);
              if (((pBVar5 != (BIGNUM *)0x0) &&
                  (iVar6 = BN_mod_mul(&local_5c,&local_5c,&local_48,*(BIGNUM **)(param_4 + 0x10),ctx
                                     ), iVar6 != 0)) &&
                 (iVar6 = BN_mod_mul(&local_48,*param_3,&local_48,*(BIGNUM **)(param_4 + 0x10),ctx),
                 iVar6 != 0)) {
                m_ctx = (BN_MONT_CTX *)0x0;
                if ((*(byte *)(param_4 + 0x28) & 1) != 0) {
                  pBVar4 = *(BIGNUM **)(param_4 + 0xc);
                  iVar3 = 8;
                  pBVar7 = ctx;
                  m_ctx = BN_MONT_CTX_set_locked
                                    ((BN_MONT_CTX **)(param_4 + 0x2c),
                                     (int)(BN_MONT_CTX **)(param_4 + 0x2c),(BIGNUM *)&DAT_00000008,
                                     (BN_CTX *)pBVar4);
                  if (m_ctx == (BN_MONT_CTX *)0x0) goto LAB_0810f910;
                }
                pcVar1 = *(code **)(*(int *)(param_4 + 0x3c) + 0x10);
                if (pcVar1 == (code *)0x0) {
                  iVar3 = BN_mod_exp2_mont(&local_34,*(BIGNUM **)(param_4 + 0x14),&local_5c,
                                           *(BIGNUM **)(param_4 + 0x18),&local_48,
                                           *(BIGNUM **)(param_4 + 0xc),ctx,m_ctx);
                }
                else {
                  iVar3 = (*pcVar1)(param_4,&local_34,*(undefined4 *)(param_4 + 0x14),&local_5c,
                                    *(undefined4 *)(param_4 + 0x18),&local_48,
                                    *(undefined4 *)(param_4 + 0xc),ctx,m_ctx,iVar3,pBVar4,pBVar7);
                }
                if ((iVar3 != 0) &&
                   (iVar3 = BN_div((BIGNUM *)0x0,&local_5c,&local_34,*(BIGNUM **)(param_4 + 0x10),
                                   ctx), iVar3 != 0)) {
                  iVar3 = BN_ucmp(&local_5c,*param_3);
                  uVar2 = (uint)(iVar3 == 0);
                  if (iVar3 == 0) {
                    uVar2 = 1;
                  }
                  else {
                    ERR_put_error(10,0x71,3,"dsa_ossl.c",0x188);
                  }
                  goto LAB_0810f72c;
                }
              }
            }
            goto LAB_0810f910;
          }
          uVar2 = 0;
          ERR_put_error(10,0x71,3,"dsa_ossl.c",0x188);
LAB_0810f72c:
          BN_CTX_free(ctx);
        }
        BN_free(&local_5c);
        BN_free(&local_48);
        BN_free(&local_34);
        goto LAB_0810f756;
      }
      iVar6 = 0x14a;
      iVar3 = 0x67;
    }
    else {
      iVar6 = 0x144;
      iVar3 = 0x66;
    }
  }
  ERR_put_error(10,0x71,iVar3,"dsa_ossl.c",iVar6);
  uVar2 = 0xffffffff;
LAB_0810f756:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

