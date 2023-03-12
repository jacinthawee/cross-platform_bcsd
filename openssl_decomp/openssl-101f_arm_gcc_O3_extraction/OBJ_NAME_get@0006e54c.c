
char * OBJ_NAME_get(char *name,int type)

{
  void *pvVar1;
  int iVar2;
  uint local_20 [2];
  char *local_18;
  
  if (name != (char *)0x0) {
    if (names_lh == (_LHASH *)0x0) {
      CRYPTO_mem_ctrl(3);
      names_lh = lh_new(obj_name_LHASH_HASH + 1,(LHASH_COMP_FN_TYPE)&DAT_0006e2e1);
      CRYPTO_mem_ctrl(2);
      if (names_lh == (_LHASH *)0x0) {
        return (char *)0x0;
      }
    }
    local_20[0] = type & 0xffff7fff;
    local_18 = name;
    if (type << 0x10 < 0) {
      pvVar1 = lh_retrieve(names_lh,local_20);
      if (pvVar1 != (void *)0x0) {
LAB_0006e59a:
        return *(char **)((int)pvVar1 + 0xc);
      }
    }
    else {
      iVar2 = 0xb;
      while (pvVar1 = lh_retrieve(names_lh,local_20), pvVar1 != (void *)0x0) {
        if (*(int *)((int)pvVar1 + 4) == 0) goto LAB_0006e59a;
        iVar2 = iVar2 + -1;
        if (iVar2 == 0) {
          return (char *)0x0;
        }
        local_18 = *(char **)((int)pvVar1 + 0xc);
      }
    }
  }
  return (char *)0x0;
}

