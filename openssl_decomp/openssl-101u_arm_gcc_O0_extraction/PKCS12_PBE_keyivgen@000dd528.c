
int PKCS12_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                       EVP_CIPHER *cipher,EVP_MD *md_type,int en_de)

{
  PBEPARAM *a;
  EVP_CIPHER *pEVar1;
  int iVar2;
  ASN1_STRING *pAVar3;
  int saltlen;
  uchar *salt;
  long local_84;
  uchar *local_80;
  uchar auStack_7c [16];
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (cipher != (EVP_CIPHER *)0x0) {
    if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
       (pAVar3 = (param->value).asn1_string, pAVar3 == (ASN1_STRING *)0x0)) {
      iVar2 = 0x56;
    }
    else {
      local_80 = pAVar3->data;
      a = d2i_PBEPARAM((PBEPARAM **)0x0,&local_80,pAVar3->length);
      iVar2 = 0x5c;
      if (a != (PBEPARAM *)0x0) {
        if (a->iter == (ASN1_INTEGER *)0x0) {
          local_84 = 1;
        }
        else {
          local_84 = ASN1_INTEGER_get(a->iter);
        }
        salt = a->salt->data;
        saltlen = a->salt->length;
        iVar2 = EVP_CIPHER_key_length(cipher);
        pEVar1 = (EVP_CIPHER *)
                 PKCS12_key_gen_asc(pass,passlen,salt,saltlen,1,local_84,iVar2,auStack_6c,md_type);
        if (pEVar1 == (EVP_CIPHER *)0x0) {
          ERR_put_error(0x23,0x78,0x6b,"p12_crpt.c",0x68);
          PBEPARAM_free(a);
          cipher = pEVar1;
        }
        else {
          iVar2 = EVP_CIPHER_iv_length(cipher);
          pEVar1 = (EVP_CIPHER *)
                   PKCS12_key_gen_asc(pass,passlen,salt,saltlen,2,local_84,iVar2,auStack_7c,md_type)
          ;
          if (pEVar1 == (EVP_CIPHER *)0x0) {
            ERR_put_error(0x23,0x78,0x6a,"p12_crpt.c",0x6e);
            PBEPARAM_free(a);
            cipher = pEVar1;
          }
          else {
            PBEPARAM_free(a);
            cipher = (EVP_CIPHER *)
                     EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,auStack_6c,auStack_7c,en_de);
            OPENSSL_cleanse(auStack_6c,0x40);
            OPENSSL_cleanse(auStack_7c,0x10);
          }
        }
        goto LAB_000dd568;
      }
    }
    ERR_put_error(0x23,0x78,0x65,"p12_crpt.c",iVar2);
    cipher = (EVP_CIPHER *)0x0;
  }
LAB_000dd568:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)cipher;
}

