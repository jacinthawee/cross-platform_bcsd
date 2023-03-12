
void PKCS5_v2_PBKDF2_keyivgen
               (EVP_CIPHER_CTX *param_1,char *param_2,int param_3,int *param_4,undefined4 param_5,
               undefined4 param_6,int param_7)

{
  EVP_MD *a;
  EVP_MD *len;
  EVP_MD *pEVar1;
  char *name;
  long iter;
  int iVar2;
  uchar *salt;
  int *piVar3;
  uchar *local_74;
  int local_70;
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  a = (EVP_MD *)EVP_CIPHER_CTX_cipher(param_1);
  if (a == (EVP_MD *)0x0) {
    ERR_put_error(6,0xa4,0x83,"p5_crpt2.c",0x105);
    len = a;
    pEVar1 = a;
  }
  else {
    len = (EVP_MD *)EVP_CIPHER_CTX_key_length(param_1);
    if ((EVP_MD *)0x40 < len) {
      OpenSSLDie("p5_crpt2.c",0x109,"keylen <= sizeof key");
    }
    if ((param_4 == (int *)0x0) || (*param_4 != 0x10)) {
      a = (EVP_MD *)0x0;
      ERR_put_error(6,0xa4,0x72,"p5_crpt2.c",0x10e);
      pEVar1 = (EVP_MD *)0x0;
    }
    else {
      local_74 = (uchar *)((long *)param_4[1])[2];
      a = (EVP_MD *)d2i_PBKDF2PARAM((PBKDF2PARAM **)0x0,&local_74,*(long *)param_4[1]);
      if (a == (EVP_MD *)0x0) {
        ERR_put_error(6,0xa4,0x72,"p5_crpt2.c",0x116);
        pEVar1 = a;
      }
      else {
        len = (EVP_MD *)EVP_CIPHER_CTX_key_length(param_1);
        if (((ASN1_INTEGER *)a->md_size == (ASN1_INTEGER *)0x0) ||
           (pEVar1 = (EVP_MD *)ASN1_INTEGER_get((ASN1_INTEGER *)a->md_size), len == pEVar1)) {
          iVar2 = 0xa3;
          if ((ASN1_OBJECT **)a->flags != (ASN1_OBJECT **)0x0) {
            iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)a->flags);
          }
          pEVar1 = (EVP_MD *)EVP_PBE_find(1,iVar2,(int *)0x0,&local_70,(undefined1 **)0x0);
          if (pEVar1 == (EVP_MD *)0x0) {
            ERR_put_error(6,0xa4,0x7d,"p5_crpt2.c",0x129);
          }
          else {
            name = OBJ_nid2sn(local_70);
            pEVar1 = EVP_get_digestbyname(name);
            if (pEVar1 == (EVP_MD *)0x0) {
              ERR_put_error(6,0xa4,0x7d,"p5_crpt2.c",0x12f);
            }
            else if (*(int *)a->type == 4) {
              piVar3 = (int *)((int *)a->type)[1];
              salt = (uchar *)piVar3[2];
              iVar2 = *piVar3;
              iter = ASN1_INTEGER_get((ASN1_INTEGER *)a->pkey_type);
              pEVar1 = (EVP_MD *)
                       PKCS5_PBKDF2_HMAC(param_2,param_3,salt,iVar2,iter,pEVar1,(int)len,auStack_6c)
              ;
              if (pEVar1 != (EVP_MD *)0x0) {
                pEVar1 = (EVP_MD *)
                         EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,auStack_6c,
                                           (uchar *)0x0,param_7);
              }
            }
            else {
              ERR_put_error(6,0xa4,0x7e,"p5_crpt2.c",0x134);
              pEVar1 = (EVP_MD *)0x0;
            }
          }
        }
        else {
          ERR_put_error(6,0xa4,0x7b,"p5_crpt2.c",0x11f);
          pEVar1 = (EVP_MD *)0x0;
        }
      }
    }
  }
  OPENSSL_cleanse(auStack_6c,(size_t)len);
  PBKDF2PARAM_free((PBKDF2PARAM *)a);
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pEVar1);
  }
  return;
}

