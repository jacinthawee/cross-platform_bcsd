
DSA_SIG * dsa_do_sign(uchar *param_1,int param_2,DSA *param_3)

{
  BIGNUM *pBVar1;
  bool bVar2;
  BIGNUM *a;
  BN_CTX *ctx_in;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  DSA_SIG *local_64;
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
    iVar4 = 0x65;
    a = (BIGNUM *)0x0;
  }
  else {
    a = BN_new();
    if (a != (BIGNUM *)0x0) {
      ctx_in = BN_CTX_new();
      if (ctx_in != (BN_CTX *)0x0) {
        local_64 = (DSA_SIG *)0x0;
        do {
          pBVar3 = param_3->kinv;
          if ((pBVar3 == (BIGNUM *)0x0) || (pBVar1 = param_3->r, pBVar1 == (BIGNUM *)0x0)) {
            iVar4 = DSA_sign_setup(param_3,ctx_in,&local_50,&local_4c);
            if (iVar4 != 0) {
              bVar2 = false;
              goto LAB_0810fb9a;
            }
LAB_0810fc48:
            if (local_64 == (DSA_SIG *)0x0) {
LAB_0810fc50:
              ERR_put_error(10,0x70,3,"dsa_ossl.c",0xcc);
              BN_free(local_4c);
              BN_free(a);
            }
            break;
          }
          param_3->kinv = (BIGNUM *)0x0;
          param_3->r = (BIGNUM *)0x0;
          bVar2 = true;
          local_50 = pBVar3;
          local_4c = pBVar1;
LAB_0810fb9a:
          iVar5 = BN_num_bits(param_3->q);
          iVar4 = iVar5 + 7;
          if (iVar5 + 7 < 0) {
            iVar4 = iVar5 + 0xe;
          }
          if (iVar4 >> 3 < param_2) {
            iVar4 = BN_num_bits(param_3->q);
            param_2 = iVar4 + 7;
            if (iVar4 + 7 < 0) {
              param_2 = iVar4 + 0xe;
            }
            param_2 = param_2 >> 3;
          }
          pBVar3 = BN_bin2bn(param_1,param_2,&local_48);
          if (pBVar3 == (BIGNUM *)0x0) goto LAB_0810fc48;
          iVar4 = BN_mod_mul(&local_34,param_3->priv_key,local_4c,param_3->q,ctx_in);
          if (iVar4 == 0) goto LAB_0810fc48;
          iVar4 = BN_add(a,&local_34,&local_48);
          if (iVar4 == 0) goto LAB_0810fc48;
          iVar4 = BN_cmp(a,param_3->q);
          if (0 < iVar4) {
            iVar4 = BN_sub(a,a,param_3->q);
            if (iVar4 == 0) goto LAB_0810fc48;
          }
          iVar4 = BN_mod_mul(a,a,local_50,param_3->q,ctx_in);
          if (iVar4 == 0) goto LAB_0810fc48;
          local_64 = DSA_SIG_new();
          if (local_64 == (DSA_SIG *)0x0) goto LAB_0810fc50;
          if ((local_4c->top != 0) && (a->top != 0)) {
            local_64->r = local_4c;
            local_64->s = a;
            break;
          }
        } while (!bVar2);
        BN_CTX_free(ctx_in);
        goto LAB_0810fbfc;
      }
    }
    iVar4 = 3;
  }
  ERR_put_error(10,0x70,iVar4,"dsa_ossl.c",0xcc);
  BN_free(local_4c);
  BN_free(a);
  local_64 = (DSA_SIG *)0x0;
LAB_0810fbfc:
  BN_clear_free(&local_48);
  BN_clear_free(&local_34);
  if (local_50 != (BIGNUM *)0x0) {
    BN_clear_free(local_50);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_64;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

