
int PKCS12_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                       EVP_CIPHER *cipher,EVP_MD *md_type,int en_de)

{
  ASN1_STRING *pAVar1;
  uchar *salt;
  PBEPARAM *a;
  int iVar2;
  int in_GS_OFFSET;
  int iVar3;
  int local_8c;
  long local_88;
  uchar *local_74;
  uchar local_70 [16];
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cipher == (EVP_CIPHER *)0x0) {
    local_8c = 0;
  }
  else {
    if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
       (pAVar1 = (param->value).asn1_string, pAVar1 == (ASN1_STRING *)0x0)) {
      iVar3 = 0x56;
    }
    else {
      local_74 = pAVar1->data;
      a = d2i_PBEPARAM((PBEPARAM **)0x0,&local_74,pAVar1->length);
      if (a != (PBEPARAM *)0x0) {
        local_88 = 1;
        if (a->iter != (ASN1_INTEGER *)0x0) {
          local_88 = ASN1_INTEGER_get(a->iter);
        }
        salt = a->salt->data;
        iVar3 = a->salt->length;
        iVar2 = EVP_CIPHER_key_length(cipher);
        local_8c = PKCS12_key_gen_asc(pass,passlen,salt,iVar3,1,local_88,iVar2,local_60,md_type);
        if (local_8c == 0) {
          iVar2 = 0x68;
          iVar3 = 0x6b;
        }
        else {
          iVar2 = EVP_CIPHER_iv_length(cipher);
          local_8c = PKCS12_key_gen_asc(pass,passlen,salt,iVar3,2,local_88,iVar2,local_70,md_type);
          if (local_8c != 0) {
            PBEPARAM_free(a);
            local_8c = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,local_60,local_70,en_de);
            OPENSSL_cleanse(local_60,0x40);
            OPENSSL_cleanse(local_70,0x10);
            goto LAB_081809b5;
          }
          iVar2 = 0x6e;
          iVar3 = 0x6a;
        }
        ERR_put_error(0x23,0x78,iVar3,"p12_crpt.c",iVar2);
        PBEPARAM_free(a);
        goto LAB_081809b5;
      }
      iVar3 = 0x5c;
    }
    ERR_put_error(0x23,0x78,0x65,"p12_crpt.c",iVar3);
    local_8c = 0;
  }
LAB_081809b5:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_8c;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

