
EC_POINT * EC_POINT_dup(EC_POINT *src,EC_GROUP *group)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  if (src == (EC_POINT *)0x0) {
    return (EC_POINT *)0x0;
  }
  if (group == (EC_GROUP *)0x0) {
    uVar4 = 0x43;
    uVar3 = 0x29f;
  }
  else {
    if (*(int *)(*(int *)group + 0x28) != 0) {
      piVar1 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x44,"ec_lib.c",0x2a7);
      if (piVar1 == (int *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x79,0x41,"ec_lib.c",0x2a9);
        return (EC_POINT *)0x0;
      }
      pcVar5 = *(code **)(*(int *)group + 0x28);
      *piVar1 = *(int *)group;
      iVar2 = (*pcVar5)(piVar1);
      if (iVar2 == 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
        return (EC_POINT *)0x0;
      }
      pcVar5 = *(code **)(*piVar1 + 0x34);
      if (pcVar5 == (code *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x72,0x42,"ec_lib.c",0x2d1);
      }
      else if (*piVar1 == *(int *)src) {
        if ((int *)src == piVar1) {
          return src;
        }
        iVar2 = (*pcVar5)(piVar1,src);
        if (iVar2 != 0) {
          return (EC_POINT *)piVar1;
        }
      }
      else {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x72,0x65,"ec_lib.c",0x2d5);
      }
      if (*(code **)(*piVar1 + 0x2c) != (code *)0x0) {
        (**(code **)(*piVar1 + 0x2c))(piVar1);
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
      return (EC_POINT *)0x0;
    }
    uVar4 = 0x42;
    uVar3 = 0x2a3;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x79,uVar4,"ec_lib.c",uVar3);
  return (EC_POINT *)0x0;
}

