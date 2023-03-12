
int BN_gcd(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  undefined *puVar1;
  BIGNUM *r_00;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  BIGNUM *b_00;
  uint uVar5;
  
  (*(code *)PTR_BN_CTX_start_006a9644)(ctx);
  r_00 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
  pBVar2 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
  if ((((r_00 != (BIGNUM *)0x0) && (pBVar2 != (BIGNUM *)0x0)) &&
      (iVar3 = (*(code *)PTR_BN_copy_006a9570)(r_00,a), iVar3 != 0)) &&
     (iVar3 = (*(code *)PTR_BN_copy_006a9570)(pBVar2,b), puVar1 = PTR_BN_cmp_006a8a4c, iVar3 != 0))
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
LAB_005f22e0:
    iVar4 = b_00->top;
    pBVar2 = b_00;
    b_00 = r_00;
    if (iVar4 != 0) {
      do {
        b_00 = pBVar2;
        if ((r_00->top < 1) || ((*r_00->d & 1) == 0)) {
          if ((iVar4 < 1) || ((*b_00->d & 1) == 0)) {
            iVar4 = (*(code *)PTR_BN_rshift1_006a8a44)();
            if ((iVar4 == 0) || (iVar4 = (*(code *)PTR_BN_rshift1_006a8a44)(b_00,b_00), iVar4 == 0))
            goto LAB_005f23a4;
            iVar3 = iVar3 + 1;
            goto LAB_005f22e0;
          }
          iVar4 = (*(code *)PTR_BN_rshift1_006a8a44)(r_00,r_00);
          if (iVar4 == 0) {
            uVar5 = 0;
            goto LAB_005f23a8;
          }
        }
        else if ((iVar4 < 1) || ((*b_00->d & 1) == 0)) {
          iVar4 = (*(code *)PTR_BN_rshift1_006a8a44)(b_00,b_00);
          if (iVar4 == 0) goto LAB_005f23a4;
        }
        else {
          iVar4 = BN_sub(r_00,r_00,b_00);
          if (iVar4 == 0) goto LAB_005f23a4;
          iVar4 = (*(code *)PTR_BN_rshift1_006a8a44)(r_00,r_00);
          if (iVar4 == 0) {
            uVar5 = 0;
            goto LAB_005f23a8;
          }
        }
        iVar4 = (*(code *)PTR_BN_cmp_006a8a4c)(r_00,b_00);
        if (-1 < iVar4) goto LAB_005f22e0;
        iVar4 = r_00->top;
        pBVar2 = r_00;
        r_00 = b_00;
        if (iVar4 == 0) break;
      } while( true );
    }
    if ((iVar3 == 0) || (iVar3 = (*(code *)PTR_BN_lshift_006a95b8)(b_00,b_00,iVar3), iVar3 != 0)) {
      iVar3 = (*(code *)PTR_BN_copy_006a9570)(r,b_00);
      uVar5 = (uint)(iVar3 != 0);
      goto LAB_005f23a8;
    }
  }
LAB_005f23a4:
  uVar5 = 0;
LAB_005f23a8:
  (*(code *)PTR_BN_CTX_end_006a9654)(ctx);
  return uVar5;
}

