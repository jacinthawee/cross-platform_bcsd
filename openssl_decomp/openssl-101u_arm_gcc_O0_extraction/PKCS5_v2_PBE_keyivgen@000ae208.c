
int PKCS5_v2_PBE_keyivgen
              (EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,EVP_CIPHER *cipher,
              EVP_MD *md,int en_de)

{
  int iVar1;
  char *name;
  EVP_CIPHER *cipher_00;
  ASN1_STRING *pAVar2;
  EVP_CIPHER *a;
  uchar *local_1c;
  
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
     (pAVar2 = (param->value).asn1_string, pAVar2 == (ASN1_STRING *)0x0)) {
    ERR_put_error(6,0x76,0x72,"p5_crpt2.c",0xcb);
    a = (EVP_CIPHER *)0x0;
    cipher_00 = (EVP_CIPHER *)0x0;
  }
  else {
    local_1c = pAVar2->data;
    a = (EVP_CIPHER *)d2i_PBE2PARAM((PBE2PARAM **)0x0,&local_1c,pAVar2->length);
    if (a == (EVP_CIPHER *)0x0) {
      ERR_put_error(6,0x76,0x72,"p5_crpt2.c",0xd2);
      cipher_00 = a;
    }
    else {
      iVar1 = OBJ_obj2nid(((X509_ALGOR *)a->nid)->algorithm);
      if (iVar1 != 0x45) {
        ERR_put_error(6,0x76,0x7c,"p5_crpt2.c",0xda);
        PBE2PARAM_free((PBE2PARAM *)a);
        return 0;
      }
      iVar1 = OBJ_obj2nid(((X509_ALGOR *)a->block_size)->algorithm);
      name = OBJ_nid2sn(iVar1);
      cipher_00 = EVP_get_cipherbyname(name);
      if (cipher_00 == (EVP_CIPHER *)0x0) {
        ERR_put_error(6,0x76,0x6b,"p5_crpt2.c",0xe5);
      }
      else {
        cipher_00 = (EVP_CIPHER *)
                    EVP_CipherInit_ex(ctx,cipher_00,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,en_de);
        if (cipher_00 != (EVP_CIPHER *)0x0) {
          iVar1 = EVP_CIPHER_asn1_to_param(ctx,((X509_ALGOR *)a->block_size)->parameter);
          if (iVar1 < 0) {
            ERR_put_error(6,0x76,0x7a,"p5_crpt2.c",0xed);
            cipher_00 = (EVP_CIPHER *)0x0;
          }
          else {
            cipher_00 = (EVP_CIPHER *)
                        PKCS5_v2_PBKDF2_keyivgen
                                  (ctx,pass,passlen,((X509_ALGOR *)a->nid)->parameter,cipher,md,
                                   en_de);
          }
        }
      }
    }
  }
  PBE2PARAM_free((PBE2PARAM *)a);
  return (int)cipher_00;
}

