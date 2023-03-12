
hostent * GetHostByName(char *param_1)

{
  uint uVar1;
  int iVar2;
  hostent *phVar3;
  size_t sVar4;
  char **ppcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar1 = DAT_00196b5c;
  if ((DAT_00196b5c == 0xffffffff) || (DAT_00196b5c != 0)) {
    iVar9 = strncmp(param_1,&ghbn_cache,0x80);
    if (iVar9 == 0) goto LAB_00036770;
    if (uVar1 <= DAT_00196bf4) goto LAB_000366d0;
    iVar9 = 1;
    uVar1 = DAT_00196bf4;
  }
  else {
LAB_000366d0:
    iVar9 = 0;
  }
  if ((DAT_00196bf4 == 0) || (iVar2 = strncmp(param_1,PTR_DAT_000367e4,0x80), iVar2 != 0)) {
    if (DAT_00196c8c < uVar1) {
      iVar9 = 2;
      uVar1 = DAT_00196c8c;
    }
    if ((DAT_00196c8c == 0) || (iVar2 = strncmp(param_1,PTR_DAT_000367e8,0x80), iVar2 != 0)) {
      if (DAT_00196d24 < uVar1) {
        iVar9 = 3;
      }
      if ((DAT_00196d24 == 0) || (iVar2 = strncmp(param_1,PTR_DAT_000367ec,0x80), iVar2 != 0)) {
        ghbn_miss = ghbn_miss + 1;
        phVar3 = gethostbyname(param_1);
        if (phVar3 == (hostent *)0x0) {
          return (hostent *)0x0;
        }
        sVar4 = strlen(param_1);
        if (0x7f < sVar4) {
          return phVar3;
        }
        iVar9 = iVar9 * 0x98;
        iVar2 = __memcpy_chk(&ghbn_cache + iVar9,param_1,sVar4 + 1,0x80);
        ppcVar5 = phVar3->h_aliases;
        iVar6 = phVar3->h_addrtype;
        iVar7 = phVar3->h_length;
        iVar8 = ghbn_miss + ghbn_hits;
        *(char **)(&DAT_00196b48 + iVar9) = phVar3->h_name;
        *(char ***)(&DAT_00196b4c + iVar9) = ppcVar5;
        *(int *)(&DAT_00196b50 + iVar9) = iVar6;
        *(int *)(&DAT_00196b54 + iVar9) = iVar7;
        *(char ***)(&DAT_00196b58 + iVar9) = phVar3->h_addr_list;
        *(int *)(iVar2 + 0x94) = iVar8;
        return phVar3;
      }
      iVar9 = 3;
    }
    else {
      iVar9 = 2;
    }
  }
  else {
    iVar9 = 1;
  }
LAB_00036770:
  ghbn_hits = ghbn_hits + 1;
  (&DAT_00196b5c)[iVar9 * 0x26] = ghbn_hits + ghbn_miss;
  return (hostent *)(&DAT_00196b48 + iVar9 * 0x98);
}

