
int ssl3_get_message(undefined4 *param_1,int param_2,int param_3,uint param_4,uint param_5,
                    undefined4 *param_6)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  bool bVar10;
  
  iVar1 = param_1[0x16];
  iVar7 = *(int *)(iVar1 + 0x354);
  if (iVar7 == 0) {
    iVar3 = param_1[0xd];
    iVar6 = param_1[0xf];
    pbVar8 = *(byte **)(iVar6 + 4);
    if (iVar3 != param_2) {
      iVar3 = param_1[0x11];
      uVar9 = *(uint *)(iVar1 + 0x33c);
      iVar1 = param_1[0x10];
      iVar7 = iVar3;
LAB_0004ff26:
      iVar3 = uVar9 - iVar3;
      if (0 < iVar3) {
        do {
          iVar7 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,iVar7 + iVar1,iVar3,0);
          iVar3 = iVar3 - iVar7;
          if (iVar7 < 1) {
            param_1[6] = 3;
            *param_6 = 0;
            return iVar7;
          }
          iVar7 = iVar7 + param_1[0x11];
          param_1[0x11] = iVar7;
        } while (0 < iVar3);
        iVar6 = param_1[0xf];
      }
      pcVar2 = *(char **)(iVar6 + 4);
      if ((*pcVar2 == '\x14') && (iVar1 = param_1[0x16], *(int *)(iVar1 + 0x344) != 0)) {
        bVar10 = (param_1[0xd] & 0x1000) != 0;
        iVar7 = *(int *)(param_1[2] + 100);
        if (bVar10) {
          uVar5 = *(undefined4 *)(iVar7 + 0x28);
        }
        else {
          uVar5 = *(undefined4 *)(iVar7 + 0x20);
        }
        if (bVar10) {
          uVar4 = *(undefined4 *)(iVar7 + 0x2c);
        }
        else {
          uVar4 = *(undefined4 *)(iVar7 + 0x24);
        }
        uVar5 = (**(code **)(iVar7 + 0x14))(param_1,uVar5,uVar4,iVar1 + 0x2b8);
        iVar7 = param_1[0x11];
        pcVar2 = *(char **)(param_1[0xf] + 4);
        *(undefined4 *)(iVar1 + 0x338) = uVar5;
      }
      ssl3_finish_mac(param_1,pcVar2,iVar7 + 4);
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])
                  (0,*param_1,0x16,*(undefined4 *)(param_1[0xf] + 4),param_1[0x11] + 4,param_1,
                   param_1[0x1a]);
      }
      *param_6 = 1;
      return param_1[0x11];
    }
    iVar1 = param_1[0x11];
joined_r0x0004ffbc:
    while (3 < iVar1) {
      iVar1 = param_1[9];
      uVar9 = (uint)*pbVar8;
      if ((iVar1 != 0) || (uVar9 != 0)) {
        if ((int)param_4 < 0) {
          if ((uVar9 == 1) && (param_3 == 0x2181 && iVar3 == 0x2180)) {
            ssl3_init_finished_mac(param_1,0x16,0x16);
            uVar9 = (uint)*pbVar8;
          }
        }
        else {
LAB_00050046:
          if (uVar9 != param_4) {
            iVar7 = 0x1df;
            goto LAB_0005010e;
          }
        }
LAB_0005004c:
        iVar1 = param_1[0x16];
        *(uint *)(iVar1 + 0x340) = uVar9;
        uVar9 = (uint)pbVar8[2] << 8 | (uint)pbVar8[1] << 0x10 | (uint)pbVar8[3];
        if (param_5 < uVar9) {
          ERR_put_error(0x14,0x8e,0x98,"s3_both.c",499);
          uVar5 = 0x2f;
          goto LAB_00050120;
        }
        if (uVar9 != 0) {
          iVar1 = BUF_MEM_grow_clean((BUF_MEM *)param_1[0xf],uVar9 + 0x14);
          if (iVar1 == 0) {
            ERR_put_error(0x14,0x8e,7,"s3_both.c",0x1fd);
            goto LAB_00050128;
          }
          iVar1 = param_1[0x16];
        }
        iVar6 = param_1[0xf];
        *(uint *)(iVar1 + 0x33c) = uVar9;
        iVar3 = 0;
        iVar1 = *(int *)(iVar6 + 4);
        param_1[0xd] = param_3;
        iVar1 = iVar1 + 4;
        param_1[0x11] = 0;
        param_1[0x10] = iVar1;
        goto LAB_0004ff26;
      }
      if (((pbVar8[1] != 0) || (pbVar8[2] != 0)) || (pbVar8[3] != 0)) {
        if (-1 < (int)param_4) goto LAB_00050046;
        goto LAB_0005004c;
      }
      param_1[0x11] = 0;
      if ((code *)param_1[0x19] == (code *)0x0) break;
      (*(code *)param_1[0x19])(0,*param_1,0x16,pbVar8,4,param_1,param_1[0x1a]);
      iVar1 = param_1[0x11];
    }
    iVar1 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,pbVar8 + iVar1,4 - iVar1,0);
    if (0 < iVar1) {
      iVar1 = param_1[0x11] + iVar1;
      param_1[0x11] = iVar1;
      goto joined_r0x0004ffbc;
    }
    param_1[6] = 3;
    *param_6 = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 0x354) = 0;
    if (((int)param_4 < 0) || (*(uint *)(iVar1 + 0x340) == param_4)) {
      iVar1 = *(int *)(iVar1 + 0x33c);
      iVar7 = *(int *)(param_1[0xf] + 4);
      *param_6 = 1;
      param_1[0x11] = iVar1;
      param_1[0xd] = param_3;
      param_1[0x10] = iVar7 + 4;
    }
    else {
      iVar7 = 0x1a9;
LAB_0005010e:
      ERR_put_error(0x14,0x8e,0xf4,"s3_both.c",iVar7);
      uVar5 = 10;
LAB_00050120:
      ssl3_send_alert(param_1,2,uVar5);
LAB_00050128:
      iVar1 = -1;
      *param_6 = 0;
    }
  }
  return iVar1;
}

