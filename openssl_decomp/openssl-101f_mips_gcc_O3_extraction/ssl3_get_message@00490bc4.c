
int ssl3_get_message(undefined4 *param_1,int param_2,int param_3,uint param_4,uint param_5,
                    undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  
  iVar1 = param_1[0x16];
  iVar8 = *(int *)(iVar1 + 0x354);
  if (iVar8 != 0) {
    *(undefined4 *)(iVar1 + 0x354) = 0;
    if (((int)param_4 < 0) || (param_4 == *(uint *)(iVar1 + 0x340))) {
      iVar8 = *(int *)(iVar1 + 0x33c);
      iVar1 = *(int *)(param_1[0xf] + 4);
      *param_6 = 1;
      param_1[0x11] = iVar8;
      param_1[0x10] = iVar1 + 4;
    }
    else {
      uVar3 = 0x1b6;
LAB_00490fb8:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8e,0xf4,"s3_both.c",uVar3);
      uVar3 = 10;
LAB_00490fd0:
      ssl3_send_alert(param_1,2,uVar3);
LAB_00490fe4:
      *param_6 = 0;
      iVar8 = -1;
    }
    return iVar8;
  }
  iVar10 = param_1[0xd];
  iVar4 = param_1[0xf];
  if (iVar10 != param_2) {
    iVar10 = param_1[0x11];
    uVar2 = *(uint *)(iVar1 + 0x33c);
    iVar1 = param_1[0x10];
    iVar8 = iVar10;
LAB_00490c88:
    iVar10 = uVar2 - iVar10;
    if (iVar10 < 1) {
      pcVar6 = *(char **)(iVar4 + 4);
    }
    else {
      do {
        iVar4 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,iVar1 + iVar8,iVar10,0);
        iVar10 = iVar10 - iVar4;
        if (iVar4 < 1) goto LAB_00490cd8;
        iVar8 = iVar4 + param_1[0x11];
        param_1[0x11] = iVar8;
      } while (0 < iVar10);
      pcVar6 = *(char **)(param_1[0xf] + 4);
    }
    if ((*pcVar6 == '\x14') && (iVar1 = param_1[0x16], *(int *)(iVar1 + 0x344) != 0)) {
      if ((param_1[0xd] & 0x1000) == 0) {
        iVar8 = *(int *)(param_1[2] + 100);
        uVar3 = *(undefined4 *)(iVar8 + 0x20);
        uVar7 = *(undefined4 *)(iVar8 + 0x24);
      }
      else {
        iVar8 = *(int *)(param_1[2] + 100);
        uVar3 = *(undefined4 *)(iVar8 + 0x28);
        uVar7 = *(undefined4 *)(iVar8 + 0x2c);
      }
      uVar3 = (**(code **)(iVar8 + 0x14))(param_1,uVar3,uVar7,iVar1 + 0x2b8);
      iVar4 = param_1[0xf];
      iVar8 = param_1[0x11];
      *(undefined4 *)(iVar1 + 0x338) = uVar3;
      pcVar6 = *(char **)(iVar4 + 4);
    }
    ssl3_finish_mac(param_1,pcVar6,iVar8 + 4);
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])
                (0,*param_1,0x16,*(undefined4 *)(param_1[0xf] + 4),param_1[0x11] + 4,param_1,
                 param_1[0x1a]);
    }
    *param_6 = 1;
    return param_1[0x11];
  }
  pbVar9 = *(byte **)(iVar4 + 4);
  uVar2 = param_1[0x11];
joined_r0x00490dc0:
  while (3 < (int)uVar2) {
    uVar2 = param_1[9];
    uVar5 = (uint)*pbVar9;
    if ((uVar2 != 0) || (uVar5 != 0)) {
      if ((int)param_4 < 0) {
        uVar2 = uVar5;
        if (uVar5 == 1) {
          if ((iVar10 == 0x2180) && (param_3 == 0x2181)) {
            ssl3_init_finished_mac(param_1,0x16,0x16,pbVar9);
            uVar2 = (uint)*pbVar9;
          }
          else {
            uVar2 = 1;
          }
        }
      }
      else {
LAB_00490e80:
        uVar2 = uVar5;
        if (param_4 != uVar5) {
          uVar3 = 0x1eb;
          goto LAB_00490fb8;
        }
      }
LAB_00490e88:
      iVar1 = param_1[0x16];
      *(uint *)(iVar1 + 0x340) = uVar2;
      uVar2 = (uint)pbVar9[1] << 0x10 | (uint)pbVar9[2] << 8 | (uint)pbVar9[3];
      if (param_5 < uVar2) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8e,0x98,"s3_both.c",0x200);
        uVar3 = 0x2f;
        goto LAB_00490fd0;
      }
      if (uVar2 != 0) {
        iVar1 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(param_1[0xf],uVar2 + 4);
        if (iVar1 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8e,7,"s3_both.c",0x20b);
          goto LAB_00490fe4;
        }
        iVar1 = param_1[0x16];
      }
      iVar4 = param_1[0xf];
      iVar10 = 0;
      *(uint *)(iVar1 + 0x33c) = uVar2;
      param_1[0xd] = param_3;
      iVar1 = *(int *)(iVar4 + 4);
      param_1[0x11] = 0;
      iVar1 = iVar1 + 4;
      param_1[0x10] = iVar1;
      goto LAB_00490c88;
    }
    if (((pbVar9[1] != 0) || (pbVar9[2] != 0)) || (pbVar9[3] != 0)) {
      if (-1 < (int)param_4) goto LAB_00490e80;
      goto LAB_00490e88;
    }
    param_1[0x11] = 0;
    if ((code *)param_1[0x19] == (code *)0x0) break;
    (*(code *)param_1[0x19])(0,*param_1,0x16,pbVar9,4,param_1,param_1[0x1a]);
    uVar2 = param_1[0x11];
  }
  iVar4 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,pbVar9 + uVar2,4 - uVar2,0);
  if (0 < iVar4) {
    uVar2 = iVar4 + param_1[0x11];
    param_1[0x11] = uVar2;
    goto joined_r0x00490dc0;
  }
LAB_00490cd8:
  param_1[6] = 3;
  *param_6 = 0;
  return iVar4;
}

