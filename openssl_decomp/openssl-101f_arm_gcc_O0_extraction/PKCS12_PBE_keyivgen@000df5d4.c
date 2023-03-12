
int PKCS12_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                       EVP_CIPHER *cipher,EVP_MD *md_type,int en_de)

{
  PBEPARAM *a;
  int iVar1;
  ASN1_STRING *pAVar2;
  int saltlen;
  int iVar3;
  uchar *salt;
  long local_8c;
  uchar *local_80;
  uchar auStack_7c [16];
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
     (pAVar2 = (param->value).asn1_string, pAVar2 == (ASN1_STRING *)0x0)) {
    iVar1 = 0x51;
  }
  else {
    local_80 = pAVar2->data;
    a = d2i_PBEPARAM((PBEPARAM **)0x0,&local_80,pAVar2->length);
    iVar1 = 0x57;
    if (a != (PBEPARAM *)0x0) {
      if (a->iter == (ASN1_INTEGER *)0x0) {
        local_8c = 1;
      }
      else {
        local_8c = ASN1_INTEGER_get(a->iter);
      }
      salt = a->salt->data;
      saltlen = a->salt->length;
      iVar1 = EVP_CIPHER_key_length(cipher);
      iVar3 = PKCS12_key_gen_asc(pass,passlen,salt,saltlen,1,local_8c,iVar1,auStack_6c,md_type);
      if (iVar3 == 0) {
        ERR_put_error(0x23,0x78,0x6b,"p12_crpt.c",0x61);
        PBEPARAM_free(a);
      }
      else {
        iVar1 = EVP_CIPHER_iv_length(cipher);
        iVar3 = PKCS12_key_gen_asc(pass,passlen,salt,saltlen,2,local_8c,iVar1,auStack_7c,md_type);
        if (iVar3 == 0) {
          ERR_put_error(0x23,0x78,0x6a,"p12_crpt.c",0x67);
          PBEPARAM_free(a);
        }
        else {
          PBEPARAM_free(a);
          iVar3 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,auStack_6c,auStack_7c,en_de);
          OPENSSL_cleanse(auStack_6c,0x40);
          OPENSSL_cleanse(auStack_7c,0x10);
        }
      }
      goto LAB_000df610;
    }
  }
  iVar3 = 0;
  ERR_put_error(0x23,0x78,0x65,"p12_crpt.c",iVar1);
LAB_000df610:
  if (local_2c == __TMC_END__) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

