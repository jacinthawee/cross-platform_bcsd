
undefined4 gost_digest_copy(int param_1,int param_2)

{
  void *pvVar1;
  
  if ((*(void **)(param_1 + 0xc) != (void *)0x0) && (*(void **)(param_2 + 0xc) != (void *)0x0)) {
    pvVar1 = memcpy(*(void **)(param_1 + 0xc),*(void **)(param_2 + 0xc),0x1090);
    *(int *)((int)pvVar1 + 8) = (int)pvVar1 + 0x70;
  }
  return 1;
}

