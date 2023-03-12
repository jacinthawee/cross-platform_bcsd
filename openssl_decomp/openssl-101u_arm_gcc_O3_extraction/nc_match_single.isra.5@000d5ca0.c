
undefined4 nc_match_single_isra_5(X509_NAME **param_1,undefined4 *param_2)

{
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  BUF_MEM *pBVar6;
  size_t __n;
  X509_NAME *a;
  char *pcVar7;
  X509_NAME *a_00;
  stack_st_X509_NAME_ENTRY *psVar8;
  
  switch(*param_2) {
  case 1:
    pcVar1 = (char *)((int *)param_2[1])[2];
    pBVar6 = (*param_1)->bytes;
    iVar4 = *(int *)param_2[1];
    psVar8 = (*param_1)->entries;
    pcVar7 = strchr(pcVar1,0x40);
    pcVar2 = strchr((char *)pBVar6,0x40);
    if (pcVar2 == (char *)0x0) {
      return 0x35;
    }
    if (pcVar7 == (char *)0x0) {
      if (*pcVar1 != '.') goto LAB_000d5de8;
      if (iVar4 < (int)psVar8) {
        pBVar6 = (BUF_MEM *)(((int)psVar8 - iVar4) + (int)pBVar6);
        goto LAB_000d5d66;
      }
    }
    else if ((pcVar1 == pcVar7) ||
            (((int)pcVar7 - (int)pcVar1 == (int)pcVar2 - (int)pBVar6 &&
             (iVar4 = strncmp(pcVar1,(char *)pBVar6,(int)pcVar7 - (int)pcVar1), iVar4 == 0)))) {
      pcVar1 = pcVar7 + 1;
LAB_000d5de8:
      iVar4 = strcasecmp(pcVar1,pcVar2 + 1);
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0x2f;
      }
      return uVar5;
    }
    break;
  case 2:
    pcVar1 = (char *)((int *)param_2[1])[2];
    iVar4 = *(int *)param_2[1];
    psVar8 = (*param_1)->entries;
    pBVar6 = (*param_1)->bytes;
    if (*pcVar1 == '\0') {
      return 0;
    }
    if ((((int)psVar8 <= iVar4) ||
        (pBVar6 = (BUF_MEM *)((int)pBVar6 + ((int)psVar8 - iVar4)), *pcVar1 == '.')) ||
       (*(char *)((int)&pBVar6[-1].max + 3) == '.')) {
LAB_000d5d66:
      iVar4 = strcasecmp(pcVar1,(char *)pBVar6);
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0x2f;
      }
      return uVar5;
    }
    break;
  default:
    return 0x33;
  case 4:
    a = *param_1;
    a_00 = (X509_NAME *)param_2[1];
    if (((a->modified != 0) && (iVar4 = i2d_X509_NAME(a,(uchar **)0x0), iVar4 < 0)) ||
       ((a_00->modified != 0 && (iVar4 = i2d_X509_NAME(a_00,(uchar **)0x0), iVar4 < 0)))) {
      return 0x11;
    }
    if (a_00->canon_enclen <= a->canon_enclen) {
      iVar4 = memcmp(a_00->canon_enc,a->canon_enc,a_00->canon_enclen);
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0x2f;
      }
      return uVar5;
    }
    break;
  case 6:
    __n = *(size_t *)param_2[1];
    pcVar7 = (char *)((size_t *)param_2[1])[2];
    pcVar1 = strchr((char *)(*param_1)->bytes,0x3a);
    if (((pcVar1 != (char *)0x0) && (pcVar1[1] == '/')) && (pcVar1[2] == '/')) {
      pcVar1 = pcVar1 + 3;
      pcVar2 = strchr(pcVar1,0x3a);
      if ((pcVar2 == (char *)0x0) && (pcVar2 = strchr(pcVar1,0x2f), pcVar2 == (char *)0x0)) {
        sVar3 = strlen(pcVar1);
      }
      else {
        sVar3 = (int)pcVar2 - (int)pcVar1;
      }
      if (sVar3 != 0) {
        if (*pcVar7 == '.') {
          if ((int)sVar3 <= (int)__n) {
            return 0x2f;
          }
          iVar4 = strncasecmp(pcVar1 + (sVar3 - __n),pcVar7,__n);
          if (iVar4 == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = 0x2f;
          }
          return uVar5;
        }
        if (__n != sVar3) {
          return 0x2f;
        }
        iVar4 = strncasecmp(pcVar1,pcVar7,__n);
        if (iVar4 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = 0x2f;
        }
        return uVar5;
      }
    }
    return 0x35;
  }
  return 0x2f;
}

