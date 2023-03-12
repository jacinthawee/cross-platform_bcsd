
void ec_pre_comp_free(void *param_1)

{
  int iVar1;
  EC_POINT *point;
  EC_POINT **ptr;
  
  if ((param_1 != (void *)0x0) &&
     (iVar1 = CRYPTO_add_lock((int *)((int)param_1 + 0x18),-1,0x24,"ec_mult.c",0x8c), iVar1 < 1)) {
    ptr = *(EC_POINT ***)((int)param_1 + 0x10);
    if (ptr != (EC_POINT **)0x0) {
      point = *ptr;
      if (point != (EC_POINT *)0x0) {
        do {
          ptr = ptr + 1;
          EC_POINT_free(point);
          point = *ptr;
        } while (point != (EC_POINT *)0x0);
        ptr = *(EC_POINT ***)((int)param_1 + 0x10);
      }
      CRYPTO_free(ptr);
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

