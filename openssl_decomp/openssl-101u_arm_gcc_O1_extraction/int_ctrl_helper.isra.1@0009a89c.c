
uint int_ctrl_helper_isra_1(uint **param_1,uint param_2,uint param_3,char *param_4)

{
  uint *puVar1;
  int iVar2;
  size_t sVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  
  if (param_2 == 0xb) {
    puVar4 = *param_1;
    if (puVar4 == (uint *)0x0) {
      return 0;
    }
    uVar7 = *puVar4;
    if (uVar7 != 0) {
      if (puVar4[1] == 0) {
        uVar7 = 0;
      }
      return uVar7;
    }
    return 0;
  }
  if ((param_2 & 0xfffffffd) == 0xd) {
    if (param_4 == (char *)0x0) {
LAB_0009a912:
      ERR_put_error(0x26,0xac,0x43,"eng_ctrl.c",0x7b);
      return 0xffffffff;
    }
    if (param_2 == 0xd) {
      puVar4 = *param_1;
      if (((puVar4 != (uint *)0x0) && (uVar7 = *puVar4, uVar7 != 0)) &&
         (iVar8 = 0, puVar5 = puVar4, puVar4[1] != 0)) {
        while( true ) {
          pcVar9 = (char *)puVar5[1];
          iVar2 = strcmp(pcVar9,param_4);
          if (iVar2 == 0) break;
          uVar7 = puVar5[4];
          iVar8 = iVar8 + 1;
          if ((uVar7 == 0) || (puVar1 = puVar5 + 5, puVar5 = puVar5 + 4, *puVar1 == 0))
          goto LAB_0009a97a;
        }
        if ((uVar7 != 0) && (pcVar9 != (char *)0x0)) {
          return puVar4[iVar8 * 4];
        }
      }
LAB_0009a97a:
      ERR_put_error(0x26,0xac,0x89,"eng_ctrl.c",0x83);
      return 0xffffffff;
    }
  }
  else if ((param_2 == 0x11) && (param_4 == (char *)0x0)) goto LAB_0009a912;
  puVar4 = *param_1;
  if (puVar4 == (uint *)0x0) {
LAB_0009a8e8:
    ERR_put_error(0x26,0xac,0x8a,"eng_ctrl.c",0x8f);
    return 0xffffffff;
  }
  uVar6 = *puVar4;
  uVar7 = uVar6;
  if ((uVar6 != 0) && (uVar7 = puVar4[1], puVar4[1] != 0)) {
    if (uVar6 < param_3) {
      uVar7 = 0;
      puVar5 = puVar4;
      do {
        uVar6 = puVar5[4];
        uVar7 = uVar7 + 1;
        if ((uVar6 == 0) || (puVar1 = puVar5 + 5, puVar5 = puVar5 + 4, *puVar1 == 0)) break;
      } while (uVar6 < param_3);
    }
    else {
      uVar7 = 0;
    }
  }
  if (param_3 != uVar6) goto LAB_0009a8e8;
  switch(param_2) {
  case 0xc:
    uVar6 = puVar4[(uVar7 + 1) * 4];
    if ((uVar6 != 0) && (puVar4[(uVar7 + 1) * 4 + 1] == 0)) {
      uVar6 = 0;
    }
    break;
  default:
    ERR_put_error(0x26,0xac,0x6e,"eng_ctrl.c",0xaf);
    uVar6 = 0xffffffff;
    break;
  case 0xe:
    uVar6 = puVar4[uVar7 * 4 + 1];
LAB_0009a9ec:
    uVar7 = (*(code *)PTR_strlen_00189130)(uVar6);
    return uVar7;
  case 0xf:
    pcVar9 = (char *)puVar4[uVar7 * 4 + 1];
    goto LAB_0009a9c4;
  case 0x10:
    uVar6 = puVar4[uVar7 * 4 + 2];
    if (uVar6 != 0) goto LAB_0009a9ec;
    break;
  case 0x11:
    pcVar9 = (char *)puVar4[uVar7 * 4 + 2];
    if (pcVar9 == (char *)0x0) {
      pcVar9 = "";
      sVar3 = 1;
      goto LAB_0009a9d8;
    }
LAB_0009a9c4:
    sVar3 = strlen(pcVar9);
    sVar3 = sVar3 + 1;
LAB_0009a9d8:
    uVar7 = BIO_snprintf(param_4,sVar3,"%s",pcVar9);
    return uVar7;
  case 0x12:
    uVar6 = puVar4[uVar7 * 4 + 3];
  }
  return uVar6;
}

