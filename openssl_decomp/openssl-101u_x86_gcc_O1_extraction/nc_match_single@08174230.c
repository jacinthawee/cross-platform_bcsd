
undefined4 __regparm3 nc_match_single(int param_1,int *param_2)

{
  char cVar1;
  X509_NAME *a;
  X509_NAME *a_00;
  int *piVar2;
  int *piVar3;
  size_t __n;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  size_t __n_00;
  int iVar9;
  uint uVar10;
  byte bVar11;
  
  bVar11 = 0;
  iVar9 = *param_2;
  if (iVar9 == 2) {
    pcVar5 = (char *)((int *)param_2[1])[2];
    cVar1 = *pcVar5;
    if (cVar1 == '\0') {
      return 0;
    }
    iVar9 = *(int *)param_2[1];
    iVar4 = **(int **)(param_1 + 4);
    pcVar8 = (char *)(*(int **)(param_1 + 4))[2];
    if (((iVar9 < iVar4) && (pcVar8 = pcVar8 + (iVar4 - iVar9), cVar1 != '.')) &&
       (pcVar8[-1] != '.')) {
      return 0x2f;
    }
    iVar9 = strcasecmp(pcVar5,pcVar8);
    goto joined_r0x08174511;
  }
  if (2 < iVar9) {
    if (iVar9 == 4) {
      a = *(X509_NAME **)(param_1 + 4);
      a_00 = (X509_NAME *)param_2[1];
      if (((a->modified != 0) && (iVar9 = i2d_X509_NAME(a,(uchar **)0x0), iVar9 < 0)) ||
         ((a_00->modified != 0 && (iVar9 = i2d_X509_NAME(a_00,(uchar **)0x0), iVar9 < 0)))) {
        return 0x11;
      }
      if (a->canon_enclen < a_00->canon_enclen) {
        return 0x2f;
      }
      iVar9 = memcmp(a_00->canon_enc,a->canon_enc,a_00->canon_enclen);
    }
    else {
      if (iVar9 != 6) {
        return 0x33;
      }
      pcVar5 = strchr(*(char **)(*(int *)(param_1 + 4) + 8),0x3a);
      if (((pcVar5 == (char *)0x0) || (pcVar5[1] != '/')) || (pcVar5[2] != '/')) {
        return 0x35;
      }
      pcVar5 = pcVar5 + 3;
      pcVar8 = strchr(pcVar5,0x3a);
      if ((pcVar8 == (char *)0x0) && (pcVar8 = strchr(pcVar5,0x2f), pcVar8 == (char *)0x0)) {
        uVar10 = 0xffffffff;
        pcVar8 = pcVar5;
        do {
          if (uVar10 == 0) break;
          uVar10 = uVar10 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
        } while (cVar1 != '\0');
        __n_00 = ~uVar10 - 1;
      }
      else {
        __n_00 = (int)pcVar8 - (int)pcVar5;
      }
      if (__n_00 == 0) {
        return 0x35;
      }
      __n = *(size_t *)param_2[1];
      pcVar8 = (char *)((size_t *)param_2[1])[2];
      if (*pcVar8 != '.') {
        if (__n != __n_00) {
          return 0x2f;
        }
        iVar9 = strncasecmp(pcVar5,pcVar8,__n_00);
        if (iVar9 != 0) {
          return 0x2f;
        }
        return 0;
      }
      if ((int)__n_00 <= (int)__n) {
        return 0x2f;
      }
      iVar9 = strncasecmp(pcVar5 + (__n_00 - __n),pcVar8,__n);
    }
    goto joined_r0x08174511;
  }
  if (iVar9 != 1) {
    return 0x33;
  }
  piVar2 = (int *)param_2[1];
  piVar3 = *(int **)(param_1 + 4);
  pcVar5 = (char *)piVar2[2];
  pcVar8 = (char *)piVar3[2];
  pcVar6 = strchr(pcVar5,0x40);
  pcVar7 = strchr(pcVar8,0x40);
  if (pcVar7 == (char *)0x0) {
    return 0x35;
  }
  if (pcVar6 == (char *)0x0) {
    if (*pcVar5 != '.') goto LAB_08174489;
    iVar9 = *piVar3;
    iVar4 = *piVar2;
    if (iVar9 <= iVar4) {
      return 0x2f;
    }
    pcVar7 = pcVar8 + (iVar9 - iVar4);
  }
  else {
    if (pcVar5 != pcVar6) {
      if ((int)pcVar6 - (int)pcVar5 != (int)pcVar7 - (int)pcVar8) {
        return 0x2f;
      }
      iVar9 = strncmp(pcVar5,pcVar8,(int)pcVar6 - (int)pcVar5);
      if (iVar9 != 0) {
        return 0x2f;
      }
    }
    pcVar5 = pcVar6 + 1;
LAB_08174489:
    pcVar7 = pcVar7 + 1;
  }
  iVar9 = strcasecmp(pcVar5,pcVar7);
joined_r0x08174511:
  if (iVar9 == 0) {
    return 0;
  }
  return 0x2f;
}

