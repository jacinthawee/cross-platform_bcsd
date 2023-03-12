
undefined4 asn1_cb(char *param_1,char *param_2,uint *param_3)

{
  char *pcVar1;
  undefined **ppuVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined *puVar7;
  uint uVar8;
  uint *puVar9;
  undefined **ppuVar10;
  uint uVar11;
  char *pcVar12;
  bool bVar13;
  char *local_38;
  char *local_34;
  uint local_30;
  uint local_2c [2];
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  local_38 = param_2;
  if ((int)param_2 < 1) {
    pcVar12 = (char *)0x0;
    local_34 = (char *)0x0;
  }
  else {
    if (*param_1 == ':') {
      local_38 = (char *)0x0;
      pcVar12 = param_1;
    }
    else {
      pcVar1 = param_1 + 1;
      do {
        pcVar12 = pcVar1;
        if (pcVar12 == param_1 + (int)param_2) {
          pcVar12 = (char *)0x0;
          local_34 = (char *)0x0;
          goto LAB_000beaec;
        }
        pcVar1 = pcVar12 + 1;
      } while (*pcVar12 != ':');
      local_38 = pcVar12 + -(int)param_1;
    }
    pcVar12 = pcVar12 + 1;
    local_34 = param_1 + ((int)param_2 - (int)pcVar12);
  }
  param_2 = local_38;
  if (local_38 == (char *)0xffffffff) {
    param_2 = (char *)strlen(param_1);
  }
LAB_000beaec:
  tntmp_16310 = &tnst_16311;
  ppuVar2 = &PTR_s_BOOLEAN_00162550;
LAB_000beb10:
  ppuVar10 = ppuVar2;
  if ((ppuVar10[-2] != param_2) ||
     (iVar3 = strncmp(ppuVar10[-3],param_1,(size_t)param_2), iVar3 != 0)) goto LAB_000beb08;
  puVar7 = ppuVar10[-1];
  if (puVar7 != (undefined *)0xffffffff) {
    uVar4 = (uint)puVar7 & 0x10000;
    if (uVar4 == 0) {
      param_3[2] = (uint)puVar7;
      param_3[4] = (uint)pcVar12;
      if (pcVar12 != (char *)0x0) {
        return 0;
      }
      if (param_1[(int)local_38] != '\0') {
        ERR_put_error(0xd,0xb1,0xbd,"asn1_gen.c",0x149);
        return 0xffffffff;
      }
      return 0;
    }
    switch(puVar7) {
    case (undefined *)0x10001:
      if (*param_3 != 0xffffffff) {
        ERR_put_error(0xd,0xb1,0xb5,"asn1_gen.c",0x154);
        return 0xffffffff;
      }
      iVar3 = parse_tagging(pcVar12,local_34,param_3,param_3 + 1);
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      return 1;
    case (undefined *)0x10002:
      iVar3 = parse_tagging(pcVar12,local_34,&local_30,local_2c);
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      if (*param_3 == 0xffffffff) {
        uVar4 = param_3[0x69];
        if (uVar4 == 0x14) {
          ERR_put_error(0xd,0xb0,0xae,"asn1_gen.c",0x218);
          return 0xffffffff;
        }
        param_3[0x69] = uVar4 + 1;
        param_3[uVar4 * 5 + 5] = local_30;
        param_3[uVar4 * 5 + 6] = local_2c[0];
        param_3[uVar4 * 5 + 8] = 0;
        param_3[uVar4 * 5 + 7] = 1;
        return 1;
      }
      ERR_put_error(0xd,0xb0,0xb3,"asn1_gen.c",0x213);
      return 0xffffffff;
    default:
      return 1;
    case (undefined *)0x10004:
      uVar5 = param_3[0x69];
      uVar8 = *param_3;
      if (uVar5 != 0x14) {
        uVar11 = uVar8 + 1;
        bVar13 = uVar11 == 0;
        param_3[0x69] = uVar5 + 1;
        if (!bVar13) {
          uVar11 = param_3[1];
          uVar4 = 0xffffffff;
        }
        if (bVar13) {
          uVar4 = 3;
          uVar8 = 0;
        }
        else {
          param_3[uVar5 * 5 + 5] = uVar8;
        }
        if (bVar13) {
          param_3[uVar5 * 5 + 5] = uVar4;
        }
        if (!bVar13) {
          param_3[uVar5 * 5 + 6] = uVar11;
        }
        if (bVar13) {
          param_3[uVar5 * 5 + 6] = uVar8;
        }
        else {
          *param_3 = uVar4;
        }
        if (!bVar13) {
          param_3[1] = uVar4;
        }
        param_3[uVar5 * 5 + 7] = 0;
        param_3[uVar5 * 5 + 8] = 1;
        return 1;
      }
      goto LAB_000bee22;
    case (undefined *)0x10005:
      uVar8 = param_3[0x69];
      uVar4 = *param_3;
      if (uVar8 != 0x14) {
        uVar5 = uVar4 + 1;
        bVar13 = uVar5 == 0;
        param_3[0x69] = uVar8 + 1;
        if (!bVar13) {
          ppuVar10 = (undefined **)param_3[1];
          uVar5 = 0xffffffff;
        }
        if (bVar13) {
          uVar5 = 4;
          uVar4 = 0;
        }
        else {
          param_3[uVar8 * 5 + 5] = uVar4;
        }
        if (bVar13) {
          param_3[uVar8 * 5 + 5] = uVar5;
        }
        if (!bVar13) {
          param_3[uVar8 * 5 + 6] = (uint)ppuVar10;
        }
        if (bVar13) {
          param_3[uVar8 * 5 + 6] = uVar4;
        }
        else {
          *param_3 = uVar5;
        }
        if (!bVar13) {
          param_3[1] = uVar5;
        }
        param_3[uVar8 * 5 + 7] = 0;
        param_3[uVar8 * 5 + 8] = 0;
        return 1;
      }
LAB_000bee22:
      ERR_put_error(0xd,0xb0,0xae,"asn1_gen.c",0x218);
      return 0xffffffff;
    case (undefined *)0x10006:
      uVar8 = param_3[0x69];
      uVar4 = *param_3;
      if (uVar8 == 0x14) goto LAB_000bee22;
      param_3[0x69] = uVar8 + 1;
      puVar6 = param_3 + uVar8 * 5;
      puVar9 = puVar6 + 5;
      if (uVar4 == 0xffffffff) {
        puVar6[5] = 0x10;
        puVar6[6] = 0;
        goto LAB_000bec6e;
      }
      break;
    case (undefined *)0x10007:
      uVar8 = param_3[0x69];
      uVar4 = *param_3;
      if (uVar8 == 0x14) goto LAB_000bee22;
      param_3[0x69] = uVar8 + 1;
      puVar6 = param_3 + uVar8 * 5;
      puVar9 = puVar6 + 5;
      if (uVar4 == 0xffffffff) {
        puVar6[5] = 0x11;
        puVar6[6] = 0;
        goto LAB_000bec6e;
      }
      break;
    case (undefined *)0x10008:
      if (pcVar12 == (char *)0x0) {
        ERR_put_error(0xd,0xb1,0xa0,"asn1_gen.c",0x179);
        return 0xffffffff;
      }
      iVar3 = strncmp(pcVar12,"ASCII",5);
      if (iVar3 == 0) {
        param_3[3] = 1;
        return 1;
      }
      iVar3 = strncmp(pcVar12,"UTF8",4);
      if (iVar3 == 0) {
        param_3[3] = 2;
        return 1;
      }
      iVar3 = strncmp(pcVar12,"HEX",3);
      if (iVar3 == 0) {
        param_3[3] = 3;
        return 1;
      }
      iVar3 = strncmp(pcVar12,"BITLIST",7);
      if (iVar3 != 0) {
        ERR_put_error(0xd,0xb1,0xc3,"asn1_gen.c",0x185);
        return 0xffffffff;
      }
      param_3[3] = 4;
      return 1;
    }
    uVar8 = param_3[1];
    puVar6[5] = uVar4;
    puVar9[1] = uVar8;
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
LAB_000bec6e:
    puVar9[2] = 1;
    puVar9[3] = 0;
    return 1;
  }
  goto LAB_000beb4c;
LAB_000beb08:
  ppuVar2 = ppuVar10 + 3;
  tntmp_16310 = ppuVar10;
  if (ppuVar10 + 3 == (undefined **)"Char=") {
LAB_000beb4c:
    ERR_put_error(0xd,0xb1,0xc2,"asn1_gen.c",0x13e);
    ERR_add_error_data(2,&DAT_001627ac,param_1);
    return 0xffffffff;
  }
  goto LAB_000beb10;
}

