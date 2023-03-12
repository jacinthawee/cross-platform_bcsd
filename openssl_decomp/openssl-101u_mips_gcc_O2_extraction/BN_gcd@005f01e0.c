
int BN_gcd(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  undefined *puVar1;
  BIGNUM *r_00;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  BIGNUM *b_00;
  uint uVar5;
  
  (*(code *)PTR_BN_CTX_start_006a8528)(ctx);
  r_00 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  pBVar2 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  if ((((r_00 != (BIGNUM *)0x0) && (pBVar2 != (BIGNUM *)0x0)) &&
      (iVar3 = (*(code *)PTR_BN_copy_006a8450)(r_00,a), iVar3 != 0)) &&
     (iVar3 = (*(code *)PTR_BN_copy_006a8450)(pBVar2,b), puVar1 = PTR_BN_cmp_006a7960, iVar3 != 0))
  {
    r_00->neg = 0;
    pBVar2->neg = 0;
    iVar3 = (*(code *)puVar1)(r_00,pBVar2);
    b_00 = pBVar2;
    if (iVar3 < 0) {
      b_00 = r_00;
      r_00 = pBVar2;
    }
    iVar3 = 0;
LAB_005f02b0:
    iVar4 = b_00->top;
    pBVar2 = b_00;
    b_00 = r_00;
    if (iVar4 != 0) {
      do {
        b_00 = pBVar2;
        if ((r_00->top < 1) || ((*r_00->d & 1) == 0)) {
          if ((iVar4 < 1) || ((*b_00->d & 1) == 0)) {
            iVar4 = (*(code *)PTR_BN_rshift1_006a7958)();
            if ((iVar4 == 0) || (iVar4 = (*(code *)PTR_BN_rshift1_006a7958)(b_00,b_00), iVar4 == 0))
            goto LAB_005f0374;
            iVar3 = iVar3 + 1;
            goto LAB_005f02b0;
          }
          iVar4 = (*(code *)PTR_BN_rshift1_006a7958)(r_00,r_00);
          if (iVar4 == 0) {
            uVar5 = 0;
            goto LAB_005f0378;
          }
        }
        else if ((iVar4 < 1) || ((*b_00->d & 1) == 0)) {
          iVar4 = (*(code *)PTR_BN_rshift1_006a7958)(b_00,b_00);
          if (iVar4 == 0) goto LAB_005f0374;
        }
        else {
          iVar4 = BN_sub(r_00,r_00,b_00);
          if (iVar4 == 0) goto LAB_005f0374;
          iVar4 = (*(code *)PTR_BN_rshift1_006a7958)(r_00,r_00);
          if (iVar4 == 0) {
            uVar5 = 0;
            goto LAB_005f0378;
          }
        }
        iVar4 = (*(code *)PTR_BN_cmp_006a7960)(r_00,b_00);
        if (-1 < iVar4) goto LAB_005f02b0;
        iVar4 = r_00->top;
        pBVar2 = r_00;
        r_00 = b_00;
        if (iVar4 == 0) break;
      } while( true );
    }
    if ((iVar3 == 0) || (iVar3 = (*(code *)PTR_BN_lshift_006a8498)(b_00,b_00,iVar3), iVar3 != 0)) {
      iVar3 = (*(code *)PTR_BN_copy_006a8450)(r,b_00);
      uVar5 = (uint)(iVar3 != 0);
      goto LAB_005f0378;
    }
  }
LAB_005f0374:
  uVar5 = 0;
LAB_005f0378:
  (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
  return uVar5;
}

