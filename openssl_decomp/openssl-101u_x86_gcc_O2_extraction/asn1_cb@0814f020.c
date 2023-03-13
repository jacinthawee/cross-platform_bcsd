
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
  if (param_1 != (char *)0x0) {
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
            goto LAB_0814f086;
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
LAB_0814f086:
    tntmp_13659 = tnst_13660;
    pcVar2 = &DAT_00000004;
LAB_0814f0b4:
    ppcVar1 = (char **)tntmp_13659;
    if ((param_2 == pcVar2) &&
       (iVar3 = strncmp(*(char **)tntmp_13659,param_1,(size_t)param_2), iVar3 == 0)) {
      pcVar2 = ppcVar1[2];
      if (pcVar2 != (char *)0xffffffff) {
        uVar4 = (uint)pcVar2 & 0x10000;
        if (uVar4 == 0) {
          param_3[2] = (int)pcVar2;
          param_3[4] = (int)pcVar6;
          if ((pcVar6 != (char *)0x0) || (param_1[(int)local_34] == '\0')) goto LAB_0814f0ef;
          iVar10 = 0x149;
          iVar3 = 0xbd;
          goto LAB_0814f40e;
        }
        switch(pcVar2) {
        case (char *)0x10001:
          if (*param_3 == -1) {
            iVar3 = parse_tagging(param_3 + 1);
            if (iVar3 != 0) goto switchD_0814f15f_caseD_10003;
            goto LAB_0814f3ae;
          }
          iVar10 = 0x154;
          iVar3 = 0xb5;
          goto LAB_0814f40e;
        case (char *)0x10002:
          iVar3 = parse_tagging(&local_24);
          if (iVar3 == 0) goto LAB_0814f3ae;
          if (*param_3 != -1) {
            ERR_put_error(0xd,0xb0,0xb3,"asn1_gen.c",0x213);
            goto LAB_0814f3ae;
          }
          iVar3 = param_3[0x69];
          if (iVar3 != 0x14) {
            param_3[0x69] = iVar3 + 1;
            uVar4 = 1;
            param_3[iVar3 * 5 + 7] = 1;
            param_3[iVar3 * 5 + 8] = 0;
            param_3[iVar3 * 5 + 5] = local_28;
            param_3[iVar3 * 5 + 6] = local_24;
            goto LAB_0814f0ef;
          }
          ERR_put_error(0xd,0xb0,0xae,"asn1_gen.c",0x218);
          goto LAB_0814f3ae;
        default:
switchD_0814f15f_caseD_10003:
          uVar4 = 1;
          goto LAB_0814f0ef;
        case (char *)0x10004:
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
            goto LAB_0814f0ef;
          }
          break;
        case (char *)0x10005:
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
            goto LAB_0814f0ef;
          }
          break;
        case (char *)0x10006:
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
LAB_0814f288:
            param_3[iVar10 * 5 + 5] = iVar5;
            param_3[iVar10 * 5 + 6] = iVar3;
            uVar4 = 1;
            param_3[iVar10 * 5 + 7] = 1;
            param_3[iVar10 * 5 + 8] = 0;
            goto LAB_0814f0ef;
          }
          break;
        case (char *)0x10007:
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
            goto LAB_0814f288;
          }
          break;
        case (char *)0x10008:
          bVar8 = pcVar6 == (char *)0x0;
          if (!bVar8) {
            iVar3 = 5;
            pcVar2 = pcVar6;
            pcVar7 = "ASCII";
            goto code_r0x0814f1bb;
          }
          iVar10 = 0x179;
          iVar3 = 0xa0;
          goto LAB_0814f40e;
        }
        ERR_put_error(0xd,0xb0,0xae,"asn1_gen.c",0x218);
        uVar4 = 0xffffffff;
        goto LAB_0814f0ef;
      }
    }
    else {
      tntmp_13659 = (undefined1 *)(ppcVar1 + 3);
      if (tntmp_13659 != "cons: ") goto code_r0x0814f0b1;
    }
    ERR_put_error(0xd,0xb1,0xc2,"asn1_gen.c",0x13e);
    ERR_add_error_data(2,&DAT_08228bf5,param_1);
    uVar4 = 0xffffffff;
    goto LAB_0814f0ef;
  }
  goto LAB_0814f3ae;
code_r0x0814f0b1:
  pcVar2 = ppcVar1[4];
  goto LAB_0814f0b4;
  while( true ) {
    iVar3 = iVar3 + -1;
    bVar8 = *pcVar2 == *pcVar7;
    pcVar2 = pcVar2 + (uint)bVar9 * -2 + 1;
    pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
    if (!bVar8) break;
code_r0x0814f1bb:
    if (iVar3 == 0) break;
  }
  if (bVar8) {
    uVar4 = 1;
    param_3[3] = 1;
    goto LAB_0814f0ef;
  }
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
    goto LAB_0814f0ef;
  }
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
    goto LAB_0814f0ef;
  }
  iVar3 = 7;
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
    goto LAB_0814f0ef;
  }
  iVar10 = 0x185;
  iVar3 = 0xc3;
LAB_0814f40e:
  ERR_put_error(0xd,0xb1,iVar3,"asn1_gen.c",iVar10);
LAB_0814f3ae:
  uVar4 = 0xffffffff;
LAB_0814f0ef:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

