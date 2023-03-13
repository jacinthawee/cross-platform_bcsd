
uint __regparm3 int_ctrl_helper_isra_1(uint **param_1,uint param_2,uint param_3,char *param_4)

{
  uint *puVar1;
  uint *puVar2;
  char *pcVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if (param_2 == 0xb) {
    puVar1 = *param_1;
    if (puVar1 == (uint *)0x0) {
      return 0;
    }
    if (*puVar1 != 0) {
      uVar5 = 0;
      if (puVar1[1] != 0) {
        uVar5 = *puVar1;
      }
      return uVar5;
    }
    return 0;
  }
  if (((param_2 & 0xfffffffd) == 0xd) || (param_2 == 0x11)) {
    if (param_4 == (char *)0x0) {
      iVar7 = 0x7b;
      iVar6 = 0x43;
      goto LAB_0811211f;
    }
    if (param_2 == 0xd) {
      puVar1 = *param_1;
      if (((puVar1 != (uint *)0x0) && (*puVar1 != 0)) &&
         (pcVar3 = (char *)puVar1[1], pcVar3 != (char *)0x0)) {
        iVar6 = 0;
        puVar2 = puVar1;
        do {
          iVar7 = strcmp(pcVar3,param_4);
          if (iVar7 == 0) {
            return puVar1[iVar6 * 4];
          }
          iVar6 = iVar6 + 1;
        } while ((puVar2[4] != 0) &&
                (pcVar3 = (char *)puVar2[5], puVar2 = puVar2 + 4, pcVar3 != (char *)0x0));
      }
      iVar7 = 0x83;
      iVar6 = 0x89;
      goto LAB_0811211f;
    }
  }
  puVar1 = *param_1;
  if (puVar1 == (uint *)0x0) {
LAB_08111f72:
    iVar7 = 0x8f;
    iVar6 = 0x8a;
LAB_0811211f:
    ERR_put_error(0x26,0xac,iVar6,"eng_ctrl.c",iVar7);
    return 0xffffffff;
  }
  uVar5 = *puVar1;
  if (((uVar5 == 0) || (puVar1[1] == 0)) || (param_3 <= uVar5)) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    puVar2 = puVar1;
    do {
      uVar5 = puVar2[4];
      iVar6 = iVar6 + 1;
      if ((uVar5 == 0) || (puVar2[5] == 0)) break;
      puVar2 = puVar2 + 4;
    } while (uVar5 < param_3);
  }
  if (param_3 != uVar5) goto LAB_08111f72;
  switch(param_2) {
  case 0xc:
    uVar5 = puVar1[(iVar6 + 1) * 4];
    if (uVar5 == 0) {
      return 0;
    }
    if ((puVar1 + (iVar6 + 1) * 4)[1] != 0) {
      return uVar5;
    }
    return 0;
  default:
    iVar7 = 0xaf;
    iVar6 = 0x6e;
    goto LAB_0811211f;
  case 0xe:
    pcVar3 = (char *)puVar1[iVar6 * 4 + 1];
    break;
  case 0xf:
    pcVar3 = (char *)puVar1[iVar6 * 4 + 1];
    goto LAB_0811206f;
  case 0x10:
    pcVar3 = (char *)puVar1[iVar6 * 4 + 2];
    if (pcVar3 == (char *)0x0) {
      return 0;
    }
    break;
  case 0x11:
    pcVar3 = (char *)puVar1[iVar6 * 4 + 2];
    if (pcVar3 == (char *)0x0) {
      uVar5 = BIO_snprintf(param_4,1,"%s",&DAT_081eca46);
      return uVar5;
    }
LAB_0811206f:
    sVar4 = strlen(pcVar3);
    uVar5 = BIO_snprintf(param_4,sVar4 + 1,"%s",pcVar3);
    return uVar5;
  case 0x12:
    return puVar1[iVar6 * 4 + 3];
  }
  uVar5 = strlen(pcVar3);
  return uVar5;
}

