
int int_get_new_index(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 *ptr;
  int iVar2;
  void *mode;
  int iVar3;
  
  iVar1 = def_get_class();
  if (iVar1 == 0) {
    iVar3 = -1;
  }
  else {
    ptr = (undefined4 *)CRYPTO_malloc(0x14,"ex_data.c",0x162);
    if (ptr == (undefined4 *)0x0) {
      ERR_put_error(0xf,0x68,0x41,"ex_data.c",0x164);
      iVar3 = -1;
    }
    else {
      *ptr = param_2;
      ptr[1] = param_3;
      ptr[2] = param_4;
      ptr[4] = param_5;
      ptr[3] = param_6;
      CRYPTO_lock(param_6,9,(char *)0x2,(int)"ex_data.c");
      do {
        iVar2 = sk_num(*(_STACK **)(iVar1 + 4));
        iVar3 = *(int *)(iVar1 + 8);
        if (iVar3 < iVar2) {
          *(int *)(iVar1 + 8) = iVar3 + 1;
          mode = sk_set(*(_STACK **)(iVar1 + 4),iVar3,ptr);
          goto LAB_080d2587;
        }
        mode = (void *)sk_push(*(_STACK **)(iVar1 + 4),(void *)0x0);
      } while (mode != (void *)0x0);
      iVar3 = -1;
      ERR_put_error(0xf,0x68,0x41,"ex_data.c",0x16f);
      CRYPTO_free(ptr);
LAB_080d2587:
      CRYPTO_lock((int)mode,10,(char *)0x2,(int)"ex_data.c");
    }
  }
  return iVar3;
}

