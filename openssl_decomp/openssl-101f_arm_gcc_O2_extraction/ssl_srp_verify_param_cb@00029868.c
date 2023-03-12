
undefined4 ssl_srp_verify_param_cb(undefined4 param_1,int param_2)

{
  BIGNUM *pBVar1;
  BIGNUM *a;
  int iVar2;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *r_00;
  uint uVar3;
  
  pBVar1 = (BIGNUM *)SSL_get_srp_N();
  if (pBVar1 == (BIGNUM *)0x0) {
    return 0;
  }
  a = (BIGNUM *)SSL_get_srp_g(param_1);
  if (a == (BIGNUM *)0x0) {
    return 0;
  }
  if (((*(int *)(param_2 + 0xc) != 0) || (*(int *)(param_2 + 8) != 0)) ||
     (*(int *)(param_2 + 0x10) == 1)) {
    BIO_printf(bio_err,"SRP parameters:\n");
    BIO_printf(bio_err,"\tN=");
    BN_print(bio_err,pBVar1);
    BIO_printf(bio_err,"\n\tg=");
    BN_print(bio_err,a);
    BIO_printf(bio_err,"\n");
  }
  iVar2 = SRP_check_known_gN_param(a,pBVar1);
  if (iVar2 != 0) {
    return 1;
  }
  if (*(int *)(param_2 + 0x10) != 1) goto LAB_0002990c;
  if (*(int *)(param_2 + 0xc) != 0) {
    BIO_printf(bio_err,"SRP param N and g are not known params, going to check deeper.\n");
  }
  iVar2 = BN_num_bits(a);
  if (0x40 < iVar2) goto LAB_0002990c;
  ctx = BN_CTX_new();
  r = BN_new();
  r_00 = BN_new();
  if (((((ctx == (BN_CTX *)0x0) || (pBVar1->top < 1)) ||
       ((-1 < (int)(*pBVar1->d << 0x1f) ||
        ((iVar2 = BN_is_prime_ex(pBVar1,0x40,ctx,(BN_GENCB *)0x0), iVar2 == 0 ||
         (r == (BIGNUM *)0x0)))))) || (iVar2 = BN_rshift1(r,pBVar1), iVar2 == 0)) ||
     (iVar2 = BN_is_prime_ex(r,0x40,ctx,(BN_GENCB *)0x0), iVar2 == 0)) {
    if (r_00 != (BIGNUM *)0x0) {
LAB_0002996c:
      pBVar1 = (BIGNUM *)0x0;
      goto LAB_0002996e;
    }
LAB_00029974:
    if (r != (BIGNUM *)0x0) goto LAB_00029976;
  }
  else {
    if (r_00 != (BIGNUM *)0x0) {
      iVar2 = BN_mod_exp(r_00,a,r,pBVar1,ctx);
      if ((iVar2 == 0) || (iVar2 = BN_add_word(r_00,1), iVar2 == 0)) goto LAB_0002996c;
      iVar2 = BN_cmp(r_00,pBVar1);
      uVar3 = count_leading_zeroes(iVar2);
      pBVar1 = (BIGNUM *)(uVar3 >> 5);
LAB_0002996e:
      BN_free(r_00);
      r_00 = pBVar1;
      goto LAB_00029974;
    }
LAB_00029976:
    BN_free(r);
  }
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  if (r_00 != (BIGNUM *)0x0) {
    return 1;
  }
LAB_0002990c:
  BIO_printf(bio_err,"SRP param N and g rejected.\n");
  return 0;
}

