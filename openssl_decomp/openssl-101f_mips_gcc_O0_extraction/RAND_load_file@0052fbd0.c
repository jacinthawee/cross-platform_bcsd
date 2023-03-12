
int RAND_load_file(char *file,long max_bytes)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  char *src;
  undefined *puVar5;
  undefined *siz;
  char *unaff_s0;
  char *dst;
  char *unaff_s1;
  undefined *unaff_s2;
  undefined *unaff_s3;
  double in_f12_13;
  undefined auStack_984 [20];
  uint uStack_970;
  uchar auStack_8f4 [1024];
  char *pcStack_4f4;
  char *pcStack_4ec;
  char *pcStack_4e8;
  undefined *puStack_4e4;
  undefined *puStack_4e0;
  code *pcStack_4dc;
  int local_4c8;
  undefined *local_4c0;
  undefined auStack_4b4 [20];
  uint local_4a0;
  undefined auStack_424 [1024];
  undefined *local_24;
  
  puVar5 = PTR___stack_chk_guard_006aabf0;
  local_4c0 = &_gp;
  local_24 = *(undefined **)PTR___stack_chk_guard_006aabf0;
  if (file == (char *)0x0) {
LAB_0052fc54:
    file = unaff_s1;
    max_bytes = (long)unaff_s0;
    puVar2 = (undefined *)0x0;
    puStack_4e4 = unaff_s2;
  }
  else {
    unaff_s2 = auStack_4b4;
    iVar1 = (*(code *)PTR___xstat_006aab8c)(3,file,unaff_s2);
    unaff_s0 = (char *)max_bytes;
    unaff_s1 = file;
    if (((iVar1 < 0) || (RAND_add(unaff_s2,0x90,in_f12_13), max_bytes == 0)) ||
       (iVar1 = (**(code **)(local_4c0 + -0x52d8))(file,&DAT_006347ac), iVar1 == 0))
    goto LAB_0052fc54;
    if ((local_4a0 & 0x6000) != 0) {
      if (max_bytes == -1) {
        max_bytes = (long)&DAT_00000800;
      }
      (**(code **)(local_4c0 + -0x53d4))(iVar1,0,2,0);
    }
    puVar2 = (undefined *)0x0;
    unaff_s3 = auStack_424;
    do {
      while (local_4c8 = iVar1, max_bytes < 1) {
        iVar3 = (**(code **)(local_4c0 + -0x5418))(unaff_s3,0x400,1,0x400);
        if (iVar3 < 1) goto LAB_0052fd4c;
        puVar2 = puVar2 + iVar3;
        RAND_add(unaff_s3,0x400,in_f12_13);
      }
      file = &DAT_00000400;
      if (max_bytes < 0x401) {
        file = (char *)max_bytes;
      }
      iVar3 = (**(code **)(local_4c0 + -0x5418))(unaff_s3,0x400,1,file);
      if (iVar3 < 1) break;
      max_bytes = max_bytes + -(int)file;
      puVar2 = puVar2 + iVar3;
      RAND_add(unaff_s3,(int)file,in_f12_13);
    } while (0 < max_bytes);
LAB_0052fd4c:
    (**(code **)(local_4c0 + -0x543c))(iVar1);
    (**(code **)(local_4c0 + -0x7d6c))(unaff_s3,0x400);
    puStack_4e4 = puVar2;
  }
  if (local_24 == *(undefined **)puVar5) {
    return (int)puVar2;
  }
  pcStack_4dc = RAND_write_file;
  puVar2 = local_24;
  (**(code **)(local_4c0 + -0x5328))();
  puVar5 = PTR___stack_chk_guard_006aabf0;
  pcStack_4f4 = *(char **)PTR___stack_chk_guard_006aabf0;
  siz = puVar2;
  pcStack_4ec = (char *)max_bytes;
  pcStack_4e8 = file;
  puStack_4e0 = unaff_s3;
  iVar1 = (*(code *)PTR___xstat_006aab8c)(3,puVar2,auStack_984);
  if ((iVar1 == -1) || (iVar1 = 1, (uStack_970 & 0xb000) != 0x2000)) {
    siz = &DAT_00632de8;
    iVar1 = (*(code *)PTR_fopen_006aac08)(puVar2);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      (*(code *)PTR_chmod_006aaa78)(puVar2,0x180);
      iVar3 = RAND_bytes(auStack_8f4,0x400);
      iVar4 = (*(code *)PTR_fwrite_006aab7c)(auStack_8f4,1,0x400,iVar1);
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      (*(code *)PTR_fclose_006aaaa4)(iVar1);
      siz = (undefined *)0x400;
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_8f4);
      iVar1 = -1;
      if (0 < iVar3) {
        iVar1 = iVar4;
      }
    }
  }
  if (pcStack_4f4 == *(char **)puVar5) {
    return iVar1;
  }
  dst = pcStack_4f4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a9a34)();
  if ((iVar1 == 0) && (src = (char *)(*(code *)PTR_getenv_006aab6c)("RANDFILE"), src != (char *)0x0)
     ) {
    if ((*src != '\0') &&
       (iVar1 = (*(code *)PTR_strlen_006aab30)(src), (undefined *)(iVar1 + 1) < siz)) {
      puVar5 = (undefined *)BUF_strlcpy(dst,src,(size_t)siz);
      if (siz <= puVar5) {
        dst = (char *)0x0;
      }
      return (int)dst;
    }
    iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a9a34)();
    if (iVar1 == 0) goto LAB_0052ff6c;
  }
  else {
    iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a9a34)();
    if (iVar1 != 0) goto LAB_0052ff88;
LAB_0052ff6c:
    src = (char *)(*(code *)PTR_getenv_006aab6c)(&DAT_00668868);
    if (src == (char *)0x0) goto LAB_0052ff88;
  }
  if ((*src != '\0') &&
     (iVar1 = (*(code *)PTR_strlen_006aab30)(src), (undefined *)(iVar1 + 6) < siz)) {
    BUF_strlcpy(dst,src,(size_t)siz);
    BUF_strlcat(dst,"/",(size_t)siz);
    BUF_strlcat(dst,".rnd",(size_t)siz);
    return (int)dst;
  }
LAB_0052ff88:
  *dst = '\0';
  return (int)dst;
}

