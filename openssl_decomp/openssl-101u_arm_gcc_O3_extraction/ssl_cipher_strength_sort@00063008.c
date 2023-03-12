
undefined4 ssl_cipher_strength_sort(int **param_1,int **param_2)

{
  int *piVar1;
  void *__s;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  size_t __n;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  bool bVar10;
  
  piVar5 = *param_1;
  if (piVar5 == (int *)0x0) {
    __n = 4;
  }
  else {
    piVar6 = (int *)0x0;
    do {
      if ((piVar5[1] != 0) && ((int)piVar6 < (int)*(int **)(*piVar5 + 0x28))) {
        piVar6 = *(int **)(*piVar5 + 0x28);
      }
      piVar5 = (int *)piVar5[3];
    } while (piVar5 != (int *)0x0);
    __n = ((int)piVar6 + 1) * 4;
    piVar5 = piVar6;
  }
  __s = CRYPTO_malloc(__n,"ssl_ciph.c",0x445);
  if (__s == (void *)0x0) {
    ERR_put_error(0x14,0xe7,0x41,"ssl_ciph.c",0x447);
    return 0;
  }
  memset(__s,0,__n);
  for (piVar6 = *param_1; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[3]) {
    if (piVar6[1] != 0) {
      *(int *)((int)__s + *(int *)(*piVar6 + 0x28) * 4) =
           *(int *)((int)__s + *(int *)(*piVar6 + 0x28) * 4) + 1;
    }
  }
  piVar6 = (int *)((int)__s + ((int)piVar5 + 1) * 4);
  do {
    piVar6 = piVar6 + -1;
    if (0 < *piVar6) {
      piVar7 = *param_2;
      piVar2 = *param_1;
      piVar9 = piVar7;
      piVar1 = piVar2;
      if (piVar7 != (int *)0x0) {
        do {
          if (piVar1 == (int *)0x0) break;
          piVar4 = (int *)piVar1[3];
          if (((piVar5 == *(int **)(*piVar1 + 0x28)) && (piVar1[1] != 0)) && (piVar1 != piVar9)) {
            iVar3 = piVar1[4];
            if (piVar1 == piVar2) {
              piVar2 = piVar4;
            }
            piVar8 = piVar4;
            if (iVar3 != 0) {
              *(int **)(iVar3 + 0xc) = piVar4;
              piVar8 = (int *)piVar1[3];
            }
            if (piVar8 != (int *)0x0) {
              piVar8[4] = iVar3;
            }
            piVar9[3] = (int)piVar1;
            piVar1[4] = (int)piVar9;
            piVar1[3] = 0;
            piVar9 = piVar1;
          }
          bVar10 = piVar7 != piVar1;
          piVar1 = piVar4;
        } while (bVar10);
      }
      *param_1 = piVar2;
      *param_2 = piVar9;
    }
    bVar10 = piVar5 == (int *)0x0;
    piVar5 = (int *)((int)piVar5 + -1);
    if (bVar10) {
      CRYPTO_free(__s);
      return 1;
    }
  } while( true );
}

