
int PKCS5_v2_PBE_keyivgen
              (EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,EVP_CIPHER *cipher,
              EVP_MD *md,int en_de)

{
  ASN1_STRING *pAVar1;
  int iVar2;
  char *name;
  EVP_CIPHER *cipher_00;
  int iVar3;
  PBE2PARAM *a;
  int in_GS_OFFSET;
  int line;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
     (pAVar1 = (param->value).asn1_string, pAVar1 == (ASN1_STRING *)0x0)) {
    iVar3 = 0;
    a = (PBE2PARAM *)0x0;
    ERR_put_error(6,0x76,0x72,"p5_crpt2.c",0xcf);
  }
  else {
    local_24 = pAVar1->data;
    a = d2i_PBE2PARAM((PBE2PARAM **)0x0,&local_24,pAVar1->length);
    if (a == (PBE2PARAM *)0x0) {
      line = 0xd6;
      iVar2 = 0x72;
    }
    else {
      iVar2 = OBJ_obj2nid(a->keyfunc->algorithm);
      if (iVar2 == 0x45) {
        iVar2 = OBJ_obj2nid(a->encryption->algorithm);
        name = OBJ_nid2sn(iVar2);
        cipher_00 = EVP_get_cipherbyname(name);
        if (cipher_00 != (EVP_CIPHER *)0x0) {
          iVar3 = 0;
          iVar2 = EVP_CipherInit_ex(ctx,cipher_00,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,en_de);
          if (iVar2 != 0) {
            iVar2 = EVP_CIPHER_asn1_to_param(ctx,a->encryption->parameter);
            if (iVar2 < 0) {
              ERR_put_error(6,0x76,0x7a,"p5_crpt2.c",0xf2);
            }
            else {
              iVar3 = PKCS5_v2_PBKDF2_keyivgen
                                (ctx,pass,passlen,a->keyfunc->parameter,cipher,md,en_de);
            }
          }
          goto LAB_08135668;
        }
        line = 0xe9;
        iVar2 = 0x6b;
      }
      else {
        line = 0xde;
        iVar2 = 0x7c;
      }
    }
    iVar3 = 0;
    ERR_put_error(6,0x76,iVar2,"p5_crpt2.c",line);
  }
LAB_08135668:
  PBE2PARAM_free(a);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

