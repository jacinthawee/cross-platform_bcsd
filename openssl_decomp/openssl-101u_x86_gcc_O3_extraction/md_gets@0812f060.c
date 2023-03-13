
uint md_gets(int param_1,uchar *param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int in_GS_OFFSET;
  uint local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  piVar1 = &(*(EVP_MD_CTX **)(param_1 + 0x20))->digest->md_size;
  uVar2 = 0;
  if ((*piVar1 == param_3 || *piVar1 < param_3) &&
     (iVar3 = EVP_DigestFinal_ex(*(EVP_MD_CTX **)(param_1 + 0x20),param_2,&local_14),
     uVar2 = local_14, iVar3 < 1)) {
    uVar2 = 0xffffffff;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

