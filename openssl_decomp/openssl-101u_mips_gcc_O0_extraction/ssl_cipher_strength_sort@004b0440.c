
undefined4 ssl_cipher_strength_sort(int **param_1,int **param_2)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  void *ptr;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  
  piVar3 = *param_1;
  if (piVar3 == (int *)0x0) {
    iVar10 = 4;
    iVar9 = 0;
  }
  else {
    iVar9 = 0;
    do {
      if ((piVar3[1] != 0) && (iVar9 < *(int *)(*piVar3 + 0x28))) {
        iVar9 = *(int *)(*piVar3 + 0x28);
      }
      piVar3 = (int *)piVar3[3];
    } while (piVar3 != (int *)0x0);
    iVar10 = (iVar9 + 1) * 4;
  }
  ptr = CRYPTO_malloc(iVar10,"ssl_ciph.c",0x445);
  if (ptr == (void *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xe7,0x41,"ssl_ciph.c",0x447);
    return 0;
  }
  (*(code *)PTR_memset_006a99f4)(ptr,0,iVar10);
  for (piVar3 = *param_1; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[3]) {
    if (piVar3[1] != 0) {
      piVar4 = (int *)((int)ptr + *(int *)(*piVar3 + 0x28) * 4);
      *piVar4 = *piVar4 + 1;
    }
  }
  piVar3 = (int *)((int)ptr + iVar9 * 4);
  do {
    if (0 < *piVar3) {
      piVar6 = *param_2;
      piVar4 = *param_1;
      if (piVar6 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = piVar6;
        piVar2 = piVar4;
        piVar8 = piVar4;
        piVar4 = (int *)0x0;
        do {
          if (piVar2 == (int *)0x0) break;
          piVar5 = (int *)piVar2[3];
          if (((*(int *)(*piVar2 + 0x28) == iVar9) && (piVar2[1] != 0)) && (piVar7 != piVar2)) {
            iVar10 = piVar2[4];
            if (piVar2 == piVar8) {
              piVar8 = piVar5;
            }
            piVar4 = piVar5;
            if (iVar10 != 0) {
              *(int **)(iVar10 + 0xc) = piVar5;
              piVar4 = (int *)piVar2[3];
            }
            if (piVar4 != (int *)0x0) {
              piVar4[4] = iVar10;
            }
            piVar7[3] = (int)piVar2;
            piVar2[4] = (int)piVar7;
            piVar2[3] = 0;
            piVar7 = piVar2;
          }
          bVar1 = piVar6 != piVar2;
          piVar4 = piVar8;
          piVar2 = piVar5;
        } while (bVar1);
      }
      *param_1 = piVar4;
      *param_2 = piVar7;
    }
    iVar9 = iVar9 + -1;
    piVar3 = piVar3 + -1;
    if (iVar9 == -1) {
      CRYPTO_free(ptr);
      return 1;
    }
  } while( true );
}

