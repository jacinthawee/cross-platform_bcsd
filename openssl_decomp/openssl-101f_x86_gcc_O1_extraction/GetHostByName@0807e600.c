
hostent * __regparm3 GetHostByName(char *param_1)

{
  int iVar1;
  hostent *phVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = ghbn_cache._148_4_;
  if ((ghbn_cache._148_4_ == 0xffffffff) || (ghbn_cache._148_4_ != 0)) {
    iVar1 = strncmp(param_1,ghbn_cache,0x80);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_0807e6f8;
    }
  }
  uVar4 = uVar5;
  if (ghbn_cache._300_4_ < uVar5) {
    uVar4 = ghbn_cache._300_4_;
  }
  uVar5 = (uint)(ghbn_cache._300_4_ < uVar5);
  if (ghbn_cache._300_4_ != 0) {
    iVar1 = strncmp(param_1,ghbn_cache + 0x98,0x80);
    if (iVar1 == 0) {
      iVar1 = 1;
      goto LAB_0807e6f8;
    }
  }
  if (ghbn_cache._452_4_ < uVar4) {
    uVar5 = 2;
    uVar4 = ghbn_cache._452_4_;
  }
  if (ghbn_cache._452_4_ != 0) {
    iVar1 = strncmp(param_1,ghbn_cache + 0x130,0x80);
    if (iVar1 == 0) {
      iVar1 = 2;
      goto LAB_0807e6f8;
    }
  }
  if (ghbn_cache._604_4_ < uVar4) {
    uVar5 = 3;
  }
  if (ghbn_cache._604_4_ != 0) {
    iVar1 = strncmp(param_1,ghbn_cache + 0x1c8,0x80);
    if (iVar1 == 0) {
      iVar1 = 3;
LAB_0807e6f8:
      ghbn_hits = ghbn_hits + 1;
      *(int *)(ghbn_cache + iVar1 * 0x98 + 0x94) = ghbn_hits + ghbn_miss;
      return (hostent *)(ghbn_cache + iVar1 * 0x98 + 0x80);
    }
  }
  ghbn_miss = ghbn_miss + 1;
  phVar2 = gethostbyname(param_1);
  if (phVar2 == (hostent *)0x0) {
    phVar2 = (hostent *)0x0;
  }
  else {
    sVar3 = strlen(param_1);
    if (sVar3 < 0x80) {
      iVar6 = uVar5 * 0x98;
      __memcpy_chk(ghbn_cache + iVar6,param_1,sVar3 + 1,0x80);
      iVar1 = ghbn_hits + ghbn_miss;
      *(char **)(ghbn_cache + iVar6 + 0x80) = phVar2->h_name;
      *(char ***)(ghbn_cache + iVar6 + 0x84) = phVar2->h_aliases;
      *(int *)(ghbn_cache + iVar6 + 0x88) = phVar2->h_addrtype;
      *(int *)(ghbn_cache + iVar6 + 0x8c) = phVar2->h_length;
      *(char ***)(ghbn_cache + iVar6 + 0x90) = phVar2->h_addr_list;
      *(int *)(ghbn_cache + iVar6 + 0x94) = iVar1;
    }
  }
  return phVar2;
}

