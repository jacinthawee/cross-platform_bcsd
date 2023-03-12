
void gost_do_verify(int param_1,undefined4 param_2,BIGNUM **param_3,int param_4)

{
  BN_CTX *ctx;
  int iVar1;
  uint uVar2;
  uchar *puVar3;
  uchar *s;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *r;
  BIGNUM *a_00;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *r_02;
  BIGNUM *r_03;
  BIGNUM *rem_00;
  uchar local_50 [32];
  uchar auStack_30 [4];
  int local_2c;
  
  local_2c = __TMC_END__;
  ctx = BN_CTX_new();
  BN_CTX_start(ctx);
  iVar1 = BN_cmp(param_3[1],*(BIGNUM **)(param_4 + 0x10));
  if ((iVar1 < 1) && (iVar1 = BN_cmp(*param_3,*(BIGNUM **)(param_4 + 0x10)), iVar1 < 1)) {
    puVar3 = (uchar *)(param_1 + -1);
    s = auStack_30;
    do {
      puVar3 = puVar3 + 1;
      s = s + -1;
      *s = *puVar3;
    } while (s != local_50);
    if (local_50[0] == '\0') {
      s = local_50;
      iVar1 = 0x20;
      do {
        s = s + 1;
        iVar1 = iVar1 + -1;
        if (*s != '\0') {
          if (iVar1 != 0) goto LAB_000f8fe2;
          break;
        }
      } while (iVar1 != 0);
      a = BN_new();
      BN_set_word(a,0);
    }
    else {
      iVar1 = 0x20;
LAB_000f8fe2:
      a = BN_bin2bn(s,iVar1,(BIGNUM *)0x0);
    }
    rem = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    a_00 = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    r_01 = BN_CTX_get(ctx);
    r_02 = BN_CTX_get(ctx);
    r_03 = BN_CTX_get(ctx);
    rem_00 = BN_CTX_get(ctx);
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
    iVar1 = BN_cmp(rem_00,*param_3);
    BN_free(a);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (iVar1 != 0) {
      ERR_GOST_error(0x71,0x7e,"gost_sign.c",0xb9);
    }
    uVar2 = count_leading_zeroes(iVar1);
    uVar2 = uVar2 >> 5;
  }
  else {
    ERR_GOST_error(0x71,0x7f,"gost_sign.c",0x95);
    uVar2 = 0;
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}

