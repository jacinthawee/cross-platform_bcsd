
uint __regparm3 read_n(int param_1_00,uint param_2,uint param_3,int param_1)

{
  BIO *b;
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  void *__dest;
  size_t __n;
  int local_28;
  
  iVar3 = *(int *)(param_1_00 + 0x54);
  __n = *(size_t *)(iVar3 + 0x28);
  if ((int)param_2 <= (int)__n) {
    if (param_1 == 0) {
      iVar5 = *(int *)(iVar3 + 0x2c);
      *(int *)(param_1_00 + 0x4c) = *(int *)(iVar3 + 0x30) + iVar5;
      uVar4 = param_2;
    }
    else {
      iVar5 = *(int *)(iVar3 + 0x2c);
      uVar4 = *(int *)(param_1_00 + 0x50) + param_2;
    }
    *(uint *)(param_1_00 + 0x50) = uVar4;
    *(size_t *)(iVar3 + 0x28) = __n - param_2;
    *(uint *)(iVar3 + 0x2c) = param_2 + iVar5;
    return param_2;
  }
  if (*(int *)(param_1_00 + 0x60) == 0) {
    param_3 = param_2;
  }
  uVar4 = 0x8001;
  if (param_3 < 0x8002) {
    uVar4 = param_3;
  }
  if (__n == 0) {
    local_28 = *(int *)(param_1_00 + 0x50);
    if ((param_1 != 0) && (local_28 != 0)) goto LAB_08097e4f;
    local_28 = 0;
    *(undefined4 *)(param_1_00 + 0x4c) = *(undefined4 *)(iVar3 + 0x30);
    if (0 < (int)param_2) goto LAB_08097e81;
    if ((int)param_2 < 0) goto LAB_08097f50;
  }
  else {
    if (param_1 == 0) {
      if (*(int *)(iVar3 + 0x2c) == 0) {
        __dest = *(void **)(iVar3 + 0x30);
        local_28 = 0;
      }
      else {
        memcpy(*(void **)(iVar3 + 0x30),
               (void *)(*(int *)(iVar3 + 0x2c) + (int)*(void **)(iVar3 + 0x30)),__n);
        iVar3 = *(int *)(param_1_00 + 0x54);
        local_28 = 0;
        *(undefined4 *)(iVar3 + 0x2c) = 0;
        __dest = *(void **)(iVar3 + 0x30);
      }
    }
    else {
      local_28 = *(int *)(param_1_00 + 0x50);
LAB_08097e4f:
      __dest = *(void **)(iVar3 + 0x30);
      if (*(void **)(param_1_00 + 0x4c) != __dest) {
        memcpy(__dest,*(void **)(param_1_00 + 0x4c),local_28 + __n);
        iVar3 = *(int *)(param_1_00 + 0x54);
        __dest = *(void **)(iVar3 + 0x30);
      }
    }
    *(undefined4 *)(iVar3 + 0x28) = 0;
    *(void **)(param_1_00 + 0x4c) = __dest;
LAB_08097e81:
    piVar1 = __errno_location();
    do {
      b = *(BIO **)(param_1_00 + 0xc);
      *piVar1 = 0;
      if (b == (BIO *)0x0) {
        ERR_put_error(0x14,0x70,0xd3,"s2_pkt.c",0x180);
        uVar2 = 0xffffffff;
LAB_08097ef6:
        piVar1 = (int *)(*(int *)(param_1_00 + 0x54) + 0x28);
        *piVar1 = *piVar1 + __n;
        return uVar2;
      }
      *(undefined4 *)(param_1_00 + 0x18) = 3;
      uVar2 = BIO_read(b,(void *)(local_28 + __n + *(int *)(*(int *)(param_1_00 + 0x54) + 0x30)),
                       uVar4 - __n);
      if ((int)uVar2 < 1) goto LAB_08097ef6;
      __n = __n + uVar2;
    } while ((int)__n < (int)param_2);
    iVar3 = *(int *)(param_1_00 + 0x54);
    if ((int)param_2 < (int)__n) {
LAB_08097f50:
      *(size_t *)(iVar3 + 0x28) = __n - param_2;
      *(uint *)(iVar3 + 0x2c) = local_28 + param_2;
      goto LAB_08097f5e;
    }
  }
  *(undefined4 *)(iVar3 + 0x2c) = 0;
  *(undefined4 *)(iVar3 + 0x28) = 0;
LAB_08097f5e:
  uVar4 = param_2;
  if (param_1 != 0) {
    uVar4 = param_2 + *(int *)(param_1_00 + 0x50);
  }
  *(uint *)(param_1_00 + 0x50) = uVar4;
  *(undefined4 *)(param_1_00 + 0x18) = 1;
  return param_2;
}

