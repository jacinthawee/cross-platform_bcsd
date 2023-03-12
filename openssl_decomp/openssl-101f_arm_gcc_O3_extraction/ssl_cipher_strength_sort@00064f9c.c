
undefined4 ssl_cipher_strength_sort(int **param_1,int **param_2)

{
  void *__s;
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  size_t __n;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  bool bVar11;
  
  piVar5 = *param_1;
  if (piVar5 == (int *)0x0) {
    __n = 4;
  }
  else {
    piVar8 = (int *)0x0;
    do {
      if ((piVar5[1] != 0) && ((int)piVar8 < (int)*(int **)(*piVar5 + 0x28))) {
        piVar8 = *(int **)(*piVar5 + 0x28);
      }
      piVar5 = (int *)piVar5[3];
    } while (piVar5 != (int *)0x0);
    __n = ((int)piVar8 + 1) * 4;
    piVar5 = piVar8;
  }
  __s = CRYPTO_malloc(__n,"ssl_ciph.c",0x431);
  if (__s == (void *)0x0) {
    ERR_put_error(0x14,0xe7,0x41,"ssl_ciph.c",0x434);
    return 0;
  }
  memset(__s,0,__n);
  for (piVar8 = *param_1; piVar8 != (int *)0x0; piVar8 = (int *)piVar8[3]) {
    if (piVar8[1] != 0) {
      *(int *)((int)__s + *(int *)(*piVar8 + 0x28) * 4) =
           *(int *)((int)__s + *(int *)(*piVar8 + 0x28) * 4) + 1;
    }
  }
  piVar8 = (int *)((int)__s + ((int)piVar5 + 1) * 4);
  do {
    piVar8 = piVar8 + -1;
    if (0 < *piVar8) {
      piVar2 = *param_1;
      piVar9 = *param_2;
      piVar1 = piVar9;
      piVar3 = piVar2;
      piVar7 = piVar2;
      while (piVar6 = piVar7, piVar3 != (int *)0x0 && piVar9 != piVar3) {
        piVar7 = (int *)piVar6[3];
        piVar3 = piVar6;
        if (((piVar5 == *(int **)(*piVar6 + 0x28)) && (piVar6[1] != 0)) && (piVar6 != piVar1)) {
          iVar4 = piVar6[4];
          if (piVar6 == piVar2) {
            piVar2 = piVar7;
          }
          piVar10 = piVar7;
          if (iVar4 != 0) {
            *(int **)(iVar4 + 0xc) = piVar7;
            piVar10 = (int *)piVar6[3];
          }
          if (piVar10 != (int *)0x0) {
            piVar10[4] = iVar4;
          }
          piVar1[3] = (int)piVar6;
          piVar6[4] = (int)piVar1;
          piVar6[3] = 0;
          piVar1 = piVar6;
        }
      }
      *param_1 = piVar2;
      *param_2 = piVar1;
    }
    bVar11 = piVar5 != (int *)0x0;
    piVar5 = (int *)((int)piVar5 + -1);
  } while (bVar11);
  CRYPTO_free(__s);
  return 1;
}

