
bool gost_do_verify(uchar *param_1,undefined4 param_2,BIGNUM **param_3,int param_4)

{
  uchar uVar1;
  BN_CTX *ctx;
  int iVar2;
  uchar *puVar3;
  BIGNUM *rem;
  BIGNUM *r;
  BIGNUM *a;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *r_02;
  BIGNUM *r_03;
  BIGNUM *rem_00;
  uchar *puVar4;
  int in_GS_OFFSET;
  bool bVar5;
  BIGNUM *local_6c;
  uchar local_41;
  uchar local_40 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = BN_CTX_new();
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
          if (iVar2 != 0) goto LAB_081aba13;
          break;
        }
      } while (iVar2 != 0);
      local_6c = BN_new();
      BN_set_word(local_6c,0);
    }
    else {
LAB_081aba13:
      local_6c = BN_bin2bn(puVar4,iVar2,(BIGNUM *)0x0);
    }
    rem = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    a = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    r_01 = BN_CTX_get(ctx);
    r_02 = BN_CTX_get(ctx);
    r_03 = BN_CTX_get(ctx);
    rem_00 = BN_CTX_get(ctx);
    BN_div((BIGNUM *)0x0,rem,local_6c,*(BIGNUM **)(param_4 + 0x10),ctx);
    if (rem->top == 0) {
      BN_set_word(local_6c,1);
    }
    BN_copy(a,*(BIGNUM **)(param_4 + 0x10));
    BN_sub_word(a,2);
    BN_mod_exp(r,local_6c,a,*(BIGNUM **)(param_4 + 0x10),ctx);
    BN_mod_mul(r_00,param_3[1],r,*(BIGNUM **)(param_4 + 0x10),ctx);
    BN_sub(rem,*(BIGNUM **)(param_4 + 0x10),*param_3);
    BN_mod_mul(r_01,rem,r,*(BIGNUM **)(param_4 + 0xc),ctx);
    BN_mod_exp(rem,*(BIGNUM **)(param_4 + 0x14),r_00,*(BIGNUM **)(param_4 + 0xc),ctx);
    BN_mod_exp(r_02,*(BIGNUM **)(param_4 + 0x18),r_01,*(BIGNUM **)(param_4 + 0xc),ctx);
    BN_mod_mul(r_03,rem,r_02,*(BIGNUM **)(param_4 + 0xc),ctx);
    BN_div((BIGNUM *)0x0,rem_00,r_03,*(BIGNUM **)(param_4 + 0x10),ctx);
    iVar2 = BN_cmp(rem_00,*param_3);
    BN_free(local_6c);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (iVar2 != 0) {
      ERR_GOST_error(0x71,0x7e,"gost_sign.c",0xb9);
    }
    bVar5 = iVar2 == 0;
  }
  else {
    ERR_GOST_error(0x71,0x7f,"gost_sign.c",0x95);
    bVar5 = false;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar5;
}

