
int EC_GROUP_cmp(EC_GROUP *a,EC_GROUP *b,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *pBVar1;
  BIGNUM *b_00;
  BIGNUM *b_01;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  BN_CTX *pBVar6;
  BIGNUM *local_2c;
  
  if (*(int *)(*(int *)a + 4) != *(int *)(*(int *)b + 4)) {
    return 1;
  }
  if (((*(int *)(a + 0x30) != 0) && (*(int *)(b + 0x30) != 0)) &&
     (*(int *)(b + 0x30) != *(int *)(a + 0x30))) {
    return 1;
  }
  if (ctx == (BN_CTX *)0x0) {
    ctx = BN_CTX_new();
    if (ctx == (BN_CTX *)0x0) {
      return -1;
    }
    BN_CTX_start(ctx);
    a_00 = BN_CTX_get(ctx);
    a_01 = BN_CTX_get(ctx);
    pBVar1 = BN_CTX_get(ctx);
    b_00 = BN_CTX_get(ctx);
    local_2c = BN_CTX_get(ctx);
    b_01 = BN_CTX_get(ctx);
    pBVar6 = ctx;
    if (b_01 == (BIGNUM *)0x0) {
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      return -1;
    }
  }
  else {
    BN_CTX_start(ctx);
    a_00 = BN_CTX_get(ctx);
    a_01 = BN_CTX_get(ctx);
    pBVar1 = BN_CTX_get(ctx);
    b_00 = BN_CTX_get(ctx);
    local_2c = BN_CTX_get(ctx);
    b_01 = BN_CTX_get(ctx);
    if (b_01 == (BIGNUM *)0x0) {
      BN_CTX_end(ctx);
      return -1;
    }
    pBVar6 = (BN_CTX *)0x0;
  }
  iVar2 = (**(code **)(*(int *)a + 0x1c))(a,a_00,a_01,pBVar1,ctx);
  if (((iVar2 != 0) &&
      (iVar2 = (**(code **)(*(int *)b + 0x1c))(b,b_00,local_2c,b_01,ctx), iVar2 != 0)) &&
     ((iVar2 = BN_cmp(a_00,b_00), iVar2 == 0 &&
      ((iVar2 = BN_cmp(a_01,local_2c), iVar2 == 0 && (iVar2 = BN_cmp(pBVar1,b_01), iVar2 == 0))))))
  {
    iVar2 = *(int *)a;
    if (*(code **)(iVar2 + 0x6c) == (code *)0x0) {
      uVar4 = 0x42;
      uVar3 = 0x3c2;
    }
    else {
      if ((iVar2 == **(int **)(a + 4)) && (iVar2 == **(int **)(b + 4))) {
        iVar2 = (**(code **)(iVar2 + 0x6c))(a,*(int **)(a + 4),*(int **)(b + 4),ctx);
        if (iVar2 == 0) {
          pBVar1 = BN_copy(a_00,(BIGNUM *)(a + 8));
          if (((((pBVar1 == (BIGNUM *)0x0) || (a_00->top == 0)) ||
               (pBVar1 = BN_copy(b_00,(BIGNUM *)(b + 8)), pBVar1 == (BIGNUM *)0x0)) ||
              ((b_00->top == 0 ||
               (pBVar1 = BN_copy(a_01,(BIGNUM *)(a + 0x1c)), pBVar1 == (BIGNUM *)0x0)))) ||
             ((*(int *)(a + 0x20) == 0 ||
              ((pBVar1 = BN_copy(local_2c,(BIGNUM *)(b + 0x1c)), pBVar1 == (BIGNUM *)0x0 ||
               (*(int *)(b + 0x20) == 0)))))) {
            BN_CTX_end(ctx);
            if (pBVar6 == (BN_CTX *)0x0) {
              return -1;
            }
            BN_CTX_free(ctx);
            return -1;
          }
          iVar2 = BN_cmp(a_00,b_00);
          if (iVar2 == 0) {
            iVar2 = BN_cmp(a_01,local_2c);
            uVar5 = (uint)(iVar2 != 0);
            goto LAB_00501d70;
          }
        }
        goto LAB_00501d6c;
      }
      uVar4 = 0x65;
      uVar3 = 0x3c6;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x71,uVar4,"ec_lib.c",uVar3);
  }
LAB_00501d6c:
  uVar5 = 1;
LAB_00501d70:
  BN_CTX_end(ctx);
  if (pBVar6 != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
    return uVar5;
  }
  return uVar5;
}

