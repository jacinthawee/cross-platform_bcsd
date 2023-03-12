
int EC_GROUP_cmp(EC_GROUP *a,EC_GROUP *b,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  BIGNUM *local_34;
  BIGNUM *local_30;
  BN_CTX *local_2c;
  BIGNUM *local_28;
  BIGNUM *local_24;
  BIGNUM *local_20;
  
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
    local_34 = BN_CTX_get(ctx);
    local_30 = BN_CTX_get(ctx);
    local_28 = BN_CTX_get(ctx);
    local_24 = BN_CTX_get(ctx);
    local_20 = BN_CTX_get(ctx);
    pBVar1 = BN_CTX_get(ctx);
    local_2c = ctx;
    if (pBVar1 == (BIGNUM *)0x0) {
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      return -1;
    }
  }
  else {
    BN_CTX_start(ctx);
    local_34 = BN_CTX_get(ctx);
    local_30 = BN_CTX_get(ctx);
    local_28 = BN_CTX_get(ctx);
    local_24 = BN_CTX_get(ctx);
    local_20 = BN_CTX_get(ctx);
    pBVar1 = BN_CTX_get(ctx);
    if (pBVar1 == (BIGNUM *)0x0) {
      BN_CTX_end(ctx);
      return -1;
    }
    local_2c = (BN_CTX *)0x0;
  }
  iVar2 = (**(code **)(*(int *)a + 0x1c))(a,local_34,local_30,local_28,ctx);
  if (((iVar2 != 0) &&
      (iVar2 = (**(code **)(*(int *)b + 0x1c))(b,local_24,local_20,pBVar1,ctx), iVar2 != 0)) &&
     ((iVar2 = BN_cmp(local_34,local_24), iVar2 == 0 &&
      ((iVar2 = BN_cmp(local_30,local_20), iVar2 == 0 &&
       (iVar2 = BN_cmp(local_28,pBVar1), iVar2 == 0)))))) {
    iVar2 = *(int *)a;
    if (*(code **)(iVar2 + 0x6c) == (code *)0x0) {
      ERR_put_error(0x10,0x71,0x42,"ec_lib.c",0x3e3);
    }
    else if ((iVar2 == **(int **)(a + 4)) && (iVar2 == **(int **)(b + 4))) {
      iVar2 = (**(code **)(iVar2 + 0x6c))(a,*(int **)(a + 4),*(int **)(b + 4),ctx);
      if (iVar2 == 0) {
        pBVar1 = BN_copy(local_34,(BIGNUM *)(a + 8));
        if (((((pBVar1 == (BIGNUM *)0x0) || (local_34->top == 0)) ||
             (pBVar1 = BN_copy(local_24,(BIGNUM *)(b + 8)), pBVar1 == (BIGNUM *)0x0)) ||
            ((local_24->top == 0 ||
             (pBVar1 = BN_copy(local_30,(BIGNUM *)(a + 0x1c)), pBVar1 == (BIGNUM *)0x0)))) ||
           ((*(int *)(a + 0x20) == 0 ||
            ((pBVar1 = BN_copy(local_20,(BIGNUM *)(b + 0x1c)), pBVar1 == (BIGNUM *)0x0 ||
             (*(int *)(b + 0x20) == 0)))))) {
          BN_CTX_end(ctx);
          if (local_2c == (BN_CTX *)0x0) {
            return -1;
          }
          BN_CTX_free(ctx);
          return -1;
        }
        iVar2 = BN_cmp(local_34,local_24);
        if (iVar2 == 0) {
          iVar2 = BN_cmp(local_30,local_20);
          uVar3 = (uint)(iVar2 != 0);
          goto LAB_08101408;
        }
      }
    }
    else {
      ERR_put_error(0x10,0x71,0x65,"ec_lib.c",1000);
    }
  }
  uVar3 = 1;
LAB_08101408:
  BN_CTX_end(ctx);
  if (local_2c != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
    return uVar3;
  }
  return uVar3;
}

