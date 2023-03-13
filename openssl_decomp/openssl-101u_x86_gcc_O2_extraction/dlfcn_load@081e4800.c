
undefined4 dlfcn_load(DSO *param_1)

{
  char *ptr;
  void *data;
  int iVar1;
  undefined4 uVar2;
  
  ptr = DSO_convert_filename(param_1,(char *)0x0);
  if (ptr == (char *)0x0) {
    uVar2 = 0;
    ERR_put_error(0x25,0x66,0x6f,"dso_dlfcn.c",0xb2);
  }
  else {
    data = (void *)dlopen(ptr,(-(uint)((param_1->flags & 0x20U) == 0) & 0xffffff00) + 0x102);
    if (data == (void *)0x0) {
      ERR_put_error(0x25,0x66,0x67,"dso_dlfcn.c",0xbb);
      uVar2 = dlerror();
      ERR_add_error_data(4,"filename(",ptr,"): ",uVar2);
      CRYPTO_free(ptr);
      return 0;
    }
    iVar1 = sk_push((_STACK *)param_1->meth_data,data);
    if (iVar1 == 0) {
      ERR_put_error(0x25,0x66,0x69,"dso_dlfcn.c",0xc0);
      CRYPTO_free(ptr);
      dlclose(data);
      return 0;
    }
    param_1->loaded_filename = ptr;
    uVar2 = 1;
  }
  return uVar2;
}

