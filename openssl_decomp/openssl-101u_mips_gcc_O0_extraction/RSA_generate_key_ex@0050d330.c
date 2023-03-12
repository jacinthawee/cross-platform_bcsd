
int RSA_generate_key_ex(RSA *rsa,int bits,BIGNUM *e,BN_GENCB *cb)

{
  int *piVar1;
  undefined *puVar2;
  RSA *pRVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  BIGNUM *pBVar8;
  undefined4 uVar9;
  BIGNUM *pBVar10;
  int b;
  BIGNUM *unaff_s3;
  BIGNUM *unaff_s4;
  BN_CTX *unaff_s6;
  _func_1628 *p_Var11;
  BIGNUM *local_6c;
  BIGNUM local_68;
  BIGNUM local_54;
  BIGNUM local_40;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  p_Var11 = rsa->meth->rsa_keygen;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (p_Var11 == (_func_1628 *)0x0) {
    unaff_s6 = BN_CTX_new();
    if (unaff_s6 != (BN_CTX *)0x0) {
      BN_CTX_start(unaff_s6);
      local_6c = BN_CTX_get(unaff_s6);
      unaff_s3 = BN_CTX_get(unaff_s6);
      unaff_s4 = BN_CTX_get(unaff_s6);
      pBVar8 = BN_CTX_get(unaff_s6);
      if (pBVar8 == (BIGNUM *)0x0) goto LAB_0050d66c;
      iVar7 = (bits + 1) / 2;
      if (rsa->n == (BIGNUM *)0x0) {
        pBVar8 = BN_new();
        rsa->n = pBVar8;
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_0050d66c;
      }
      if (rsa->d == (BIGNUM *)0x0) {
        pBVar8 = BN_new();
        rsa->d = pBVar8;
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_0050d66c;
      }
      if (rsa->e == (BIGNUM *)0x0) {
        pBVar8 = BN_new();
        rsa->e = pBVar8;
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_0050d66c;
      }
      if (rsa->p == (BIGNUM *)0x0) {
        pBVar8 = BN_new();
        rsa->p = pBVar8;
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_0050d66c;
      }
      if (rsa->q == (BIGNUM *)0x0) {
        pBVar8 = BN_new();
        rsa->q = pBVar8;
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_0050d66c;
      }
      if (rsa->dmp1 == (BIGNUM *)0x0) {
        pBVar8 = BN_new();
        rsa->dmp1 = pBVar8;
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_0050d66c;
      }
      if (rsa->dmq1 == (BIGNUM *)0x0) {
        pBVar8 = BN_new();
        rsa->dmq1 = pBVar8;
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_0050d66c;
      }
      if (rsa->iqmp == (BIGNUM *)0x0) {
        pBVar8 = BN_new();
        rsa->iqmp = pBVar8;
        if (pBVar8 == (BIGNUM *)0x0) goto LAB_0050d66c;
      }
      b = 0;
      BN_copy(rsa->e,e);
      while( true ) {
        iVar4 = BN_generate_prime_ex(rsa->p,iVar7,0,(BIGNUM *)0x0,(BIGNUM *)0x0,cb);
        if (iVar4 == 0) goto LAB_0050d66c;
        pBVar10 = rsa->p;
        pBVar8 = BN_value_one();
        iVar4 = (*(code *)PTR_BN_sub_006a85a8)(unaff_s4,pBVar10,pBVar8);
        if (iVar4 == 0) goto LAB_0050d66c;
        iVar4 = (*(code *)PTR_BN_gcd_006a871c)(unaff_s3,unaff_s4,rsa->e,unaff_s6);
        if (iVar4 == 0) goto LAB_0050d66c;
        if (((unaff_s3->top == 1) && (*unaff_s3->d == 1)) && (unaff_s3->neg == 0)) break;
        iVar4 = BN_GENCB_call(cb,2,b);
        b = b + 1;
        if (iVar4 == 0) goto LAB_0050d66c;
      }
      iVar4 = BN_GENCB_call(cb,3,0);
      if (iVar4 == 0) goto LAB_0050d66c;
      while( true ) {
        iVar4 = 3;
        while( true ) {
          iVar5 = BN_generate_prime_ex(rsa->q,bits - iVar7,0,(BIGNUM *)0x0,(BIGNUM *)0x0,cb);
          if (iVar5 == 0) goto LAB_0050d66c;
          iVar5 = BN_cmp(rsa->p,rsa->q);
          if (iVar5 != 0) break;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) {
            uVar9 = 0x78;
            uVar6 = 0xaf;
            goto LAB_0050d67c;
          }
        }
        pBVar10 = rsa->q;
        pBVar8 = BN_value_one();
        iVar4 = (*(code *)PTR_BN_sub_006a85a8)(unaff_s4,pBVar10,pBVar8);
        if (iVar4 == 0) goto LAB_0050d66c;
        iVar4 = (*(code *)PTR_BN_gcd_006a871c)(unaff_s3,unaff_s4,rsa->e,unaff_s6);
        if (iVar4 == 0) goto LAB_0050d66c;
        if (((unaff_s3->top == 1) && (*unaff_s3->d == 1)) && (unaff_s3->neg == 0)) break;
        iVar4 = BN_GENCB_call(cb,2,b);
        b = b + 1;
        if (iVar4 == 0) goto LAB_0050d66c;
      }
      iVar7 = BN_GENCB_call(cb,3,1);
      if (iVar7 == 0) goto LAB_0050d66c;
      iVar7 = BN_cmp(rsa->p,rsa->q);
      if (iVar7 < 0) goto LAB_0050da80;
      pBVar10 = rsa->p;
      pBVar8 = rsa->q;
      goto LAB_0050d858;
    }
    rsa = (RSA *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x81,3,"rsa_gen.c",0xf1);
    pRVar3 = (RSA *)0x0;
  }
  else {
    pRVar3 = (RSA *)(*p_Var11)(rsa,bits,e,cb);
  }
  do {
    if (local_2c == *(int *)puVar2) {
      return (int)pRVar3;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0050da80:
    pBVar10 = rsa->q;
    pBVar8 = rsa->p;
    rsa->p = pBVar10;
    rsa->q = pBVar8;
LAB_0050d858:
    iVar7 = BN_mul(rsa->n,pBVar10,pBVar8,unaff_s6);
    if (iVar7 == 0) {
LAB_0050d66c:
      uVar9 = 3;
      uVar6 = 0xf1;
LAB_0050d67c:
      pRVar3 = (RSA *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x81,uVar9,"rsa_gen.c",uVar6);
    }
    else {
      pBVar10 = rsa->p;
      pBVar8 = BN_value_one();
      iVar7 = (*(code *)PTR_BN_sub_006a85a8)(unaff_s3,pBVar10,pBVar8);
      if (iVar7 == 0) goto LAB_0050d66c;
      pBVar10 = rsa->q;
      pBVar8 = BN_value_one();
      iVar7 = (*(code *)PTR_BN_sub_006a85a8)(unaff_s4,pBVar10,pBVar8);
      if ((iVar7 == 0) || (iVar7 = BN_mul(local_6c,unaff_s3,unaff_s4,unaff_s6), iVar7 == 0))
      goto LAB_0050d66c;
      if ((rsa->flags & 0x100U) == 0) {
        piVar1 = &local_6c->flags;
        local_68.d = local_6c->d;
        local_68.top = local_6c->top;
        local_68.dmax = local_6c->dmax;
        local_68.neg = local_6c->neg;
        local_6c = &local_68;
        local_68.flags = local_68.flags & 1U | *piVar1 & 0xfffffffeU | 6;
      }
      iVar7 = (*(code *)PTR_BN_mod_inverse_006a85f0)(rsa->d,rsa->e,local_6c,unaff_s6);
      if (iVar7 == 0) goto LAB_0050d66c;
      if ((rsa->flags & 0x100U) == 0) {
        pBVar10 = rsa->d;
        pBVar8 = &local_54;
        local_54.d = pBVar10->d;
        local_54.top = pBVar10->top;
        local_54.dmax = pBVar10->dmax;
        local_54.neg = pBVar10->neg;
        local_54.flags = local_54.flags & 1U | pBVar10->flags & 0xfffffffeU | 6;
      }
      else {
        pBVar8 = rsa->d;
      }
      iVar7 = (*(code *)PTR_BN_div_006a855c)(0,rsa->dmp1,pBVar8,unaff_s3,unaff_s6);
      if ((iVar7 == 0) ||
         (iVar7 = (*(code *)PTR_BN_div_006a855c)(0,rsa->dmq1,pBVar8,unaff_s4,unaff_s6), iVar7 == 0))
      goto LAB_0050d66c;
      if ((rsa->flags & 0x100U) == 0) {
        pBVar10 = rsa->p;
        pBVar8 = &local_40;
        local_40.d = pBVar10->d;
        local_40.top = pBVar10->top;
        local_40.dmax = pBVar10->dmax;
        local_40.neg = pBVar10->neg;
        local_40.flags = local_40.flags & 1U | pBVar10->flags & 0xfffffffeU | 6;
      }
      else {
        pBVar8 = rsa->p;
      }
      iVar7 = (*(code *)PTR_BN_mod_inverse_006a85f0)(rsa->iqmp,rsa->q,pBVar8,unaff_s6);
      if (iVar7 == 0) goto LAB_0050d66c;
      pRVar3 = (RSA *)0x1;
    }
    BN_CTX_end(unaff_s6);
    BN_CTX_free(unaff_s6);
    rsa = pRVar3;
  } while( true );
}

