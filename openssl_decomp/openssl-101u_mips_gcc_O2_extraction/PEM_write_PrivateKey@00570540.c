
int PEM_write_PrivateKey
              (FILE *fp,EVP_PKEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  BIO *bp;
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  BIO_METHOD *pBVar6;
  int *piVar7;
  EVP_PKEY *name;
  BIO *pBVar8;
  undefined *puVar9;
  EVP_PKEY aEStack_7c [2];
  int *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  bp = (BIO *)(*(code *)PTR_BIO_new_fp_006a7248)(fp,0);
  if (bp == (BIO *)0x0) {
    pBVar8 = (BIO *)&DAT_00000007;
    name = (EVP_PKEY *)0x8b;
    iVar2 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x8b,7,"pem_pkey.c",0xeb);
  }
  else {
    pEVar1 = x->ameth;
    if ((pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0) || (*(int *)(pEVar1 + 0x28) != 0)) {
      iVar2 = PEM_write_bio_PKCS8PrivateKey(bp,x,enc,(char *)kstr,klen,cb,u);
      name = x;
      pBVar8 = (BIO *)enc;
    }
    else {
      name = aEStack_7c;
      (*(code *)PTR_BIO_snprintf_006a6f60)(name,0x50,"%s PRIVATE KEY",*(undefined4 *)(pEVar1 + 0xc))
      ;
      pBVar8 = bp;
      iVar2 = PEM_ASN1_write_bio(PTR_i2d_PrivateKey_006a8eb0,(char *)name,bp,x,enc,kstr,klen,cb,u);
    }
    (*(code *)PTR_BIO_free_006a6e70)(bp);
  }
  if (local_2c == *(int **)puVar3) {
    return iVar2;
  }
  piVar7 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = *piVar7;
  puVar3 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(name,FUN_0066c47c,100);
  if (puVar3 != (undefined *)0x0) {
    if (name != (EVP_PKEY *)0x0) {
      puVar4 = puVar3;
      puVar9 = (undefined *)((int)name + iVar2 + -1);
      do {
        puVar5 = puVar4 + 1;
        *puVar4 = *puVar9;
        puVar4 = puVar5;
        puVar9 = puVar9 + -1;
      } while (puVar5 != puVar3 + (int)name);
    }
    pBVar6 = (BIO_METHOD *)(*(code *)PTR_BN_bin2bn_006a7904)(puVar3,name,0);
    puVar4 = PTR_CRYPTO_free_006a6e88;
    pBVar8->method = pBVar6;
    (*(code *)puVar4)(puVar3);
    if (pBVar8->method != (BIO_METHOD *)0x0) {
      *piVar7 = (int)&name->type + *piVar7;
      return 1;
    }
  }
  return 0;
}

