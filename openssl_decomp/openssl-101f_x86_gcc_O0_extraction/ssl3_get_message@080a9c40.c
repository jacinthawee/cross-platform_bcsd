
int ssl3_get_message(undefined4 *param_1,int param_2,int param_3,uint param_4,uint param_5,
                    undefined4 *param_6)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  
  iVar11 = param_1[0x16];
  iVar4 = *(int *)(iVar11 + 0x354);
  if (iVar4 == 0) {
    iVar8 = param_1[0xd];
    iVar3 = param_1[0xf];
    if (iVar8 != param_2) {
      iVar9 = param_1[0x11];
      iVar8 = param_1[0x10];
      uVar6 = *(uint *)(iVar11 + 0x33c);
      iVar4 = iVar9;
LAB_080a9cc6:
      iVar9 = uVar6 - iVar9;
      if (0 < iVar9) {
        do {
          iVar4 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,iVar4 + iVar8,iVar9,0);
          if (iVar4 < 1) {
            param_1[6] = 3;
            *param_6 = 0;
            return iVar4;
          }
          iVar9 = iVar9 - iVar4;
          iVar4 = param_1[0x11] + iVar4;
          param_1[0x11] = iVar4;
        } while (0 < iVar9);
        iVar3 = param_1[0xf];
      }
      pcVar5 = *(char **)(iVar3 + 4);
      if ((*pcVar5 == '\x14') && (iVar11 = param_1[0x16], *(int *)(iVar11 + 0x344) != 0)) {
        iVar4 = *(int *)(param_1[2] + 100);
        if ((*(byte *)((int)param_1 + 0x35) & 0x10) == 0) {
          uVar7 = *(undefined4 *)(iVar4 + 0x20);
          uVar10 = *(undefined4 *)(iVar4 + 0x24);
        }
        else {
          uVar7 = *(undefined4 *)(iVar4 + 0x28);
          uVar10 = *(undefined4 *)(iVar4 + 0x2c);
        }
        uVar7 = (**(code **)(iVar4 + 0x14))(param_1,uVar7,uVar10,iVar11 + 0x2b8);
        *(undefined4 *)(iVar11 + 0x338) = uVar7;
        iVar4 = param_1[0x11];
        pcVar5 = *(char **)(param_1[0xf] + 4);
      }
      ssl3_finish_mac(param_1,pcVar5,iVar4 + 4);
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])
                  (0,*param_1,0x16,*(undefined4 *)(param_1[0xf] + 4),param_1[0x11] + 4,param_1,
                   param_1[0x1a]);
      }
      *param_6 = 1;
      return param_1[0x11];
    }
    pbVar2 = *(byte **)(iVar3 + 4);
    uVar6 = param_1[0x11];
joined_r0x080a9d83:
    while (3 < (int)uVar6) {
      uVar6 = param_1[9];
      bVar1 = *pbVar2;
      if ((uVar6 != 0) || (bVar1 != 0)) {
        if ((int)param_4 < 0) {
          if (bVar1 == 1) {
            if ((iVar8 == 0x2180) && (param_3 == 0x2181)) {
              ssl3_init_finished_mac(param_1);
              uVar6 = (uint)*pbVar2;
            }
            else {
              uVar6 = 1;
            }
          }
          else {
            uVar6 = (uint)bVar1;
          }
        }
        else {
LAB_080a9e18:
          uVar6 = (uint)bVar1;
          if (param_4 != uVar6) {
            iVar11 = 0x1eb;
            goto LAB_080a9f3c;
          }
        }
LAB_080a9e25:
        iVar11 = param_1[0x16];
        *(uint *)(iVar11 + 0x340) = uVar6;
        uVar6 = (uint)pbVar2[1] << 0x10 | (uint)pbVar2[2] << 8 | (uint)pbVar2[3];
        if (param_5 < uVar6) {
          ERR_put_error(0x14,0x8e,0x98,"s3_both.c",0x200);
          uVar7 = 0x2f;
          goto LAB_080a9f5a;
        }
        if (uVar6 != 0) {
          iVar11 = BUF_MEM_grow_clean((BUF_MEM *)param_1[0xf],uVar6 + 4);
          if (iVar11 == 0) {
            ERR_put_error(0x14,0x8e,7,"s3_both.c",0x20b);
            goto LAB_080a9f69;
          }
          iVar11 = param_1[0x16];
        }
        *(uint *)(iVar11 + 0x33c) = uVar6;
        iVar9 = 0;
        param_1[0xd] = param_3;
        iVar3 = param_1[0xf];
        iVar8 = *(int *)(iVar3 + 4);
        param_1[0x11] = 0;
        iVar8 = iVar8 + 4;
        param_1[0x10] = iVar8;
        goto LAB_080a9cc6;
      }
      if (((pbVar2[1] != 0) || (pbVar2[2] != 0)) || (pbVar2[3] != 0)) {
        if (-1 < (int)param_4) goto LAB_080a9e18;
        goto LAB_080a9e25;
      }
      param_1[0x11] = 0;
      if ((code *)param_1[0x19] == (code *)0x0) break;
      (*(code *)param_1[0x19])(0,*param_1,0x16,pbVar2,4,param_1,param_1[0x1a]);
      uVar6 = param_1[0x11];
    }
    iVar11 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,pbVar2 + uVar6,4 - uVar6,0);
    if (0 < iVar11) {
      uVar6 = iVar11 + param_1[0x11];
      param_1[0x11] = uVar6;
      goto joined_r0x080a9d83;
    }
    param_1[6] = 3;
    *param_6 = 0;
  }
  else {
    *(undefined4 *)(iVar11 + 0x354) = 0;
    if (((int)param_4 < 0) || (param_4 == *(uint *)(iVar11 + 0x340))) {
      *param_6 = 1;
      param_1[0x10] = *(int *)(param_1[0xf] + 4) + 4;
      iVar11 = *(int *)(iVar11 + 0x33c);
      param_1[0x11] = iVar11;
    }
    else {
      iVar11 = 0x1b6;
LAB_080a9f3c:
      ERR_put_error(0x14,0x8e,0xf4,"s3_both.c",iVar11);
      uVar7 = 10;
LAB_080a9f5a:
      ssl3_send_alert(param_1,2,uVar7);
LAB_080a9f69:
      *param_6 = 0;
      iVar11 = -1;
    }
  }
  return iVar11;
}

