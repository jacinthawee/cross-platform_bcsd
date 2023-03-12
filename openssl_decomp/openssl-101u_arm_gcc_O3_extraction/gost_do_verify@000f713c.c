
void gost_do_verify(int param_1,undefined4 param_2,BIGNUM **param_3,int param_4)

{
  BN_CTX *ctx;
  int iVar1;
  uchar *puVar2;
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
  BN_CTX *pBVar3;
  uchar local_50 [32];
  uchar auStack_30 [4];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_GOST_error(0x71,0x41,"gost_sign.c",0xac);
  }
  else {
    BN_CTX_start(ctx);
    iVar1 = BN_cmp(param_3[1],*(BIGNUM **)(param_4 + 0x10));
    if ((iVar1 < 1) && (iVar1 = BN_cmp(*param_3,*(BIGNUM **)(param_4 + 0x10)), iVar1 < 1)) {
      puVar2 = (uchar *)(param_1 + -1);
      s = auStack_30;
      do {
        puVar2 = puVar2 + 1;
        s = s + -1;
        *s = *puVar2;
      } while (s != local_50);
      if (local_50[0] == '\0') {
        s = local_50;
        iVar1 = 0x20;
        do {
          s = s + 1;
          iVar1 = iVar1 + -1;
          if (*s != '\0') {
            if (iVar1 != 0) goto LAB_000f71e8;
            break;
          }
        } while (iVar1 != 0);
        a = BN_new();
        BN_set_word(a,0);
      }
      else {
        iVar1 = 0x20;
LAB_000f71e8:
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
      if ((((r == (BIGNUM *)0x0 || rem == (BIGNUM *)0x0) ||
           (r_00 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0)) ||
          (r_02 == (BIGNUM *)0x0 || r_01 == (BIGNUM *)0x0)) ||
         (rem_00 == (BIGNUM *)0x0 || r_03 == (BIGNUM *)0x0)) {
        pBVar3 = (BN_CTX *)0x0;
        ERR_GOST_error(0x71,0x41,"gost_sign.c",0xc0);
      }
      else {
        BN_div((BIGNUM *)(uint)(rem_00 == (BIGNUM *)0x0 || r_03 == (BIGNUM *)0x0),rem,a,
               *(BIGNUM **)(param_4 + 0x10),ctx);
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
        pBVar3 = (BN_CTX *)0x1;
        BN_div((BIGNUM *)0x0,rem_00,r_03,*(BIGNUM **)(param_4 + 0x10),ctx);
        iVar1 = BN_cmp(rem_00,*param_3);
        if (iVar1 != 0) {
          pBVar3 = (BN_CTX *)0x0;
          ERR_GOST_error(0x71,0x7e,"gost_sign.c",0xd5);
        }
      }
      if (a != (BIGNUM *)0x0) {
        BN_free(a);
      }
    }
    else {
      pBVar3 = (BN_CTX *)0x0;
      ERR_GOST_error(0x71,0x7f,"gost_sign.c",0xb2);
    }
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    ctx = pBVar3;
  }
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(ctx);
  }
  return;
}

