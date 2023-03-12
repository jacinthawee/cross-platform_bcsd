
uint asn1_cb(char *param_1,int param_2,int *param_3,char *param_4)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int iVar11;
  int local_3c;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar5 = 0xffffffff;
  if (param_1 == (char *)0x0) goto LAB_00565ea0;
  if (param_2 < 1) {
    pcVar10 = (char *)0x0;
    local_3c = 0;
  }
  else {
    pcVar10 = param_1;
    if (*param_1 == ':') {
      iVar11 = 0;
    }
    else {
      do {
        pcVar10 = pcVar10 + 1;
        if (pcVar10 == param_1 + param_2) {
          pcVar10 = (char *)0x0;
          local_3c = 0;
          iVar11 = param_2;
          goto LAB_00565e20;
        }
        iVar11 = (int)pcVar10 - (int)param_1;
      } while (*pcVar10 != ':');
    }
    pcVar10 = pcVar10 + 1;
    local_3c = param_2 - ((int)pcVar10 - (int)param_1);
    param_2 = iVar11;
  }
  iVar11 = param_2;
  if (param_2 == -1) {
    iVar11 = (*(code *)PTR_strlen_006a9a24)(param_1);
  }
LAB_00565e20:
  tntmp_13679 = tnst_13680;
  puVar9 = (undefined4 *)tnst_13680;
  if (iVar11 == 4) goto LAB_00565e58;
  do {
    do {
      tntmp_13679 = (undefined1 *)(puVar9 + 3);
      if (tntmp_13679 == tag2str_7244) goto LAB_00565ee0;
      piVar1 = puVar9 + 4;
      puVar9 = (undefined4 *)tntmp_13679;
    } while (iVar11 != *piVar1);
LAB_00565e58:
    puVar9 = (undefined4 *)tntmp_13679;
    iVar3 = (*(code *)PTR_strncmp_006a9970)(*(undefined4 *)tntmp_13679,param_1,iVar11);
  } while (iVar3 != 0);
  uVar6 = puVar9[2];
  if (uVar6 == 0xffffffff) {
LAB_00565ee0:
    param_4 = "asn1_gen.c";
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb1,0xc2,"asn1_gen.c",0x13e);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,&DAT_0066a464,param_1);
    uVar5 = 0xffffffff;
    goto LAB_00565ea0;
  }
  uVar5 = uVar6 & 0x10000;
  if (uVar5 == 0) {
    param_3[2] = uVar6;
    param_3[4] = (int)pcVar10;
    if ((pcVar10 == (char *)0x0) && (param_4 = "encrypt", param_1[param_2] != '\0')) {
      uVar8 = 0xbd;
      param_4 = "asn1_gen.c";
      uVar4 = 0x149;
      goto LAB_00566204;
    }
    goto LAB_00565ea0;
  }
  switch(uVar6) {
  case 0x10001:
    if (*param_3 != -1) {
      uVar8 = 0xb5;
      param_4 = "asn1_gen.c";
      uVar4 = 0x154;
      goto LAB_00566204;
    }
    param_4 = (char *)(param_3 + 1);
    iVar11 = parse_tagging(pcVar10,local_3c,param_3,param_4);
    if (iVar11 == 0) goto LAB_005661a8;
  default:
    uVar5 = 1;
    goto LAB_00565ea0;
  case 0x10002:
    param_4 = (char *)&local_30;
    iVar11 = parse_tagging(pcVar10,local_3c,&local_34,param_4);
    if (iVar11 != 0) {
      param_4 = "encrypt";
      if (*param_3 == -1) {
        iVar11 = param_3[0x69];
        if (iVar11 != 0x14) {
          param_3[0x69] = iVar11 + 1;
          uVar5 = 1;
          param_3[iVar11 * 5 + 5] = local_34;
          param_3[iVar11 * 5 + 8] = 0;
          param_3[iVar11 * 5 + 6] = local_30;
          param_3[iVar11 * 5 + 7] = 1;
          goto LAB_00565ea0;
        }
        uVar8 = 0xae;
        uVar4 = 0x218;
      }
      else {
        uVar8 = 0xb3;
        uVar4 = 0x213;
      }
      param_4 = "asn1_gen.c";
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb0,uVar8,"asn1_gen.c",uVar4);
    }
