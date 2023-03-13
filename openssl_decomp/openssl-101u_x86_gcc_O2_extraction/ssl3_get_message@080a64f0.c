
int ssl3_get_message(undefined4 *param_1,int param_2,int param_3,uint param_4,uint param_5,
                    undefined4 *param_6)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  
  iVar11 = param_1[0x16];
  iVar7 = *(int *)(iVar11 + 0x354);
  if (iVar7 != 0) {
    *(undefined4 *)(iVar11 + 0x354) = 0;
    if (((int)param_4 < 0) || (param_4 == *(uint *)(iVar11 + 0x340))) {
      *param_6 = 1;
      param_1[0xd] = param_3;
      param_1[0x10] = *(int *)(param_1[0xf] + 4) + 4;
      iVar11 = *(int *)(iVar11 + 0x33c);
      param_1[0x11] = iVar11;
    }
    else {
      iVar11 = 0x1a9;
LAB_080a67e6:
      ERR_put_error(0x14,0x8e,0xf4,"s3_both.c",iVar11);
      uVar6 = 10;
LAB_080a6804:
      ssl3_send_alert(param_1,2,uVar6);
LAB_080a6813:
      *param_6 = 0;
      iVar11 = -1;
    }
    return iVar11;
  }
  iVar8 = param_1[0xd];
  iVar3 = param_1[0xf];
  if (iVar8 != param_2) {
    iVar9 = param_1[0x11];
    iVar8 = param_1[0x10];
    uVar5 = *(uint *)(iVar11 + 0x33c);
    iVar7 = iVar9;
LAB_080a657e:
    iVar9 = uVar5 - iVar9;
    if (0 < iVar9) {
      do {
        iVar11 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,iVar7 + iVar8,iVar9,0);
        if (iVar11 < 1) goto LAB_080a65b7;
        iVar9 = iVar9 - iVar11;
        iVar7 = param_1[0x11] + iVar11;
        param_1[0x11] = iVar7;
      } while (0 < iVar9);
      iVar3 = param_1[0xf];
    }
    pcVar4 = *(char **)(iVar3 + 4);
    if ((*pcVar4 == '\x14') && (iVar11 = param_1[0x16], *(int *)(iVar11 + 0x344) != 0)) {
      iVar7 = *(int *)(param_1[2] + 100);
      if ((*(byte *)((int)param_1 + 0x35) & 0x10) == 0) {
        uVar6 = *(undefined4 *)(iVar7 + 0x20);
        uVar10 = *(undefined4 *)(iVar7 + 0x24);
      }
      else {
        uVar6 = *(undefined4 *)(iVar7 + 0x28);
        uVar10 = *(undefined4 *)(iVar7 + 0x2c);
      }
      uVar6 = (**(code **)(iVar7 + 0x14))(param_1,uVar6,uVar10,iVar11 + 0x2b8);
      *(undefined4 *)(iVar11 + 0x338) = uVar6;
      iVar7 = param_1[0x11];
      pcVar4 = *(char **)(param_1[0xf] + 4);
    }
    ssl3_finish_mac(param_1,pcVar4,iVar7 + 4);
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])
                (0,*param_1,0x16,*(undefined4 *)(param_1[0xf] + 4),param_1[0x11] + 4,param_1,
                 param_1[0x1a]);
    }
    *param_6 = 1;
    return param_1[0x11];
  }
  pbVar2 = *(byte **)(iVar3 + 4);
  uVar5 = param_1[0x11];
joined_r0x080a6643:
  while (3 < (int)uVar5) {
    uVar5 = param_1[9];
    bVar1 = *pbVar2;
    if ((uVar5 != 0) || (bVar1 != 0)) {
      if ((int)param_4 < 0) {
        if (bVar1 == 1) {
          if ((iVar8 == 0x2180) && (param_3 == 0x2181)) {
            ssl3_init_finished_mac(param_1);
            uVar5 = (uint)*pbVar2;
          }
          else {
            uVar5 = 1;
          }
        }
        else {
          uVar5 = (uint)bVar1;
        }
      }
      else {
LAB_080a66d8:
        uVar5 = (uint)bVar1;
        if (param_4 != uVar5) {
          iVar11 = 0x1df;
          goto LAB_080a67e6;
        }
      }
LAB_080a66e5:
      iVar11 = param_1[0x16];
      *(uint *)(iVar11 + 0x340) = uVar5;
      uVar5 = (uint)pbVar2[1] << 0x10 | (uint)pbVar2[2] << 8 | (uint)pbVar2[3];
      if (param_5 < uVar5) {
        ERR_put_error(0x14,0x8e,0x98,"s3_both.c",499);
        uVar6 = 0x2f;
        goto LAB_080a6804;
      }
      if (uVar5 != 0) {
        iVar11 = BUF_MEM_grow_clean((BUF_MEM *)param_1[0xf],uVar5 + 0x14);
        if (iVar11 == 0) {
          ERR_put_error(0x14,0x8e,7,"s3_both.c",0x1fd);
          goto LAB_080a6813;
        }
        iVar11 = param_1[0x16];
      }
      *(uint *)(iVar11 + 0x33c) = uVar5;
      param_1[0xd] = param_3;
      iVar3 = param_1[0xf];
      iVar8 = *(int *)(iVar3 + 4);
      param_1[0x11] = 0;
      iVar8 = iVar8 + 4;
      iVar9 = 0;
      param_1[0x10] = iVar8;
      goto LAB_080a657e;
    }
    if (((pbVar2[1] != 0) || (pbVar2[2] != 0)) || (pbVar2[3] != 0)) {
      if (-1 < (int)param_4) goto LAB_080a66d8;
      goto LAB_080a66e5;
    }
    param_1[0x11] = 0;
    if ((code *)param_1[0x19] == (code *)0x0) break;
    (*(code *)param_1[0x19])(0,*param_1,0x16,pbVar2,4,param_1,param_1[0x1a]);
    uVar5 = param_1[0x11];
  }
  iVar11 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,pbVar2 + uVar5,4 - uVar5,0);
  if (0 < iVar11) {
    uVar5 = iVar11 + param_1[0x11];
    param_1[0x11] = uVar5;
    goto joined_r0x080a6643;
  }
LAB_080a65b7:
  param_1[6] = 3;
  *param_6 = 0;
  return iVar11;
}

