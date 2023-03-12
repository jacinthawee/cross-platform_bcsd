
uint asn1_cb(char *param_1,char *param_2,int *param_3)

{
  char **ppcVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int in_GS_OFFSET;
  bool bVar8;
  byte bVar9;
  int iVar10;
  char *local_34;
  int local_28;
  int local_24;
  int local_20;
  
  bVar9 = 0;
  local_34 = param_2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((int)param_2 < 1) {
    pcVar6 = (char *)0x0;
  }
  else {
    pcVar6 = param_1;
    if (*param_1 == ':') {
      local_34 = (char *)0x0;
    }
    else {
      do {
        pcVar6 = pcVar6 + 1;
        if (pcVar6 == param_1 + (int)param_2) {
          pcVar6 = (char *)0x0;
          goto LAB_08150d5e;
        }
      } while (*pcVar6 != ':');
      local_34 = pcVar6 + -(int)param_1;
    }
    pcVar6 = pcVar6 + 1;
  }
  param_2 = local_34;
  if (local_34 == (char *)0xffffffff) {
    param_2 = (char *)strlen(param_1);
  }
LAB_08150d5e:
  tntmp_13632 = tnst_13633;
  pcVar2 = &DAT_00000004;
LAB_08150d8c:
  ppcVar1 = (char **)tntmp_13632;
  if ((param_2 == pcVar2) &&
     (iVar3 = strncmp(*(char **)tntmp_13632,param_1,(size_t)param_2), iVar3 == 0)) {
    pcVar2 = ppcVar1[2];
    if (pcVar2 != (char *)0xffffffff) {
      uVar4 = (uint)pcVar2 & 0x10000;
      if (uVar4 == 0) {
        param_3[2] = (int)pcVar2;
        param_3[4] = (int)pcVar6;
        if ((pcVar6 != (char *)0x0) || (param_1[(int)local_34] == '\0')) goto LAB_08150dc7;
        iVar10 = 0x13c;
        iVar3 = 0xbd;
        goto LAB_081510d6;
      }
      bVar8 = pcVar2 + -0x10001 == (char *)0x7;
      switch(pcVar2 + -0x10001) {
      case (char *)0x0:
        if (*param_3 == -1) {
          iVar3 = parse_tagging(param_3 + 1);
          if (iVar3 != 0) goto switchD_08150e2f_caseD_2;
          goto LAB_08151076;
        }
        iVar10 = 0x149;
        iVar3 = 0xb5;
        goto LAB_081510d6;
      case (char *)0x1:
        iVar3 = parse_tagging(&local_24);
        if (iVar3 == 0) goto LAB_08151076;
        if (*param_3 != -1) {
          ERR_put_error(0xd,0xb0,0xb3,"asn1_gen.c",0x206);
          goto LAB_08151076;
        }
        iVar3 = param_3[0x69];
        if (iVar3 != 0x14) {
          param_3[0x69] = iVar3 + 1;
          uVar4 = 1;
          param_3[iVar3 * 5 + 7] = 1;
          param_3[iVar3 * 5 + 8] = 0;
          param_3[iVar3 * 5 + 5] = local_28;
          param_3[iVar3 * 5 + 6] = local_24;
          goto LAB_08150dc7;
        }
        ERR_put_error(0xd,0xb0,0xae,"asn1_gen.c",0x20c);
        goto LAB_08151076;
      default:
switchD_08150e2f_caseD_2:
        uVar4 = 1;
        goto LAB_08150dc7;
      case (char *)0x3:
        iVar10 = param_3[0x69];
        iVar5 = *param_3;
        if (iVar10 != 0x14) {
          param_3[0x69] = iVar10 + 1;
          if (iVar5 == -1) {
            iVar5 = 3;
          }
          else {
            iVar3 = param_3[1];
            *param_3 = -1;
            param_3[1] = -1;
          }
          param_3[iVar10 * 5 + 5] = iVar5;
          param_3[iVar10 * 5 + 6] = iVar3;
          uVar4 = 1;
          param_3[iVar10 * 5 + 7] = 0;
          param_3[iVar10 * 5 + 8] = 1;
          goto LAB_08150dc7;
        }
        break;
      case (char *)0x4:
        iVar10 = param_3[0x69];
        iVar5 = *param_3;
        if (iVar10 != 0x14) {
          param_3[0x69] = iVar10 + 1;
          if (iVar5 == -1) {
            iVar5 = 4;
          }
          else {
            iVar3 = param_3[1];
            *param_3 = -1;
            param_3[1] = -1;
          }
          param_3[iVar10 * 5 + 5] = iVar5;
          param_3[iVar10 * 5 + 6] = iVar3;
          uVar4 = 1;
          param_3[iVar10 * 5 + 7] = 0;
          param_3[iVar10 * 5 + 8] = 0;
          goto LAB_08150dc7;
        }
        break;
      case (char *)0x5:
        iVar5 = *param_3;
        iVar10 = param_3[0x69];
        if (iVar10 != 0x14) {
          param_3[0x69] = iVar10 + 1;
          if (iVar5 == -1) {
            iVar5 = 0x10;
          }
          else {
            iVar3 = param_3[1];
            *param_3 = -1;
            param_3[1] = -1;
          }
LAB_08150f50:
          param_3[iVar10 * 5 + 5] = iVar5;
          param_3[iVar10 * 5 + 6] = iVar3;
          uVar4 = 1;
          param_3[iVar10 * 5 + 7] = 1;
          param_3[iVar10 * 5 + 8] = 0;
          goto LAB_08150dc7;
        }
        break;
      case (char *)0x6:
        iVar10 = param_3[0x69];
        iVar5 = *param_3;
        if (iVar10 != 0x14) {
          param_3[0x69] = iVar10 + 1;
          if (iVar5 == -1) {
            iVar5 = 0x11;
          }
          else {
            iVar3 = param_3[1];
            *param_3 = -1;
            param_3[1] = -1;
          }
          goto LAB_08150f50;
        }
        break;
      case (char *)0x7:
        iVar3 = 5;
        pcVar2 = pcVar6;
        pcVar7 = "ASCII";
        goto code_r0x08150e83;
      }
      ERR_put_error(0xd,0xb0,0xae,"asn1_gen.c",0x20c);
      uVar4 = 0xffffffff;
      goto LAB_08150dc7;
    }
  }
  else {
    tntmp_13632 = (undefined1 *)(ppcVar1 + 3);
    if (tntmp_13632 != "cons: ") goto code_r0x08150d89;
  }
  ERR_put_error(0xd,0xb1,0xc2,"asn1_gen.c",0x12f);
  ERR_add_error_data(2,&DAT_0822884d,param_1);
  uVar4 = 0xffffffff;
  goto LAB_08150dc7;
code_r0x08150d89:
  pcVar2 = ppcVar1[4];
  goto LAB_08150d8c;
  while( true ) {
    iVar3 = iVar3 + -1;
    bVar8 = *pcVar2 == *pcVar7;
    pcVar2 = pcVar2 + (uint)bVar9 * -2 + 1;
    pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
    if (!bVar8) break;
code_r0x08150e83:
    if (iVar3 == 0) break;
  }
  if (bVar8) {
    uVar4 = 1;
    param_3[3] = 1;
  }
  else {
    iVar3 = 4;
    pcVar2 = pcVar6;
    pcVar7 = "UTF8";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar8 = *pcVar2 == *pcVar7;
      pcVar2 = pcVar2 + (uint)bVar9 * -2 + 1;
      pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
    } while (bVar8);
    if (bVar8) {
      uVar4 = 1;
      param_3[3] = 2;
    }
    else {
      iVar3 = 3;
      pcVar2 = pcVar6;
      pcVar7 = "HEX";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar8 = *pcVar2 == *pcVar7;
        pcVar2 = pcVar2 + (uint)bVar9 * -2 + 1;
        pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
      } while (bVar8);
      if (bVar8) {
        uVar4 = 1;
        param_3[3] = 3;
      }
      else {
        iVar3 = 3;
        pcVar2 = "BITLIST";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar8 = *pcVar6 == *pcVar2;
          pcVar6 = pcVar6 + (uint)bVar9 * -2 + 1;
          pcVar2 = pcVar2 + (uint)bVar9 * -2 + 1;
        } while (bVar8);
        if (bVar8) {
          uVar4 = 1;
          param_3[3] = 4;
        }
        else {
          iVar10 = 0x177;
          iVar3 = 0xc3;
LAB_081510d6:
          ERR_put_error(0xd,0xb1,iVar3,"asn1_gen.c",iVar10);
LAB_08151076:
          uVar4 = 0xffffffff;
        }
      }
    }
  }
LAB_08150dc7:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

