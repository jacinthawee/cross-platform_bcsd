
undefined4 dlfcn_unload(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    uVar3 = 1;
    iVar1 = sk_num(*(_STACK **)(param_1 + 4));
    if (0 < iVar1) {
      pvVar2 = sk_pop(*(_STACK **)(param_1 + 4));
      if (pvVar2 == (void *)0x0) {
        uVar3 = 0;
        ERR_put_error(0x25,0x67,0x68,"dso_dlfcn.c",0xdd);
        sk_push(*(_STACK **)(param_1 + 4),(void *)0x0);
      }
      else {
        dlclose(pvVar2);
      }
    }
    return uVar3;
  }
  ERR_put_error(0x25,0x67,0x43,"dso_dlfcn.c",0xd5);
  return 0;
}

