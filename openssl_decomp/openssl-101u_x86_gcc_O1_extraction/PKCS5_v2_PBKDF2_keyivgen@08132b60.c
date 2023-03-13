
int PKCS5_v2_PBKDF2_keyivgen
              (EVP_CIPHER_CTX *param_1,char *param_2,int param_3,int *param_4,undefined4 param_5,
              undefined4 param_6,int param_7)

{
  ASN1_STRING *pAVar1;
  uchar *salt;
  EVP_CIPHER *pEVar2;
  uint len;
  uint uVar3;
  char *name;
  EVP_MD *digest;
  long iter;
  int iVar4;
  PBKDF2PARAM *a;
  int in_GS_OFFSET;
  int iVar5;
  int line;
  uchar *local_68;
  int local_64;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pEVar2 = EVP_CIPHER_CTX_cipher(param_1);
  if (pEVar2 == (EVP_CIPHER *)0x0) {
    a = (PBKDF2PARAM *)0x0;
    len = 0;
    iVar4 = 0;
    ERR_put_error(6,0xa4,0x83,"p5_crpt2.c",0x105);
    goto LAB_08132bdb;
  }
  len = EVP_CIPHER_CTX_key_length(param_1);
  if (0x40 < len) {
    OpenSSLDie("p5_crpt2.c",0x109,"keylen <= sizeof key");
  }
  if ((param_4 == (int *)0x0) || (*param_4 != 0x10)) {
    a = (PBKDF2PARAM *)0x0;
    iVar4 = 0;
    ERR_put_error(6,0xa4,0x72,"p5_crpt2.c",0x10e);
    goto LAB_08132bdb;
  }
  local_68 = (uchar *)((long *)param_4[1])[2];
  a = d2i_PBKDF2PARAM((PBKDF2PARAM **)0x0,&local_68,*(long *)param_4[1]);
  if (a == (PBKDF2PARAM *)0x0) {
    line = 0x116;
    iVar5 = 0x72;
  }
  else {
    len = EVP_CIPHER_CTX_key_length(param_1);
    if (a->keylength != (ASN1_INTEGER *)0x0) {
      uVar3 = ASN1_INTEGER_get(a->keylength);
      if (len != uVar3) {
        line = 0x11f;
        iVar5 = 0x7b;
        goto LAB_08132cf0;
      }
    }
    iVar4 = 0xa3;
    if (a->prf != (X509_ALGOR *)0x0) {
      iVar4 = OBJ_obj2nid(a->prf->algorithm);
    }
    iVar4 = EVP_PBE_find(1,iVar4,(int *)0x0,&local_64,(undefined1 **)0x0);
    if (iVar4 == 0) {
      line = 0x129;
      iVar5 = 0x7d;
    }
    else {
      name = OBJ_nid2sn(local_64);
      digest = EVP_get_digestbyname(name);
      if (digest == (EVP_MD *)0x0) {
        line = 0x12f;
        iVar5 = 0x7d;
      }
      else {
        if (a->salt->type == 4) {
          pAVar1 = (a->salt->value).asn1_string;
          salt = pAVar1->data;
          iVar5 = pAVar1->length;
          iter = ASN1_INTEGER_get(a->iter);
          iVar4 = 0;
          iVar5 = PKCS5_PBKDF2_HMAC(param_2,param_3,salt,iVar5,iter,digest,len,local_60);
          if (iVar5 != 0) {
            iVar4 = EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,local_60,(uchar *)0x0,
                                      param_7);
          }
          goto LAB_08132bdb;
        }
        line = 0x134;
        iVar5 = 0x7e;
      }
    }
  }
LAB_08132cf0:
  iVar4 = 0;
  ERR_put_error(6,0xa4,iVar5,"p5_crpt2.c",line);
LAB_08132bdb:
  OPENSSL_cleanse(local_60,len);
  PBKDF2PARAM_free(a);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

