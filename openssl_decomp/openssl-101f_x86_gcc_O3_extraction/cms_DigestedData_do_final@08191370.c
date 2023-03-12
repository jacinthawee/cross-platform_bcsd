
bool cms_DigestedData_do_final(int param_1,undefined4 param_2,int param_3)

{
  size_t __n;
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  bool bVar3;
  size_t local_6c;
  EVP_MD_CTX local_68;
  uchar local_50 [64];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_68);
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = cms_DigestAlgorithm_find_ctx(&local_68,param_2,*(undefined4 *)(iVar2 + 4));
  if (iVar1 != 0) {
    iVar1 = EVP_DigestFinal_ex(&local_68,local_50,&local_6c);
    if (0 < iVar1) {
      if (param_3 == 0) {
        iVar2 = ASN1_STRING_set(*(ASN1_STRING **)(iVar2 + 0xc),local_50,local_6c);
        bVar3 = iVar2 != 0;
        goto LAB_081913b0;
      }
      __n = **(size_t **)(iVar2 + 0xc);
      if (__n == local_6c) {
        bVar3 = true;
        iVar2 = memcmp(local_50,(void *)(*(size_t **)(iVar2 + 0xc))[2],__n);
        if (iVar2 == 0) goto LAB_081913b0;
        iVar1 = 0x84;
        iVar2 = 0x9e;
      }
      else {
        iVar1 = 0x7e;
        iVar2 = 0x79;
      }
      ERR_put_error(0x2e,0x75,iVar2,"cms_dd.c",iVar1);
    }
  }
  bVar3 = false;
LAB_081913b0:
  EVP_MD_CTX_cleanup(&local_68);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

