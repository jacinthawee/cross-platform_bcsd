
int EC_GROUP_set_generator(EC_GROUP *group,EC_POINT *generator,BIGNUM *order,BIGNUM *cofactor)

{
  int iVar1;
  BIGNUM *pBVar2;
  int *ptr;
  code *pcVar3;
  
  if (generator == (EC_POINT *)0x0) {
    ERR_put_error(0x10,0x6f,0x43,"ec_lib.c",0x120);
    return 0;
  }
  ptr = *(int **)(group + 4);
  if (ptr != (int *)0x0) {
LAB_000907dc:
    pcVar3 = *(code **)(*ptr + 0x34);
    if (pcVar3 == (code *)0x0) {
      ERR_put_error(0x10,0x72,0x42,"ec_lib.c",0x2f2);
    }
    else if (*ptr == *(int *)generator) {
      if (((int *)generator == ptr) || (iVar1 = (*pcVar3)(ptr,generator), iVar1 != 0)) {
        if (order == (BIGNUM *)0x0) {
          BN_set_word((BIGNUM *)(group + 8),0);
        }
        else {
          pBVar2 = BN_copy((BIGNUM *)(group + 8),order);
          if (pBVar2 == (BIGNUM *)0x0) {
            return 0;
          }
        }
        if (cofactor != (BIGNUM *)0x0) {
          pBVar2 = BN_copy((BIGNUM *)(group + 0x1c),cofactor);
          if (pBVar2 != (BIGNUM *)0x0) {
            pBVar2 = (BIGNUM *)0x1;
          }
          return (int)pBVar2;
        }
        BN_set_word((BIGNUM *)(group + 0x1c),0);
        return 1;
      }
    }
    else {
      ERR_put_error(0x10,0x72,0x65,"ec_lib.c",0x2f7);
    }
    return 0;
  }
  if (*(int *)(*(int *)group + 0x28) == 0) {
    ERR_put_error(0x10,0x79,0x42,"ec_lib.c",0x2c0);
  }
  else {
    ptr = (int *)CRYPTO_malloc(0x44,"ec_lib.c",0x2c4);
    if (ptr == (int *)0x0) {
      ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2c7);
    }
    else {
      iVar1 = *(int *)group;
      *ptr = iVar1;
      iVar1 = (**(code **)(iVar1 + 0x28))();
      if (iVar1 != 0) {
        *(int **)(group + 4) = ptr;
        goto LAB_000907dc;
      }
      CRYPTO_free(ptr);
    }
  }
  *(undefined4 *)(group + 4) = 0;
  return 0;
}

