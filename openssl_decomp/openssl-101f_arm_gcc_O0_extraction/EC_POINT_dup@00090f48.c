
EC_POINT * EC_POINT_dup(EC_POINT *src,EC_GROUP *group)

{
  int *ptr;
  code *pcVar1;
  int iVar2;
  
  if (src != (EC_POINT *)0x0) {
    if (group == (EC_GROUP *)0x0) {
      ERR_put_error(0x10,0x79,0x43,"ec_lib.c",699);
    }
    else if (*(int *)(*(int *)group + 0x28) == 0) {
      ERR_put_error(0x10,0x79,0x42,"ec_lib.c",0x2c0);
    }
    else {
      ptr = (int *)CRYPTO_malloc(0x44,"ec_lib.c",0x2c4);
      if (ptr == (int *)0x0) {
        ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2c7);
      }
      else {
        iVar2 = *(int *)group;
        *ptr = iVar2;
        iVar2 = (**(code **)(iVar2 + 0x28))();
        if (iVar2 != 0) {
          pcVar1 = *(code **)(*ptr + 0x34);
          if (pcVar1 == (code *)0x0) {
            ERR_put_error(0x10,0x72,0x42,"ec_lib.c",0x2f2);
          }
          else if (*ptr == *(int *)src) {
            if (((int *)src == ptr) ||
               (iVar2 = (*pcVar1)(ptr,src), src = (EC_POINT *)ptr, iVar2 != 0)) {
              return src;
            }
          }
          else {
            ERR_put_error(0x10,0x72,0x65,"ec_lib.c",0x2f7);
          }
          if (*(code **)(*ptr + 0x2c) != (code *)0x0) {
            (**(code **)(*ptr + 0x2c))(ptr);
          }
        }
        CRYPTO_free(ptr);
      }
    }
  }
  return (EC_POINT *)0x0;
}

