
undefined4 ssl_cipher_strength_sort(int **param_1,int **param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *ptr;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  piVar4 = *param_1;
  if (piVar4 == (int *)0x0) {
    iVar9 = 4;
    iVar8 = 0;
  }
  else {
    iVar8 = 0;
    do {
      if ((piVar4[1] != 0) && (iVar8 < *(int *)(*piVar4 + 0x28))) {
        iVar8 = *(int *)(*piVar4 + 0x28);
      }
      piVar4 = (int *)piVar4[3];
    } while (piVar4 != (int *)0x0);
    iVar9 = (iVar8 + 1) * 4;
  }
  ptr = CRYPTO_malloc(iVar9,"ssl_ciph.c",0x431);
  if (ptr == (void *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xe7,0x41,"ssl_ciph.c",0x434);
    return 0;
  }
  (*(code *)PTR_memset_006aab00)(ptr,0,iVar9);
  for (piVar4 = *param_1; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[3]) {
    if (piVar4[1] != 0) {
      piVar5 = (int *)((int)ptr + *(int *)(*piVar4 + 0x28) * 4);
      *piVar5 = *piVar5 + 1;
    }
  }
  piVar4 = (int *)((int)ptr + iVar8 * 4);
  do {
    if (0 < *piVar4) {
      piVar5 = *param_1;
      piVar6 = *param_2;
      if (piVar5 == (int *)0x0) {
        *param_1 = (int *)0x0;
        *param_2 = piVar6;
      }
      else if (piVar5 == piVar6) {
        *param_1 = piVar5;
        *param_2 = piVar5;
      }
      else {
        iVar9 = *(int *)(*piVar5 + 0x28);
        piVar1 = piVar5;
        piVar2 = piVar6;
        piVar3 = (int *)piVar5[3];
        while( true ) {
          if (((iVar9 == iVar8) && (piVar1[1] != 0)) && (piVar1 != piVar2)) {
            iVar9 = piVar1[4];
            if (piVar5 == piVar1) {
              piVar5 = piVar3;
            }
            piVar7 = piVar3;
            if (iVar9 != 0) {
              *(int **)(iVar9 + 0xc) = piVar3;
              piVar7 = (int *)piVar1[3];
            }
            if (piVar7 != (int *)0x0) {
              piVar7[4] = iVar9;
            }
            piVar2[3] = (int)piVar1;
            piVar1[4] = (int)piVar2;
            piVar1[3] = 0;
            piVar2 = piVar1;
          }
          if (piVar6 == piVar1) break;
          iVar9 = *(int *)(*piVar3 + 0x28);
          piVar1 = piVar3;
          piVar3 = (int *)piVar3[3];
        }
        *param_1 = piVar5;
        *param_2 = piVar2;
      }
    }
    iVar8 = iVar8 + -1;
    piVar4 = piVar4 + -1;
  } while (iVar8 != -1);
  CRYPTO_free(ptr);
  return 1;
}

