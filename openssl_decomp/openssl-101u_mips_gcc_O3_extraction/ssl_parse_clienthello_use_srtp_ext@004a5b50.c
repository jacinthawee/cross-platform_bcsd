
undefined4
ssl_parse_clienthello_use_srtp_ext(int param_1,ushort *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  puVar2 = PTR_sk_num_006a6e2c;
  if (param_3 < 3) {
    uVar7 = 0x161;
    uVar6 = 0x126;
  }
  else {
    uVar10 = (uint)*param_2;
    param_3 = param_3 + -2;
    if ((*param_2 & 1) == 0) {
      if ((int)uVar10 < param_3) {
        if (param_1 == 0) {
          iVar9 = 0;
        }
        else {
          iVar9 = *(int *)(param_1 + 0x17c);
          if ((iVar9 == 0) && (*(int *)(param_1 + 0xe4) != 0)) {
            iVar9 = *(int *)(*(int *)(param_1 + 0xe4) + 0x1b4);
          }
        }
        *(undefined4 *)(param_1 + 0x180) = 0;
        param_2 = param_2 + 1;
        iVar3 = (*(code *)puVar2)(iVar9);
LAB_004a5bec:
        uVar4 = (uint)*(byte *)param_2;
        if (uVar10 != 0) {
          while( true ) {
            bVar1 = *(byte *)((int)param_2 + 1);
            uVar10 = uVar10 - 2;
            param_3 = param_3 + -2;
            param_2 = param_2 + 1;
            if (iVar3 < 1) break;
            iVar8 = 0;
            while (iVar5 = (*(code *)PTR_sk_value_006a6e24)(iVar9,iVar8),
                  ((uint)bVar1 | uVar4 << 8) != *(uint *)(iVar5 + 4)) {
              iVar8 = iVar8 + 1;
              if (iVar8 == iVar3) goto LAB_004a5bec;
            }
            *(int *)(param_1 + 0x180) = iVar5;
            uVar4 = (uint)*(byte *)param_2;
            iVar3 = iVar8;
            if (uVar10 == 0) goto LAB_004a5c50;
          }
          goto LAB_004a5bec;
        }
LAB_004a5c50:
        if (uVar4 == param_3 - 1U) {
          return 0;
        }
        uVar7 = 0x160;
        uVar6 = 0x162;
      }
      else {
        uVar7 = 0x161;
        uVar6 = 0x13a;
      }
    }
    else {
      uVar7 = 0x161;
      uVar6 = 0x132;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x136,uVar7,"d1_srtp.c",uVar6);
  *param_4 = 0x32;
  return 1;
}

