
int EC_GROUP_set_generator(EC_GROUP *group,EC_POINT *generator,BIGNUM *order,BIGNUM *cofactor)

{
  undefined4 uVar1;
  int iVar2;
  BIGNUM *pBVar3;
  int *piVar4;
  undefined4 uVar5;
  code *pcVar6;
  
  if (generator == (EC_POINT *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x6f,0x43,"ec_lib.c",0x120);
    return 0;
  }
  piVar4 = *(int **)(group + 4);
  if (piVar4 == (int *)0x0) {
    if (*(int *)(*(int *)group + 0x28) == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x79,0x42,"ec_lib.c",0x2c0);
      *(undefined4 *)(group + 4) = 0;
      return 0;
    }
    piVar4 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x44,"ec_lib.c",0x2c4);
    if (piVar4 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x79,0x41,"ec_lib.c",0x2c7);
      *(undefined4 *)(group + 4) = 0;
      return 0;
    }
    pcVar6 = *(code **)(*(int *)group + 0x28);
    *piVar4 = *(int *)group;
    iVar2 = (*pcVar6)(piVar4);
    if (iVar2 == 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(piVar4);
      *(undefined4 *)(group + 4) = 0;
      return 0;
    }
    *(int **)(group + 4) = piVar4;
  }
  pcVar6 = *(code **)(*piVar4 + 0x34);
  uVar5 = 0x42;
  if (pcVar6 == (code *)0x0) {
    uVar1 = 0x2f2;
  }
  else {
    if (*piVar4 == *(int *)generator) {
      if (((int *)generator != piVar4) && (iVar2 = (*pcVar6)(piVar4,generator,0x42), iVar2 == 0)) {
        return 0;
      }
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
    uVar5 = 0x65;
    uVar1 = 0x2f7;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x72,uVar5,"ec_lib.c",uVar1);
  return 0;
}

