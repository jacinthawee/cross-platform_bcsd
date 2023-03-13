
int SetBlobCmp(void **param_1,void **param_2)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  void *__n;
  
  pvVar1 = param_1[1];
  pvVar2 = param_2[1];
  __n = pvVar1;
  if ((int)pvVar2 <= (int)pvVar1) {
    __n = pvVar2;
  }
  iVar3 = memcmp(*param_1,*param_2,(size_t)__n);
  if (iVar3 == 0) {
    iVar3 = (int)pvVar1 - (int)pvVar2;
  }
  return iVar3;
}

