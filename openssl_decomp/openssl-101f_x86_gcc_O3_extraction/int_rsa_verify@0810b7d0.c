
undefined4
int_rsa_verify(int param_1,void *param_2,size_t param_3,undefined4 *param_4,int *param_5,
              uchar *param_6,size_t param_7,RSA *param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  size_t len;
  int iVar3;
  undefined4 uVar4;
  uchar *to;
  X509_SIG *a;
  X509_ALGOR *pXVar5;
  char *name;
  EVP_MD *md;
  size_t sVar6;
  ASN1_OCTET_STRING *pAVar7;
  size_t __n;
  int in_GS_OFFSET;
  int iVar8;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  len = RSA_size(param_8);
  if (len != param_7) {
    iVar8 = 0xaf;
    iVar3 = 0x77;
LAB_0810b8ef:
    ERR_put_error(4,0x91,iVar3,"rsa_sign.c",iVar8);
    uVar4 = 0;
    goto LAB_0810b847;
  }
  if ((param_4 != (undefined4 *)0x0) && (param_1 == 0x72)) {
    iVar3 = RSA_public_decrypt(len,param_6,(uchar *)param_4,param_8,1);
    uVar4 = 0;
    if (0 < iVar3) {
      *param_5 = iVar3;
      uVar4 = 1;
    }
    goto LAB_0810b847;
  }
  to = (uchar *)CRYPTO_malloc(len,"rsa_sign.c",0xbd);
  if (to == (uchar *)0x0) {
    iVar8 = 0xc0;
    iVar3 = 0x41;
    goto LAB_0810b8ef;
  }
  if ((param_3 == 0x24) || (param_1 != 0x72)) {
    uVar4 = 0;
    iVar3 = RSA_public_decrypt(len,param_6,to,param_8,1);
    if (0 < iVar3) {
      if ((param_1 == 0x5f) && (iVar3 == 0x12)) {
        if ((*to == '\x04') && (to[1] == '\x10')) {
          if (param_4 == (undefined4 *)0x0) {
            uVar4 = 1;
            iVar8 = memcmp(param_2,to + 2,0x10);
            if (iVar8 != 0) {
              uVar4 = 0;
              ERR_put_error(4,0x91,0x68,"rsa_sign.c",0xd6);
            }
          }
          else {
            uVar4 = *(undefined4 *)(to + 2);
            uVar1 = *(undefined4 *)(to + 6);
            uVar2 = *(undefined4 *)(to + 0xe);
            param_4[2] = *(undefined4 *)(to + 10);
            *param_4 = uVar4;
            uVar4 = 1;
            param_4[3] = uVar2;
            param_4[1] = uVar1;
            *param_5 = 0x10;
          }
        }
      }
      else {
        if (param_1 == 0x72) {
          if (iVar3 == 0x24) {
            uVar4 = 1;
            iVar3 = memcmp(to,param_2,0x24);
            if (iVar3 == 0) goto LAB_0810b8b9;
          }
          iVar8 = 0xde;
          iVar3 = 0x68;
          goto LAB_0810b8a8;
        }
        uVar4 = 0;
      }
      local_24 = to;
      a = d2i_X509_SIG((X509_SIG **)0x0,&local_24,iVar3);
      if (a != (X509_SIG *)0x0) {
        if (local_24 == to + iVar3) {
          pXVar5 = a->algor;
          if (pXVar5->parameter != (ASN1_TYPE *)0x0) {
            iVar3 = ASN1_TYPE_get(pXVar5->parameter);
            if (iVar3 != 5) {
              iVar3 = 0xf2;
              goto LAB_0810b97b;
            }
            pXVar5 = a->algor;
          }
          iVar3 = OBJ_obj2nid(pXVar5->algorithm);
          if (param_1 != iVar3) {
            if (((param_1 == 4) && (iVar3 == 8)) || ((param_1 == 3 && (iVar3 == 7)))) {
              fwrite("signature has problems, re-make with post SSLeay045\n",1,0x34,stderr);
              goto LAB_0810bab2;
            }
            iVar3 = 0x10d;
            iVar8 = 100;
            goto LAB_0810b982;
          }
LAB_0810bab2:
          if (param_4 == (undefined4 *)0x0) {
            if (param_3 == a->digest->length) {
              iVar3 = memcmp(param_2,a->digest->data,param_3);
              if (iVar3 == 0) {
                uVar4 = 1;
                goto LAB_0810b994;
              }
            }
            iVar3 = 0x123;
            goto LAB_0810b97b;
          }
          name = OBJ_nid2sn(param_1);
          md = EVP_get_digestbyname(name);
          if (md == (EVP_MD *)0x0) {
            pAVar7 = a->digest;
            __n = pAVar7->length;
          }
          else {
            sVar6 = EVP_MD_size(md);
            pAVar7 = a->digest;
            __n = pAVar7->length;
            if (sVar6 != __n) {
              iVar3 = 0x117;
              iVar8 = 0x8f;
              goto LAB_0810b982;
            }
          }
          uVar4 = 1;
          memcpy(param_4,pAVar7->data,__n);
          *param_5 = a->digest->length;
        }
        else {
          iVar3 = 0xe9;
LAB_0810b97b:
          iVar8 = 0x68;
LAB_0810b982:
          ERR_put_error(4,0x91,iVar8,"rsa_sign.c",iVar3);
        }
LAB_0810b994:
        X509_SIG_free(a);
      }
    }
  }
  else {
    iVar8 = 0xc4;
    iVar3 = 0x83;
LAB_0810b8a8:
    uVar4 = 0;
    ERR_put_error(4,0x91,iVar3,"rsa_sign.c",iVar8);
  }
LAB_0810b8b9:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
LAB_0810b847:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

