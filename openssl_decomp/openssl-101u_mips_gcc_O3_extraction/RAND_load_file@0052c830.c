
int RAND_load_file(char *file,long max_bytes)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *src;
  undefined *puVar6;
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
  
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  local_4c0 = &_gp;
  local_24 = *(undefined **)PTR___stack_chk_guard_006a9ae8;
  if (file == (char *)0x0) {
LAB_0052c8b4:
    file = unaff_s1;
    max_bytes = (long)unaff_s0;
    puVar2 = (undefined *)0x0;
    puStack_4e4 = unaff_s2;
  }
  else {
    unaff_s2 = auStack_4b4;
    iVar1 = (*(code *)PTR___xstat_006a9a84)(3,file,unaff_s2);
    unaff_s0 = (char *)max_bytes;
    unaff_s1 = file;
    if (((iVar1 < 0) || (RAND_add(unaff_s2,0x90,in_f12_13), max_bytes == 0)) ||
       (iVar1 = (**(code **)(local_4c0 + -0x52e0))(file,&DAT_00633e40), iVar1 == 0))
    goto LAB_0052c8b4;
    if ((local_4a0 & 0x6000) != 0) {
      if (max_bytes == -1) {
        max_bytes = 0x800;
      }
      (**(code **)(local_4c0 + -0x53e0))(iVar1,0,2,0);
    }
    puVar2 = (undefined *)0x0;
    unaff_s3 = auStack_424;
    do {
      while (local_4c8 = iVar1, max_bytes < 1) {
        iVar3 = (**(code **)(local_4c0 + -0x5424))(unaff_s3,0x400,1,0x400);
        if (iVar3 < 1) goto LAB_0052c9ac;
        puVar2 = puVar2 + iVar3;
        RAND_add(unaff_s3,0x400,in_f12_13);
      }
      file = &DAT_00000400;
      if (max_bytes < 0x401) {
        file = (char *)max_bytes;
      }
      iVar3 = (**(code **)(local_4c0 + -0x5424))(unaff_s3,0x400,1,file);
      if (iVar3 < 1) break;
      max_bytes = max_bytes + -(int)file;
      puVar2 = puVar2 + iVar3;
      RAND_add(unaff_s3,(int)file,in_f12_13);
    } while (0 < max_bytes);
LAB_0052c9ac:
    (**(code **)(local_4c0 + -0x5448))(iVar1);
    (**(code **)(local_4c0 + -0x7d6c))(unaff_s3,0x400);
    puStack_4e4 = puVar2;
  }
  if (local_24 == *(undefined **)puVar6) {
    return (int)puVar2;
  }
  pcStack_4dc = RAND_write_file;
  puVar2 = local_24;
  (**(code **)(local_4c0 + -0x5330))();
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  pcStack_4f4 = *(char **)PTR___stack_chk_guard_006a9ae8;
  siz = puVar2;
  pcStack_4ec = (char *)max_bytes;
  pcStack_4e8 = file;
  puStack_4e0 = unaff_s3;
  iVar1 = (*(code *)PTR___xstat_006a9a84)(3,puVar2,auStack_984);
  if ((iVar1 == -1) || (iVar1 = 1, (uStack_970 & 0xb000) != 0x2000)) {
    iVar1 = (*(code *)PTR_open_006a9a3c)(puVar2,0x101,0x180);
    if ((iVar1 == -1) || (iVar3 = (*(code *)PTR_fdopen_006a9b20)(iVar1,&DAT_00632420), iVar3 == 0))
    {
      siz = &DAT_00632420;
      iVar3 = (*(code *)PTR_fopen_006a9b00)(puVar2);
      iVar1 = 0;
      if (iVar3 == 0) goto LAB_0052cb64;
    }
    (*(code *)PTR_chmod_006a9968)(puVar2,0x180);
    iVar4 = RAND_bytes(auStack_8f4,0x400);
    iVar5 = (*(code *)PTR_fwrite_006a9a74)(auStack_8f4,1,0x400,iVar3);
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    (*(code *)PTR_fclose_006a9998)(iVar3);
    siz = (undefined *)0x400;
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_8f4);
    iVar1 = -1;
    if (0 < iVar4) {
      iVar1 = iVar5;
    }
  }
LAB_0052cb64:
  if (pcStack_4f4 == *(char **)puVar6) {
    return iVar1;
  }
  dst = pcStack_4f4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a8914)();
  if ((iVar1 == 0) && (src = (char *)(*(code *)PTR_getenv_006a9a60)("RANDFILE"), src != (char *)0x0)
     ) {
    if ((*src != '\0') &&
       (iVar1 = (*(code *)PTR_strlen_006a9a24)(src), (undefined *)(iVar1 + 1) < siz)) {
      puVar6 = (undefined *)BUF_strlcpy(dst,src,(size_t)siz);
      if (siz <= puVar6) {
        dst = (char *)0x0;
      }
      return (int)dst;
    }
    iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a8914)();
    if (iVar1 == 0) goto LAB_0052cc10;
  }
  else {
    iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a8914)();
    if (iVar1 != 0) goto LAB_0052cc2c;
LAB_0052cc10:
    src = (char *)(*(code *)PTR_getenv_006a9a60)(&DAT_00667da8);
    if (src == (char *)0x0) goto LAB_0052cc2c;
  }
  if ((*src != '\0') &&
     (iVar1 = (*(code *)PTR_strlen_006a9a24)(src), (undefined *)(iVar1 + 6) < siz)) {
    BUF_strlcpy(dst,src,(size_t)siz);
    BUF_strlcat(dst,"/",(size_t)siz);
    BUF_strlcat(dst,".rnd",(size_t)siz);
    return (int)dst;
  }
LAB_0052cc2c:
  *dst = '\0';
  return (int)dst;
}

