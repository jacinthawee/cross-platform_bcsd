
undefined4 TS_REQ_set_version(int **param_1,int param_2)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int in_GS_OFFSET;
  undefined auStack_17 [7];
  int iStack_10;
  
  piVar2 = *param_1;
  iStack_10 = *(int *)(in_GS_OFFSET + 0x14);
  piVar2[1] = 2;
  if (*piVar2 < 5) {
    if ((void *)piVar2[2] != (void *)0x0) {
      CRYPTO_free((void *)piVar2[2]);
    }
    puVar3 = (undefined4 *)CRYPTO_malloc(5,"a_int.c",0x15b);
    piVar2[2] = (int)puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      *(undefined *)(puVar3 + 1) = 0;
      goto LAB_0813ad54;
    }
  }
  else {
LAB_0813ad54:
    puVar1 = (undefined *)piVar2[2];
    if (puVar1 != (undefined *)0x0) {
      if (param_2 < 0) {
        param_2 = -param_2;
        piVar2[1] = 0x102;
LAB_0813ad6d:
        auStack_17[2] = (char)param_2;
        if (param_2 >> 8 == 0) {
          iVar7 = 1;
LAB_0813ae2d:
          iVar4 = iVar7 + -1;
          *puVar1 = auStack_17[iVar7 + 1];
          if (iVar7 != 1) {
            iVar6 = iVar7 + -3;
            *(undefined *)(piVar2[2] + 1) = auStack_17[iVar7];
            if (iVar6 != -1) goto LAB_0813adb4;
          }
        }
        else {
          auStack_17[3] = (char)((uint)param_2 >> 8);
          if (param_2 >> 0x10 == 0) {
            iVar7 = 2;
            goto LAB_0813ae2d;
          }
          auStack_17[4] = (undefined)((uint)param_2 >> 0x10);
          if (param_2 >> 0x18 == 0) {
            iVar7 = 3;
            goto LAB_0813ae2d;
          }
          auStack_17[5] = (undefined)((uint)param_2 >> 0x18);
          *puVar1 = auStack_17[5];
          *(undefined *)(piVar2[2] + 1) = auStack_17[4];
          iVar4 = 3;
          iVar6 = 1;
LAB_0813adb4:
          *(undefined *)(piVar2[2] + 2) = auStack_17[iVar6 + 2];
          if (iVar6 != 0) {
            *(char *)(piVar2[2] + 3) = (char)param_2;
          }
        }
        iVar4 = iVar4 + 1;
      }
      else {
        if (param_2 != 0) goto LAB_0813ad6d;
        iVar4 = 0;
      }
      *piVar2 = iVar4;
      uVar5 = 1;
      goto LAB_0813add8;
    }
  }
  ERR_put_error(0xd,0x76,0x41,"a_int.c",0x160);
  uVar5 = 0;
LAB_0813add8:
  if (iStack_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

