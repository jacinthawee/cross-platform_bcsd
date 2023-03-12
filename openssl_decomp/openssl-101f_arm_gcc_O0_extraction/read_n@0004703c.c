
uint read_n(int param_1,uint param_2,uint param_3,int param_4)

{
  size_t sVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  void *__dest;
  size_t __n;
  int iVar6;
  BIO *b;
  int iVar7;
  
  iVar2 = *(int *)(param_1 + 0x54);
  __n = *(size_t *)(iVar2 + 0x28);
  if ((int)param_2 <= (int)__n) {
    if (param_4 == 0) {
      iVar5 = *(int *)(iVar2 + 0x2c);
      *(int *)(param_1 + 0x4c) = *(int *)(iVar2 + 0x30) + iVar5;
      uVar4 = param_2;
    }
    else {
      iVar5 = *(int *)(iVar2 + 0x2c);
      uVar4 = *(int *)(param_1 + 0x50) + param_2;
    }
    *(uint *)(param_1 + 0x50) = uVar4;
    *(size_t *)(iVar2 + 0x28) = __n - param_2;
    *(uint *)(iVar2 + 0x2c) = iVar5 + param_2;
    return param_2;
  }
  if (*(int *)(param_1 + 0x60) == 0) {
    param_3 = param_2;
  }
  if (0x8000 < param_3) {
    param_3 = 0x8001;
  }
  if (__n == 0) {
    iVar5 = *(int *)(param_1 + 0x50);
    if ((iVar5 != 0) && (param_4 != 0)) goto LAB_0004710c;
    iVar6 = *(int *)(iVar2 + 0x30);
    iVar5 = 0;
    iVar7 = 0;
    *(int *)(param_1 + 0x4c) = iVar6;
    if ((int)param_2 < 1) goto LAB_00047138;
  }
  else {
    if (param_4 == 0) {
      iVar5 = param_4;
      if (*(int *)(iVar2 + 0x2c) == 0) {
        __dest = *(void **)(iVar2 + 0x30);
      }
      else {
        memcpy(*(void **)(iVar2 + 0x30),
               (void *)(*(int *)(iVar2 + 0x2c) + (int)*(void **)(iVar2 + 0x30)),__n);
        iVar2 = *(int *)(param_1 + 0x54);
        __dest = *(void **)(iVar2 + 0x30);
        *(undefined4 *)(iVar2 + 0x2c) = 0;
      }
    }
    else {
      iVar5 = *(int *)(param_1 + 0x50);
LAB_0004710c:
      __dest = *(void **)(iVar2 + 0x30);
      if (*(void **)(param_1 + 0x4c) != __dest) {
        memcpy(__dest,*(void **)(param_1 + 0x4c),iVar5 + __n);
        iVar2 = *(int *)(param_1 + 0x54);
        __dest = *(void **)(iVar2 + 0x30);
      }
    }
    *(undefined4 *)(iVar2 + 0x28) = 0;
    *(void **)(param_1 + 0x4c) = __dest;
  }
  piVar3 = __errno_location();
  do {
    b = *(BIO **)(param_1 + 0xc);
    *piVar3 = 0;
    if (b == (BIO *)0x0) {
      ERR_put_error(0x14,0x70,0xd3,"s2_pkt.c",0x180);
      uVar4 = 0xffffffff;
LAB_000470f6:
      *(size_t *)(*(int *)(param_1 + 0x54) + 0x28) = *(int *)(*(int *)(param_1 + 0x54) + 0x28) + __n
      ;
      return uVar4;
    }
    *(undefined4 *)(param_1 + 0x18) = 3;
    iVar6 = *(int *)(*(int *)(param_1 + 0x54) + 0x30);
    uVar4 = BIO_read(b,(void *)(iVar5 + __n + iVar6),param_3 - __n);
    if ((int)uVar4 < 1) goto LAB_000470f6;
    __n = __n + uVar4;
  } while ((int)__n < (int)param_2);
  iVar2 = *(int *)(param_1 + 0x54);
  iVar7 = iVar5;
LAB_00047138:
  if ((int)param_2 < (int)__n) {
    iVar7 = iVar7 + param_2;
    sVar1 = __n - param_2;
  }
  else {
    iVar6 = 0;
    sVar1 = __n;
  }
  if ((int)__n <= (int)param_2) {
    *(int *)(iVar2 + 0x2c) = iVar6;
  }
  if ((int)__n <= (int)param_2) {
    *(int *)(iVar2 + 0x28) = iVar6;
  }
  if ((int)param_2 < (int)__n) {
    *(int *)(iVar2 + 0x2c) = iVar7;
  }
  if ((int)param_2 < (int)__n) {
    *(size_t *)(iVar2 + 0x28) = sVar1;
  }
  uVar4 = param_2;
  if (param_4 != 0) {
    uVar4 = *(int *)(param_1 + 0x50) + param_2;
  }
  *(uint *)(param_1 + 0x50) = uVar4;
  *(undefined4 *)(param_1 + 0x18) = 1;
  return param_2;
}

