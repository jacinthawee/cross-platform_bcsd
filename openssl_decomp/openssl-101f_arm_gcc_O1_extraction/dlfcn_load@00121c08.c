
char * dlfcn_load(DSO *param_1)

{
  char *ptr;
  void *data;
  int iVar1;
  undefined4 uVar2;
  
  ptr = DSO_convert_filename(param_1,(char *)0x0);
  if (ptr == (char *)0x0) {
    ERR_put_error(0x25,0x66,0x6f,"dso_dlfcn.c",0xb0);
  }
  else {
    if ((param_1->flags & 0x20U) == 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 0x102;
    }
    data = (void *)dlopen(ptr,uVar2);
    if (data == (void *)0x0) {
      ERR_put_error(0x25,0x66,0x67,"dso_dlfcn.c",0xbb);
      uVar2 = dlerror();
      ERR_add_error_data(4,"filename(",ptr,"): ",uVar2);
      CRYPTO_free(ptr);
      return (char *)0x0;
    }
    iVar1 = sk_push((_STACK *)param_1->meth_data,data);
    if (iVar1 == 0) {
      ERR_put_error(0x25,0x66,0x69,"dso_dlfcn.c",0xc1);
      CRYPTO_free(ptr);
      dlclose(data);
      return (char *)0x0;
    }
    param_1->loaded_filename = ptr;
    ptr = (char *)0x1;
  }
  return ptr;
}

