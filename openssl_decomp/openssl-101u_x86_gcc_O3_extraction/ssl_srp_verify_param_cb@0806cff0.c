
undefined4 ssl_srp_verify_param_cb(undefined4 param_1,int param_2)

{
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *r_00;
  bool bVar2;
  
  a = (BIGNUM *)SSL_get_srp_N(param_1);
  if (a == (BIGNUM *)0x0) {
    return 0;
  }
  a_00 = (BIGNUM *)SSL_get_srp_g(param_1);
  if (a_00 == (BIGNUM *)0x0) {
    return 0;
  }
  if (((*(int *)(param_2 + 0xc) != 0) || (*(int *)(param_2 + 8) != 0)) ||
     (*(int *)(param_2 + 0x10) == 1)) {
    BIO_printf(bio_err,"SRP parameters:\n");
    BIO_printf(bio_err,"\tN=");
    BN_print(bio_err,a);
    BIO_printf(bio_err,"\n\tg=");
    BN_print(bio_err,a_00);
    BIO_printf(bio_err,"\n");
  }
  iVar1 = SRP_check_known_gN_param(a_00,a);
  if (iVar1 != 0) {
    return 1;
  }
  if (*(int *)(param_2 + 0x10) != 1) goto LAB_0806d0ee;
  if (*(int *)(param_2 + 0xc) != 0) {
    BIO_printf(bio_err,"SRP param N and g are not known params, going to check deeper.\n");
  }
  iVar1 = BN_num_bits(a_00);
  if (0x40 < iVar1) goto LAB_0806d0ee;
  ctx = BN_CTX_new();
  r = BN_new();
  r_00 = BN_new();
  if (((((ctx == (BN_CTX *)0x0) || (a->top < 1)) ||
       (((*(byte *)a->d & 1) == 0 ||
        ((iVar1 = BN_is_prime_ex(a,0x40,ctx,(BN_GENCB *)0x0), iVar1 == 0 || (r == (BIGNUM *)0x0)))))
       ) || (iVar1 = BN_rshift1(r,a), iVar1 == 0)) ||
     (iVar1 = BN_is_prime_ex(r,0x40,ctx,(BN_GENCB *)0x0), iVar1 == 0)) {
    bVar2 = false;
    if (r_00 != (BIGNUM *)0x0) goto LAB_0806d15d;
LAB_0806d169:
    if (r != (BIGNUM *)0x0) goto LAB_0806d16d;
  }
  else {
    if (r_00 != (BIGNUM *)0x0) {
      iVar1 = BN_mod_exp(r_00,a_00,r,a,ctx);
      if ((iVar1 == 0) || (iVar1 = BN_add_word(r_00,1), iVar1 == 0)) {
        bVar2 = false;
      }
      else {
        iVar1 = BN_cmp(r_00,a);
        bVar2 = iVar1 == 0;
      }
LAB_0806d15d:
      BN_free(r_00);
      goto LAB_0806d169;
    }
    bVar2 = false;
LAB_0806d16d:
    BN_free(r);
  }
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  if (bVar2) {
    return 1;
  }
LAB_0806d0ee:
  BIO_printf(bio_err,"SRP param N and g rejected.\n");
  return 0;
}

