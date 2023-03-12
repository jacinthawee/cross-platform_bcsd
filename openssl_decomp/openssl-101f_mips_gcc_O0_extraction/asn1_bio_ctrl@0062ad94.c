
int asn1_bio_ctrl(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  
  piVar3 = *(int **)(param_1 + 0x20);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  if (param_2 == 0x97) {
    iVar1 = param_4[1];
    piVar3[10] = *param_4;
    piVar3[0xb] = iVar1;
    return 1;
  }
  if (param_2 < 0x98) {
    if (param_2 == 0x95) {
      iVar1 = param_4[1];
      piVar3[8] = *param_4;
      piVar3[9] = iVar1;
      return 1;
    }
    if (0x95 < param_2) {
      iVar1 = piVar3[9];
      *param_4 = piVar3[8];
      param_4[1] = iVar1;
      return 1;
    }
    if (param_2 == 0xb) {
      if (*(int *)(param_1 + 0x24) == 0) {
        return 0;
      }
      iVar1 = *piVar3;
      if (iVar1 == 2) {
        if (((code *)piVar3[10] != (code *)0x0) &&
           (iVar1 = (*(code *)piVar3[10])(param_1,piVar3 + 0xc,piVar3 + 0xd,piVar3 + 0xf),
           iVar1 == 0)) goto LAB_0062ae74;
        iVar1 = 6;
        if (0 < piVar3[0xd]) {
          iVar1 = 5;
        }
        *piVar3 = iVar1;
      }
      if (iVar1 == 5) {
        if (piVar3[0xd] < 1) {
LAB_0062ae74:
          (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
          return 0;
        }
        pcVar4 = (code *)piVar3[0xb];
        iVar1 = piVar3[0xe];
        while( true ) {
          iVar1 = (*(code *)PTR_BIO_write_006a7f14)
                            (*(undefined4 *)(param_1 + 0x24),piVar3[0xc] + iVar1);
          if (iVar1 < 1) {
            return iVar1;
          }
          iVar2 = piVar3[0xd];
          piVar3[0xd] = iVar2 - iVar1;
          if (iVar2 - iVar1 < 1) break;
          iVar1 = iVar1 + piVar3[0xe];
          piVar3[0xe] = iVar1;
        }
        if (pcVar4 != (code *)0x0) {
          (*pcVar4)(param_1,piVar3 + 0xc,piVar3 + 0xd,piVar3 + 0xf);
        }
        piVar3[0xe] = 0;
        *piVar3 = 6;
      }
      else if (iVar1 != 6) goto LAB_0062ae74;
      iVar1 = *(int *)(param_1 + 0x24);
      param_2 = 0xb;
      goto LAB_0062afb0;
    }
  }
  else {
    if (param_2 == 0x99) {
      piVar3[0xf] = (int)param_4;
      return 1;
    }
    if (param_2 < 0x99) {
      iVar1 = piVar3[0xb];
      *param_4 = piVar3[10];
      param_4[1] = iVar1;
      return 1;
    }
    if (param_2 == 0x9a) {
      *param_4 = piVar3[0xf];
      return 1;
    }
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 == 0) {
    return 0;
  }
LAB_0062afb0:
                    /* WARNING: Could not recover jumptable at 0x0062afc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar1,param_2,param_3,param_4);
  return iVar1;
}

