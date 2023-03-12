
int DH_generate_parameters_ex(DH *dh,int prime_len,int generator,BN_GENCB *cb)

{
  int iVar1;
  BIGNUM *add;
  BIGNUM *rem;
  int iVar2;
  BIGNUM *pBVar3;
  _func_1706 *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = dh->meth->generate_params;
  if (UNRECOVERED_JUMPTABLE != (_func_1706 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005153f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(dh,prime_len,generator,cb);
    return iVar1;
  }
  iVar1 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar1 == 0) {
    ERR_put_error(5,0x6a,3,"dh_gen.c",0xc3);
    return 0;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(iVar1);
  add = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
  rem = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
  if ((add != (BIGNUM *)0x0) && (rem != (BIGNUM *)0x0)) {
    if (dh->p == (BIGNUM *)0x0) {
      pBVar3 = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
      dh->p = pBVar3;
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_005154d8;
    }
    if (dh->g == (BIGNUM *)0x0) {
      pBVar3 = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
      dh->g = pBVar3;
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_005154d8;
    }
    if (generator < 2) {
      ERR_put_error(5,0x6a,0x65,"dh_gen.c",0x91);
      iVar2 = 0;
      ERR_put_error(5,0x6a,3,"dh_gen.c",0xc3);
      goto LAB_00515500;
    }
    if (generator == 2) {
      iVar2 = (*(code *)PTR_BN_set_word_006a7730)(add,0x18);
      if ((iVar2 != 0) && (iVar2 = (*(code *)PTR_BN_set_word_006a7730)(rem,0xb), iVar2 != 0)) {
        pBVar3 = dh->p;
        goto LAB_005155b4;
      }
    }
    else if (generator == 5) {
      iVar2 = (*(code *)PTR_BN_set_word_006a7730)(add,10);
      if ((iVar2 != 0) && (iVar2 = (*(code *)PTR_BN_set_word_006a7730)(rem,3), iVar2 != 0)) {
        pBVar3 = dh->p;
        goto LAB_005155b4;
      }
    }
    else {
      iVar2 = (*(code *)PTR_BN_set_word_006a7730)(add,2);
      if ((iVar2 != 0) && (iVar2 = (*(code *)PTR_BN_set_word_006a7730)(rem,1), iVar2 != 0)) {
        pBVar3 = dh->p;
LAB_005155b4:
        iVar2 = BN_generate_prime_ex(pBVar3,prime_len,1,add,rem,cb);
        if (((iVar2 != 0) && (iVar2 = BN_GENCB_call(cb,3,0), iVar2 != 0)) &&
           (iVar2 = (*(code *)PTR_BN_set_word_006a7730)(dh->g,generator), iVar2 != 0)) {
          iVar2 = 1;
          goto LAB_00515500;
        }
      }
    }
  }
LAB_005154d8:
  iVar2 = 0;
  ERR_put_error(5,0x6a,3,"dh_gen.c",0xc3);
LAB_00515500:
  (*(code *)PTR_BN_CTX_end_006a8530)(iVar1);
  (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
  return iVar2;
}

