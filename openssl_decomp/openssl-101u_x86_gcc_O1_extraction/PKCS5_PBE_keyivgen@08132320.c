
int PKCS5_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER *cipher,EVP_MD *md,int en_de)

{
  ASN1_STRING *pAVar1;
  uchar *d;
  PBEPARAM *a;
  size_t sVar2;
  int iVar3;
  int in_GS_OFFSET;
  int iVar4;
  long local_d8;
  uchar *local_cc;
  EVP_MD_CTX local_c8;
  uchar local_b0 [16];
  uchar local_a0 [16];
  undefined auStack_90 [48];
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_c8);
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
     (pAVar1 = (param->value).asn1_string, pAVar1 == (ASN1_STRING *)0x0)) {
    iVar4 = 0x5d;
  }
  else {
    local_cc = pAVar1->data;
    a = d2i_PBEPARAM((PBEPARAM **)0x0,&local_cc,pAVar1->length);
    if (a != (PBEPARAM *)0x0) {
      local_d8 = 1;
      if (a->iter != (ASN1_INTEGER *)0x0) {
        local_d8 = ASN1_INTEGER_get(a->iter);
      }
      d = a->salt->data;
      sVar2 = a->salt->length;
      if (pass == (char *)0x0) {
        passlen = 0;
      }
      else if (passlen == -1) {
        passlen = strlen(pass);
      }
      iVar4 = EVP_DigestInit_ex(&local_c8,md,(ENGINE *)0x0);
      if (((iVar4 == 0) || (iVar4 = EVP_DigestUpdate(&local_c8,pass,passlen), iVar4 == 0)) ||
         (iVar4 = EVP_DigestUpdate(&local_c8,d,sVar2), iVar4 == 0)) {
LAB_0813243c:
        iVar4 = 0;
      }
      else {
        PBEPARAM_free(a);
        iVar4 = EVP_DigestFinal_ex(&local_c8,local_a0,(uint *)0x0);
        if (iVar4 == 0) goto LAB_0813243c;
        sVar2 = EVP_MD_size(md);
        if ((int)sVar2 < 0) {
          iVar4 = 0;
          goto LAB_08132395;
        }
        iVar4 = 1;
        if (1 < local_d8) {
          do {
            iVar3 = EVP_DigestInit_ex(&local_c8,md,(ENGINE *)0x0);
            if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&local_c8,local_a0,sVar2), iVar3 == 0))
               || (iVar3 = EVP_DigestFinal_ex(&local_c8,local_a0,(uint *)0x0), iVar3 == 0))
            goto LAB_0813243c;
            iVar4 = iVar4 + 1;
          } while (local_d8 != iVar4);
        }
        iVar4 = EVP_CIPHER_key_length(cipher);
        if (0x40 < iVar4) {
          OpenSSLDie("p5_crpt.c",0x87,"EVP_CIPHER_key_length(cipher) <= (int)sizeof(md_tmp)");
        }
        iVar4 = EVP_CIPHER_key_length(cipher);
        __memcpy_chk(local_60,local_a0,iVar4,0x40);
        iVar4 = EVP_CIPHER_iv_length(cipher);
        if (0x10 < iVar4) {
          OpenSSLDie("p5_crpt.c",0x89,"EVP_CIPHER_iv_length(cipher) <= 16");
        }
        iVar4 = EVP_CIPHER_iv_length(cipher);
        iVar3 = EVP_CIPHER_iv_length(cipher);
        __memcpy_chk(local_b0,auStack_90 + -iVar3,iVar4,0x10);
        iVar4 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,local_60,local_b0,en_de);
        if (iVar4 == 0) goto LAB_0813243c;
        OPENSSL_cleanse(local_a0,0x40);
        OPENSSL_cleanse(local_60,0x40);
        iVar4 = 1;
        OPENSSL_cleanse(local_b0,0x10);
      }
      EVP_MD_CTX_cleanup(&local_c8);
      goto LAB_08132395;
    }
    iVar4 = 99;
  }
  ERR_put_error(6,0x75,0x72,"p5_crpt.c",iVar4);
  iVar4 = 0;
LAB_08132395:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}

