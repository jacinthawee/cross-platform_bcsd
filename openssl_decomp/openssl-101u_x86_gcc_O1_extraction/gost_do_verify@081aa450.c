
bool gost_do_verify(uchar *param_1,undefined4 param_2,BIGNUM **param_3,int param_4)

{
  uchar uVar1;
  BN_CTX *ctx;
  int iVar2;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *r;
  BIGNUM *a_00;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *r_02;
  BIGNUM *r_03;
  BIGNUM *rem_00;
  uchar *puVar3;
  uchar *puVar4;
  int in_GS_OFFSET;
  bool bVar5;
  uchar local_41;
  uchar local_40 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    bVar5 = false;
    ERR_GOST_error(0x71,0x41,"gost_sign.c",0xac);
  }
  else {
    BN_CTX_start(ctx);
    iVar2 = BN_cmp(param_3[1],*(BIGNUM **)(param_4 + 0x10));
    if ((iVar2 < 1) && (iVar2 = BN_cmp(*param_3,*(BIGNUM **)(param_4 + 0x10)), iVar2 < 1)) {
      puVar4 = local_40 + 0x1f;
      do {
        uVar1 = *param_1;
        puVar3 = puVar4 + -1;
        param_1 = param_1 + 1;
        *puVar4 = uVar1;
        puVar4 = puVar3;
      } while (puVar3 != &local_41);
      iVar2 = 0x20;
      puVar4 = local_40;
      if (local_40[0] == '\0') {
        do {
          puVar4 = puVar4 + 1;
          iVar2 = iVar2 + -1;
          if (*puVar4 != '\0') {
            if (iVar2 != 0) goto LAB_081aa553;
            break;
          }
        } while (iVar2 != 0);
        a = BN_new();
        BN_set_word(a,0);
      }
      else {
LAB_081aa553:
        a = BN_bin2bn(puVar4,iVar2,(BIGNUM *)0x0);
      }
      rem = BN_CTX_get(ctx);
      r = BN_CTX_get(ctx);
      a_00 = BN_CTX_get(ctx);
      r_00 = BN_CTX_get(ctx);
      r_01 = BN_CTX_get(ctx);
      r_02 = BN_CTX_get(ctx);
      r_03 = BN_CTX_get(ctx);
      rem_00 = BN_CTX_get(ctx);
      if (((((rem == (BIGNUM *)0x0) || (r == (BIGNUM *)0x0)) || (a_00 == (BIGNUM *)0x0)) ||
          ((r_00 == (BIGNUM *)0x0 || (r_01 == (BIGNUM *)0x0)))) ||
         ((r_02 == (BIGNUM *)0x0 || ((r_03 == (BIGNUM *)0x0 || (rem_00 == (BIGNUM *)0x0)))))) {
        bVar5 = false;
        ERR_GOST_error(0x71,0x41,"gost_sign.c",0xc0);
      }
      else {
        BN_div((BIGNUM *)0x0,rem,a,*(BIGNUM **)(param_4 + 0x10),ctx);
        if (rem->top == 0) {
          BN_set_word(a,1);
        }
        BN_copy(a_00,*(BIGNUM **)(param_4 + 0x10));
        BN_sub_word(a_00,2);
        BN_mod_exp(r,a,a_00,*(BIGNUM **)(param_4 + 0x10),ctx);
        BN_mod_mul(r_00,param_3[1],r,*(BIGNUM **)(param_4 + 0x10),ctx);
        BN_sub(rem,*(BIGNUM **)(param_4 + 0x10),*param_3);
        BN_mod_mul(r_01,rem,r,*(BIGNUM **)(param_4 + 0xc),ctx);
        BN_mod_exp(rem,*(BIGNUM **)(param_4 + 0x14),r_00,*(BIGNUM **)(param_4 + 0xc),ctx);
        BN_mod_exp(r_02,*(BIGNUM **)(param_4 + 0x18),r_01,*(BIGNUM **)(param_4 + 0xc),ctx);
        BN_mod_mul(r_03,rem,r_02,*(BIGNUM **)(param_4 + 0xc),ctx);
        BN_div((BIGNUM *)0x0,rem_00,r_03,*(BIGNUM **)(param_4 + 0x10),ctx);
        iVar2 = BN_cmp(rem_00,*param_3);
        bVar5 = iVar2 == 0;
        if (!bVar5) {
          ERR_GOST_error(0x71,0x7e,"gost_sign.c",0xd5);
        }
      }
      if (a != (BIGNUM *)0x0) {
        BN_free(a);
      }
    }
    else {
      bVar5 = false;
      ERR_GOST_error(0x71,0x7f,"gost_sign.c",0xb2);
    }
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar5;
}

