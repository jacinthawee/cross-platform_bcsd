
int EC_GROUP_set_generator(EC_GROUP *group,EC_POINT *generator,BIGNUM *order,BIGNUM *cofactor)

{
  code *pcVar1;
  int iVar2;
  BIGNUM *pBVar3;
  int *ptr;
  
  if (generator == (EC_POINT *)0x0) {
    ERR_put_error(0x10,0x6f,0x43,"ec_lib.c",0x112);
    return 0;
  }
  ptr = *(int **)(group + 4);
  if (ptr != (int *)0x0) {
LAB_080ff336:
    pcVar1 = *(code **)(*ptr + 0x34);
    if (pcVar1 == (code *)0x0) {
      ERR_put_error(0x10,0x72,0x42,"ec_lib.c",0x2d1);
    }
    else if (*ptr == *(int *)generator) {
      if (((int *)generator == ptr) || (iVar2 = (*pcVar1)(ptr,generator), iVar2 != 0)) {
        if (order == (BIGNUM *)0x0) {
          BN_set_word((BIGNUM *)(group + 8),0);
        }
        else {
          pBVar3 = BN_copy((BIGNUM *)(group + 8),order);
          if (pBVar3 == (BIGNUM *)0x0) {
            return 0;
          }
        }
        if (cofactor != (BIGNUM *)0x0) {
          pBVar3 = BN_copy((BIGNUM *)(group + 0x1c),cofactor);
          return (uint)(pBVar3 != (BIGNUM *)0x0);
        }
        BN_set_word((BIGNUM *)(group + 0x1c),0);
        return 1;
      }
    }
    else {
      ERR_put_error(0x10,0x72,0x65,"ec_lib.c",0x2d5);
    }
    return 0;
  }
  if (*(int *)(*(int *)group + 0x28) == 0) {
    ERR_put_error(0x10,0x79,0x42,"ec_lib.c",0x2a3);
  }
  else {
    ptr = (int *)CRYPTO_malloc(0x44,"ec_lib.c",0x2a7);
    if (ptr == (int *)0x0) {
      ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2a9);
    }
    else {
      iVar2 = *(int *)group;
      *ptr = iVar2;
      iVar2 = (**(code **)(iVar2 + 0x28))(ptr);
      if (iVar2 != 0) {
        *(int **)(group + 4) = ptr;
        goto LAB_080ff336;
      }
      CRYPTO_free(ptr);
    }
  }
  *(undefined4 *)(group + 4) = 0;
  return 0;
}

