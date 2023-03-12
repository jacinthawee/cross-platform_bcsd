
ulong X509_subject_name_hash_old(X509 *x)

{
  EVP_MD *type;
  int iVar1;
  BUF_MEM *pBVar2;
  X509_NAME *a;
  ulong uVar3;
  EVP_MD_CTX EStack_40;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  int local_14;
  
  a = x->cert_info->subject;
  local_14 = __TMC_END__;
  i2d_X509_NAME(a,(uchar **)0x0);
  EVP_MD_CTX_init(&EStack_40);
  EVP_MD_CTX_set_flags(&EStack_40,8);
  type = EVP_md5();
  iVar1 = EVP_DigestInit_ex(&EStack_40,type,(ENGINE *)0x0);
  if (((iVar1 == 0) ||
      (pBVar2 = a->bytes, iVar1 = EVP_DigestUpdate(&EStack_40,pBVar2->data,pBVar2->length),
      iVar1 == 0)) || (iVar1 = EVP_DigestFinal_ex(&EStack_40,&local_28,(uint *)0x0), iVar1 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)local_26 << 0x10 | (uint)local_27 << 8 | (uint)local_28 | (uint)local_25 << 0x18;
  }
  EVP_MD_CTX_cleanup(&EStack_40);
  if (local_14 == __TMC_END__) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

