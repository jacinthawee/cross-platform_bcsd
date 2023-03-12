
int PKCS5_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER *cipher,EVP_MD *md,int en_de)

{
  undefined *puVar1;
  int iVar2;
  ASN1_STRING *pAVar3;
  size_t **ppsVar4;
  size_t sVar5;
  int iVar6;
  void *d;
  long local_dc;
  uchar *local_d8;
  EVP_MD_CTX EStack_d4;
  uchar auStack_bc [16];
  uchar auStack_ac [128];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  EVP_MD_CTX_init(&EStack_d4);
  if ((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) {
LAB_005438e0:
    iVar2 = 0x5d;
  }
  else {
    pAVar3 = (param->value).asn1_string;
    if (pAVar3 == (ASN1_STRING *)0x0) goto LAB_005438e0;
    local_d8 = pAVar3->data;
    ppsVar4 = (size_t **)(*(code *)PTR_d2i_PBEPARAM_006a7204)(0,&local_d8,pAVar3->length);
    if (ppsVar4 != (size_t **)0x0) {
      if ((ASN1_INTEGER *)ppsVar4[1] == (ASN1_INTEGER *)0x0) {
        local_dc = 1;
      }
      else {
        local_dc = ASN1_INTEGER_get((ASN1_INTEGER *)ppsVar4[1]);
      }
      d = (void *)(*ppsVar4)[2];
      sVar5 = **ppsVar4;
      if (pass == (char *)0x0) {
        passlen = 0;
      }
      else if (passlen == -1) {
        passlen = (*(code *)PTR_strlen_006a9a24)(pass);
      }
      iVar2 = EVP_DigestInit_ex(&EStack_d4,md,(ENGINE *)0x0);
      if (iVar2 == 0) goto LAB_005439ec;
      iVar2 = EVP_DigestUpdate(&EStack_d4,pass,passlen);
      if (iVar2 == 0) goto LAB_005439ec;
      iVar2 = EVP_DigestUpdate(&EStack_d4,d,sVar5);
      if (iVar2 == 0) goto LAB_005439ec;
      passlen = (int)auStack_ac;
      (*(code *)PTR_PBEPARAM_free_006a720c)(ppsVar4);
      iVar2 = EVP_DigestFinal_ex(&EStack_d4,(uchar *)passlen,(uint *)0x0);
      if (iVar2 == 0) goto LAB_005439ec;
      sVar5 = EVP_MD_size(md);
      if (-1 < (int)sVar5) {
        iVar2 = 1;
        if (1 < local_dc) {
          do {
            iVar6 = EVP_DigestInit_ex(&EStack_d4,md,(ENGINE *)0x0);
            if (iVar6 == 0) {
              iVar2 = 0;
              goto LAB_005439f0;
            }
            iVar6 = EVP_DigestUpdate(&EStack_d4,(void *)passlen,sVar5);
            if (iVar6 == 0) goto LAB_005439ec;
            iVar6 = EVP_DigestFinal_ex(&EStack_d4,(uchar *)passlen,(uint *)0x0);
            if (iVar6 == 0) goto LAB_005439ec;
            iVar2 = iVar2 + 1;
          } while (local_dc != iVar2);
        }
        iVar2 = EVP_CIPHER_key_length(cipher);
        if (0x40 < iVar2) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)
                    ("p5_crpt.c",0x87,"EVP_CIPHER_key_length(cipher) <= (int)sizeof(md_tmp)");
        }
        md = (EVP_MD *)(auStack_ac + 0x40);
        iVar2 = EVP_CIPHER_key_length(cipher);
        (*(code *)PTR___memcpy_chk_006a9a48)(md,passlen,iVar2,0x40);
        iVar2 = EVP_CIPHER_iv_length(cipher);
        if (0x10 < iVar2) goto LAB_00543c58;
        goto LAB_00543b8c;
      }
      iVar2 = 0;
      goto LAB_0054390c;
    }
    iVar2 = 99;
  }
  ERR_put_error(6,0x75,0x72,"p5_crpt.c",iVar2);
  iVar2 = 0;
LAB_0054390c:
  while (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00543c58:
    (*(code *)PTR_OpenSSLDie_006a7c5c)("p5_crpt.c",0x89,"EVP_CIPHER_iv_length(cipher) <= 16");
LAB_00543b8c:
    iVar2 = EVP_CIPHER_iv_length(cipher);
    iVar6 = EVP_CIPHER_iv_length(cipher);
    (*(code *)PTR___memcpy_chk_006a9a48)(auStack_bc,(uchar *)(passlen + (0x10 - iVar2)),iVar6,0x10);
    iVar2 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,(uchar *)md,auStack_bc,en_de);
    if (iVar2 == 0) {
LAB_005439ec:
      iVar2 = 0;
    }
    else {
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(passlen,0x40);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(md,0x40);
      iVar2 = 1;
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_bc,0x10);
    }
LAB_005439f0:
    EVP_MD_CTX_cleanup(&EStack_d4);
  }
  return iVar2;
}

