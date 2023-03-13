
EC_POINT * EC_POINT_new(EC_GROUP *group)

{
  int *ptr;
  int iVar1;
  int line;
  
  if (group == (EC_GROUP *)0x0) {
    line = 0x29f;
    iVar1 = 0x43;
  }
  else {
    if (*(int *)(*(int *)group + 0x28) != 0) {
      ptr = (int *)CRYPTO_malloc(0x44,"ec_lib.c",0x2a7);
      if (ptr == (int *)0x0) {
        ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2a9);
        return (EC_POINT *)0x0;
      }
      iVar1 = *(int *)group;
      *ptr = iVar1;
      iVar1 = (**(code **)(iVar1 + 0x28))(ptr);
      if (iVar1 != 0) {
        return (EC_POINT *)ptr;
      }
      CRYPTO_free(ptr);
      return (EC_POINT *)0x0;
    }
    line = 0x2a3;
    iVar1 = 0x42;
  }
  ERR_put_error(0x10,0x79,iVar1,"ec_lib.c",line);
  return (EC_POINT *)0x0;
}

