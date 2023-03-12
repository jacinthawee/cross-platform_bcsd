
void * dlfcn_unload(int param_1)

{
  int iVar1;
  void *pvVar2;
  
  if (param_1 == 0) {
    ERR_put_error(0x25,0x67,0x43,"dso_dlfcn.c",0xd5);
    return (void *)0x0;
  }
  iVar1 = sk_num(*(_STACK **)(param_1 + 4));
  if (iVar1 < 1) {
    pvVar2 = (void *)0x1;
  }
  else {
    pvVar2 = sk_pop(*(_STACK **)(param_1 + 4));
    if (pvVar2 == (void *)0x0) {
      ERR_put_error(0x25,0x67,0x68,"dso_dlfcn.c",0xdd);
      sk_push(*(_STACK **)(param_1 + 4),(void *)0x0);
    }
    else {
      dlclose();
      pvVar2 = (void *)0x1;
    }
  }
  return pvVar2;
}

