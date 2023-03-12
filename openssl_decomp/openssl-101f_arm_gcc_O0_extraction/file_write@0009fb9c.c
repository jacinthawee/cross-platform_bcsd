
void * file_write(int param_1,void *param_2,void *param_3)

{
  size_t sVar1;
  void *pvVar2;
  
  pvVar2 = *(void **)(param_1 + 0xc);
  if (((*(void **)(param_1 + 0xc) != (void *)0x0) && (pvVar2 = param_2, param_2 != (void *)0x0)) &&
     (sVar1 = fwrite(param_2,(size_t)param_3,1,*(FILE **)(param_1 + 0x20)), pvVar2 = param_3,
     sVar1 == 0)) {
    pvVar2 = (void *)0x0;
  }
  return pvVar2;
}

