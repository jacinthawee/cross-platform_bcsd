
int DH_generate_parameters_ex(DH *dh,int prime_len,int generator,BN_GENCB *cb)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  _func_1706 *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = dh->meth->generate_params;
  if (UNRECOVERED_JUMPTABLE != (_func_1706 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00098aea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(dh,prime_len,generator,cb);
    return iVar1;
  }
  ctx = BN_CTX_new();
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_start(ctx);
    a = BN_CTX_get(ctx);
    a_00 = BN_CTX_get(ctx);
    if (a != (BIGNUM *)0x0 && a_00 != (BIGNUM *)0x0) {
      if (dh->p == (BIGNUM *)0x0) {
        pBVar2 = BN_new();
        dh->p = pBVar2;
        if (pBVar2 == (BIGNUM *)0x0) goto LAB_00098b9a;
      }
      if (dh->g == (BIGNUM *)0x0) {
        pBVar2 = BN_new();
        dh->g = pBVar2;
        if (pBVar2 == (BIGNUM *)0x0) goto LAB_00098b9a;
      }
      if (generator < 2) {
        iVar1 = 0;
        ERR_put_error(5,0x6a,0x65,"dh_gen.c",0x91);
        ERR_put_error(5,0x6a,3,"dh_gen.c",0xc3);
        goto LAB_00098b72;
      }
      if (generator == 2) {
        iVar1 = BN_set_word(a,0x18);
        if (iVar1 != 0) {
          iVar1 = BN_set_word(a_00,0xb);
          goto joined_r0x00098bce;
        }
      }
      else if (generator == 5) {
        iVar1 = BN_set_word(a,10);
        if (iVar1 != 0) {
          iVar1 = BN_set_word(a_00,3);
          goto joined_r0x00098bce;
        }
      }
      else {
        iVar1 = BN_set_word(a,2);
        if (iVar1 != 0) {
          iVar1 = BN_set_word(a_00,1);
joined_r0x00098bce:
          if ((((iVar1 != 0) &&
               (iVar1 = BN_generate_prime_ex(dh->p,prime_len,1,a,a_00,cb), iVar1 != 0)) &&
              (iVar1 = BN_GENCB_call(cb,3,0), iVar1 != 0)) &&
             (iVar1 = BN_set_word(dh->g,generator), iVar1 != 0)) {
            iVar1 = 1;
            goto LAB_00098b72;
          }
        }
      }
    }
  }
LAB_00098b9a:
  iVar1 = 0;
  ERR_put_error(5,0x6a,3,"dh_gen.c",0xc3);
  if (ctx == (BN_CTX *)0x0) {
    return 0;
  }
LAB_00098b72:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar1;
}

