
EC_POINT * EC_POINT_dup(EC_POINT *src,EC_GROUP *group)

{
  code *pcVar1;
  int *ptr;
  int iVar2;
  
  if (src == (EC_POINT *)0x0) {
    return (EC_POINT *)0x0;
  }
  if (group == (EC_GROUP *)0x0) {
    ERR_put_error(0x10,0x79,0x43,"ec_lib.c",0x29f);
    return (EC_POINT *)0x0;
  }
  if (*(int *)(*(int *)group + 0x28) == 0) {
    ERR_put_error(0x10,0x79,0x42,"ec_lib.c",0x2a3);
    return (EC_POINT *)0x0;
  }
  ptr = (int *)CRYPTO_malloc(0x44,"ec_lib.c",0x2a7);
  if (ptr != (int *)0x0) {
    iVar2 = *(int *)group;
    *ptr = iVar2;
    iVar2 = (**(code **)(iVar2 + 0x28))(ptr);
    if (iVar2 == 0) {
      CRYPTO_free(ptr);
      return (EC_POINT *)0x0;
    }
    pcVar1 = *(code **)(*ptr + 0x34);
    if (pcVar1 == (code *)0x0) {
      ERR_put_error(0x10,0x72,0x42,"ec_lib.c",0x2d1);
    }
    else if (*ptr == *(int *)src) {
      if ((int *)src == ptr) {
        return src;
      }
      iVar2 = (*pcVar1)(ptr,src);
      if (iVar2 != 0) {
        return (EC_POINT *)ptr;
      }
    }
    else {
      ERR_put_error(0x10,0x72,0x65,"ec_lib.c",0x2d5);
    }
    if (*(code **)(*ptr + 0x2c) != (code *)0x0) {
      (**(code **)(*ptr + 0x2c))(ptr);
    }
    CRYPTO_free(ptr);
    return (EC_POINT *)0x0;
  }
  ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2a9);
  return (EC_POINT *)0x0;
}

