
EC_POINT * EC_POINT_new(EC_GROUP *group)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (group == (EC_GROUP *)0x0) {
    ERR_put_error(0x10,0x79,0x43,"ec_lib.c",0x29f);
  }
  else {
    piVar3 = *(int **)(*(int *)group + 0x28);
    if (piVar3 == (int *)0x0) {
      ERR_put_error(0x10,0x79,0x42,"ec_lib.c",0x2a3);
      group = (EC_GROUP *)piVar3;
    }
    else {
      piVar3 = (int *)CRYPTO_malloc(0x44,"ec_lib.c",0x2a7);
      if (piVar3 == (int *)0x0) {
        ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2a9);
        group = (EC_GROUP *)piVar3;
      }
      else {
        iVar2 = *(int *)group;
        *piVar3 = iVar2;
        piVar1 = (int *)(**(code **)(iVar2 + 0x28))();
        group = (EC_GROUP *)piVar3;
        if (piVar1 == (int *)0x0) {
          CRYPTO_free(piVar3);
          group = (EC_GROUP *)piVar1;
        }
      }
    }
  }
  return (EC_POINT *)group;
}