LAB_005661a8:
    uVar5 = 0xffffffff;
    goto LAB_00565ea0;
  case 0x10004:
    iVar11 = param_3[0x69];
    iVar7 = *param_3;
    if (iVar11 != 0x14) {
      param_3[0x69] = iVar11 + 1;
      if (iVar7 == -1) {
        iVar7 = 3;
      }
      else {
        iVar3 = param_3[1];
        *param_3 = -1;
        param_3[1] = -1;
      }
      uVar5 = 1;
      param_3[iVar11 * 5 + 6] = iVar3;
      param_3[iVar11 * 5 + 5] = iVar7;
      param_3[iVar11 * 5 + 7] = 0;
      param_3[iVar11 * 5 + 8] = 1;
      goto LAB_00565ea0;
    }
    break;
  case 0x10005:
    iVar11 = param_3[0x69];
    iVar7 = *param_3;
    if (iVar11 != 0x14) {
      param_3[0x69] = iVar11 + 1;
      if (iVar7 == -1) {
        iVar7 = 4;
      }
      else {
        iVar3 = param_3[1];
        *param_3 = -1;
        param_3[1] = -1;
      }
      uVar5 = 1;
      param_3[iVar11 * 5 + 6] = iVar3;
      param_3[iVar11 * 5 + 5] = iVar7;
      param_3[iVar11 * 5 + 7] = 0;
      param_3[iVar11 * 5 + 8] = 0;
      goto LAB_00565ea0;
    }
    break;
  case 0x10006:
    iVar11 = param_3[0x69];
    iVar7 = *param_3;
    if (iVar11 != 0x14) {
      param_3[0x69] = iVar11 + 1;
      if (iVar7 == -1) {
        iVar7 = 0x10;
      }
      else {
LAB_0056604c:
        iVar3 = param_3[1];
        *param_3 = -1;
        param_3[1] = -1;
      }
LAB_00566058:
      uVar5 = 1;
      param_3[iVar11 * 5 + 6] = iVar3;
      param_3[iVar11 * 5 + 5] = iVar7;
      param_3[iVar11 * 5 + 8] = 0;
      param_3[iVar11 * 5 + 7] = 1;
      goto LAB_00565ea0;
    }
    break;
  case 0x10007:
    iVar11 = param_3[0x69];
    iVar7 = *param_3;
    if (iVar11 != 0x14) {
      param_3[0x69] = iVar11 + 1;
      if (iVar7 != -1) goto LAB_0056604c;
      iVar7 = 0x11;
      goto LAB_00566058;
    }
    break;
  case 0x10008:
    param_4 = "encrypt";
    if (pcVar10 == (char *)0x0) goto LAB_00566334;
    iVar11 = (*(code *)PTR_strncmp_006a9970)(pcVar10,"ASCII",5);
    if (iVar11 == 0) {
      uVar5 = 1;
      param_3[3] = 1;
    }
    else {
      iVar11 = (*(code *)PTR_strncmp_006a9970)(pcVar10,&DAT_0066a474,4);
      if (iVar11 == 0) {
        uVar5 = 1;
        param_3[3] = 2;
      }
      else {
        iVar11 = (*(code *)PTR_strncmp_006a9970)(pcVar10,&DAT_0066a47c,3);
        if (iVar11 == 0) {
          uVar5 = 1;
          param_3[3] = 3;
        }
        else {
          iVar11 = (*(code *)PTR_strncmp_006a9970)(pcVar10,"BITLIST",7);
          if (iVar11 != 0) {
            uVar8 = 0xc3;
            param_4 = "asn1_gen.c";
            uVar4 = 0x185;
            goto LAB_00566204;
          }
          uVar5 = 1;
          param_3[3] = 4;
        }
      }
    }
    goto LAB_00565ea0;
  }
  param_4 = "asn1_gen.c";
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb0,0xae,"asn1_gen.c",0x218);
  uVar5 = 0xffffffff;
LAB_00565ea0:
  while (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00566334:
    uVar8 = 0xa0;
    param_4 = (char *)((int)param_4 + -0x5bb8);
    uVar4 = 0x179;
LAB_00566204:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb1,uVar8,param_4,uVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

