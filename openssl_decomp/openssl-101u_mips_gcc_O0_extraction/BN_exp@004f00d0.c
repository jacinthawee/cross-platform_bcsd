
int BN_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  BIGNUM *a_01;
  int iVar4;
  int iVar5;
  
  if ((p->flags & 4U) != 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7b,0x42,"bn_exp.c",0x8b);
    return -1;
  }
  BN_CTX_start(ctx);
  if ((r == a) || (a_01 = r, p == r)) {
    a_01 = BN_CTX_get(ctx);
  }
  a_00 = BN_CTX_get(ctx);
  if (((a_01 != (BIGNUM *)0x0) && (a_00 != (BIGNUM *)0x0)) &&
     (pBVar1 = BN_copy(a_00,a), pBVar1 != (BIGNUM *)0x0)) {
    iVar2 = BN_num_bits(p);
    if ((p->top < 1) || ((*p->d & 1) == 0)) {
      pBVar1 = (BIGNUM *)BN_set_word(a_01,1);
    }
    else {
      pBVar1 = BN_copy(a_01,a);
    }
    if (pBVar1 != (BIGNUM *)0x0) {
      iVar4 = 1;
      if (1 < iVar2) {
        do {
          while( true ) {
            iVar3 = BN_sqr(a_00,a_00,ctx);
            iVar5 = iVar4 + 1;
            if (iVar3 == 0) goto LAB_004f01b8;
            iVar3 = BN_is_bit_set(p,iVar4);
            iVar4 = iVar5;
            if (iVar3 != 0) break;
            if (iVar2 == iVar5) goto LAB_004f0258;
          }
          iVar3 = BN_mul(a_01,a_01,a_00,ctx);
          if (iVar3 == 0) goto LAB_004f01b8;
        } while (iVar2 != iVar5);
      }
LAB_004f0258:
      if (a_01 == r) {
        iVar2 = 1;
      }
      else {
        iVar2 = 1;
        BN_copy(r,a_01);
      }
      goto LAB_004f01bc;
    }
  }
LAB_004f01b8:
  iVar2 = 0;
LAB_004f01bc:
  BN_CTX_end(ctx);
  return iVar2;
}

