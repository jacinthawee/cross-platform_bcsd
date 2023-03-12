
undefined4 __regparm3 ssl_cipher_strength_sort(int **param_1,int **param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *__s;
  int *piVar4;
  int *piVar5;
  size_t __n;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *local_2c;
  
  piVar3 = *param_1;
  if (piVar3 == (int *)0x0) {
    __n = 4;
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    do {
      if ((piVar3[1] != 0) && (iVar6 < *(int *)(*piVar3 + 0x28))) {
        iVar6 = *(int *)(*piVar3 + 0x28);
      }
      piVar3 = (int *)piVar3[3];
    } while (piVar3 != (int *)0x0);
    __n = iVar6 * 4 + 4;
  }
  __s = CRYPTO_malloc(__n,"ssl_ciph.c",0x431);
  if (__s != (void *)0x0) {
    memset(__s,0,__n);
    for (piVar3 = *param_1; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[3]) {
      if (piVar3[1] != 0) {
        piVar1 = (int *)((int)__s + *(int *)(*piVar3 + 0x28) * 4);
        *piVar1 = *piVar1 + 1;
      }
    }
    do {
      if (0 < *(int *)((int)__s + iVar6 * 4)) {
        local_2c = *param_1;
        piVar3 = *param_2;
        piVar1 = local_2c;
        piVar5 = piVar3;
        piVar7 = local_2c;
        while ((piVar4 = piVar1, piVar7 != (int *)0x0 && (piVar3 != piVar7))) {
          piVar1 = (int *)piVar4[3];
          piVar7 = piVar4;
          if ((*(int *)(*piVar4 + 0x28) == iVar6) && ((piVar4[1] != 0 && (piVar4 != piVar5)))) {
            iVar2 = piVar4[4];
            if (piVar4 == local_2c) {
              local_2c = piVar1;
            }
            piVar8 = piVar1;
            if (iVar2 != 0) {
              *(int **)(iVar2 + 0xc) = piVar1;
              piVar8 = (int *)piVar4[3];
            }
            if (piVar8 != (int *)0x0) {
              piVar8[4] = iVar2;
            }
            piVar5[3] = (int)piVar4;
            piVar4[4] = (int)piVar5;
            piVar4[3] = 0;
            piVar5 = piVar4;
          }
        }
        *param_1 = local_2c;
        *param_2 = piVar5;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != -1);
    CRYPTO_free(__s);
    return 1;
  }
  ERR_put_error(0x14,0xe7,0x41,"ssl_ciph.c",0x434);
  return 0;
}

