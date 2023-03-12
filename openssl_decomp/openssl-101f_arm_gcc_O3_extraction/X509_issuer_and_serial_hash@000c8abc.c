
ulong X509_issuer_and_serial_hash(X509 *a)

{
  char *__s;
  EVP_MD *type;
  int iVar1;
  size_t cnt;
  ASN1_INTEGER *pAVar2;
  ulong uVar3;
  EVP_MD_CTX EStack_40;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  int local_14;
  
  local_14 = __TMC_END__;
  EVP_MD_CTX_init(&EStack_40);
  __s = X509_NAME_oneline(a->cert_info->issuer,(char *)0x0,0);
  type = EVP_md5();
  iVar1 = EVP_DigestInit_ex(&EStack_40,type,(ENGINE *)0x0);
  if (iVar1 != 0) {
    cnt = strlen(__s);
    iVar1 = EVP_DigestUpdate(&EStack_40,__s,cnt);
    if (iVar1 != 0) {
      CRYPTO_free(__s);
      pAVar2 = a->cert_info->serialNumber;
      iVar1 = EVP_DigestUpdate(&EStack_40,pAVar2->data,pAVar2->length);
      if ((iVar1 != 0) && (iVar1 = EVP_DigestFinal_ex(&EStack_40,&local_28,(uint *)0x0), iVar1 != 0)
         ) {
        uVar3 = (uint)local_26 << 0x10 | (uint)local_27 << 8 | (uint)local_28 |
                (uint)local_25 << 0x18;
        goto LAB_000c8af4;
      }
    }
  }
  uVar3 = 0;
LAB_000c8af4:
  EVP_MD_CTX_cleanup(&EStack_40);
  if (local_14 == __TMC_END__) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

