
undefined4 tls1_cert_verify_mac(int param_1,int param_2,uchar *param_3)

{
  EVP_MD *md;
  int iVar1;
  EVP_MD_CTX *pEVar2;
  int iVar3;
  uint local_34;
  EVP_MD_CTX EStack_30;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (*(int *)(iVar1 + 0x178) != 0) {
    iVar1 = ssl3_digest_cached_records();
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x58);
  }
  iVar3 = 0;
  do {
    pEVar2 = *(EVP_MD_CTX **)(*(int *)(iVar1 + 0x17c) + iVar3);
    if (pEVar2 != (EVP_MD_CTX *)0x0) {
      md = EVP_MD_CTX_md(pEVar2);
      iVar1 = EVP_MD_type(md);
      if (iVar1 == param_2) {
        pEVar2 = *(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar3);
        if (pEVar2 != (EVP_MD_CTX *)0x0) {
          EVP_MD_CTX_init(&EStack_30);
          EVP_MD_CTX_copy_ex(&EStack_30,pEVar2);
          EVP_DigestFinal_ex(&EStack_30,param_3,&local_34);
          EVP_MD_CTX_cleanup(&EStack_30);
          return local_34;
        }
LAB_00058138:
        ERR_put_error(0x14,0x11e,0x144,"t1_enc.c",0x377);
        return 0;
      }
    }
    iVar3 = iVar3 + 4;
    if (iVar3 == 0x18) goto LAB_00058138;
    iVar1 = *(int *)(param_1 + 0x58);
  } while( true );
}

