
void cms_DigestedData_do_final(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  size_t __n;
  int iVar2;
  size_t local_78;
  EVP_MD_CTX EStack_74;
  uchar auStack_5c [64];
  int local_1c;
  
  local_1c = __TMC_END__;
  EVP_MD_CTX_init(&EStack_74);
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = cms_DigestAlgorithm_find_ctx(&EStack_74,param_2,*(undefined4 *)(iVar2 + 4));
  if ((iVar1 == 0) || (iVar1 = EVP_DigestFinal_ex(&EStack_74,auStack_5c,&local_78), iVar1 < 1)) {
    iVar1 = 0;
  }
  else if (param_3 == 0) {
    iVar1 = ASN1_STRING_set(*(ASN1_STRING **)(iVar2 + 0xc),auStack_5c,local_78);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else {
    __n = **(size_t **)(iVar2 + 0xc);
    if (__n == local_78) {
      iVar2 = memcmp(auStack_5c,(void *)(*(size_t **)(iVar2 + 0xc))[2],__n);
      iVar1 = 1;
      if (iVar2 != 0) {
        iVar1 = 0;
        ERR_put_error(0x2e,0x75,0x9e,"cms_dd.c",0x84);
      }
    }
    else {
      iVar1 = 0;
      ERR_put_error(0x2e,0x75,0x79,"cms_dd.c",0x7e);
    }
  }
  EVP_MD_CTX_cleanup(&EStack_74);
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}

