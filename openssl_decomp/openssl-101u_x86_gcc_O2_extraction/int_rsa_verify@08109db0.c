
undefined4
int_rsa_verify(int param_1,void *param_2,size_t param_3,undefined4 *param_4,int *param_5,
              uchar *param_6,size_t param_7,RSA *param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uchar *ptr;
  size_t len;
  int iVar3;
  undefined4 uVar4;
  uchar *to;
  size_t __n;
  X509_SIG *a;
  size_t len_00;
  X509_ALGOR *pXVar5;
  char *name;
  EVP_MD *md;
  ASN1_OCTET_STRING *pAVar6;
  int in_GS_OFFSET;
  int iVar7;
  uchar *local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  len = RSA_size(param_8);
  if (len != param_7) {
    iVar7 = 0xba;
    iVar3 = 0x77;
LAB_08109ed7:
    ERR_put_error(4,0x91,iVar3,"rsa_sign.c",iVar7);
    uVar4 = 0;
    goto LAB_08109e28;
  }
  if ((param_4 != (undefined4 *)0x0) && (param_1 == 0x72)) {
    iVar3 = RSA_public_decrypt(len,param_6,(uchar *)param_4,param_8,1);
    uVar4 = 0;
    if (0 < iVar3) {
      *param_5 = iVar3;
      uVar4 = 1;
    }
    goto LAB_08109e28;
  }
  to = (uchar *)CRYPTO_malloc(len,"rsa_sign.c",199);
  if (to == (uchar *)0x0) {
    iVar7 = 0xc9;
    iVar3 = 0x41;
    goto LAB_08109ed7;
  }
  if ((param_3 == 0x24) || (param_1 != 0x72)) {
    uVar4 = 0;
    __n = RSA_public_decrypt(len,param_6,to,param_8,1);
    if (0 < (int)__n) {
      if ((param_1 == 0x5f) && (__n == 0x12)) {
        if ((*to == '\x04') && (to[1] == '\x10')) {
          if (param_4 == (undefined4 *)0x0) {
            uVar4 = 1;
            iVar3 = memcmp(param_2,to + 2,0x10);
            if (iVar3 != 0) {
              iVar3 = 0xde;
              goto LAB_08109fd6;
            }
          }
          else {
            uVar4 = *(undefined4 *)(to + 2);
            uVar1 = *(undefined4 *)(to + 10);
            uVar2 = *(undefined4 *)(to + 0xe);
            param_4[1] = *(undefined4 *)(to + 6);
            *param_4 = uVar4;
            uVar4 = 1;
            param_4[3] = uVar2;
            param_4[2] = uVar1;
            *param_5 = 0x10;
          }
          goto LAB_08109ea1;
        }
      }
      else if (param_1 == 0x72) {
        if (__n == 0x24) {
          uVar4 = 1;
          iVar3 = memcmp(to,param_2,0x24);
          if (iVar3 == 0) goto LAB_08109ea1;
        }
        iVar3 = 0xe5;
LAB_08109fd6:
        iVar7 = 0x68;
        goto LAB_08109e90;
      }
      local_28 = to;
      a = d2i_X509_SIG((X509_SIG **)0x0,&local_28,__n);
      if (a == (X509_SIG *)0x0) goto LAB_08109e9f;
      if (local_28 == to + __n) {
        local_24 = (uchar *)0x0;
        len_00 = i2d_X509_SIG(a,&local_24);
        ptr = local_24;
        if ((int)len_00 < 1) goto LAB_08109f62;
        if (len_00 != __n) {
          OPENSSL_cleanse(local_24,len_00);
          CRYPTO_free(local_24);
          goto LAB_08109f62;
        }
        iVar3 = memcmp(to,local_24,__n);
        OPENSSL_cleanse(ptr,__n);
        CRYPTO_free(local_24);
        if (iVar3 != 0) goto LAB_08109f62;
        pXVar5 = a->algor;
        if (pXVar5->parameter != (ASN1_TYPE *)0x0) {
          iVar3 = ASN1_TYPE_get(pXVar5->parameter);
          if (iVar3 == 5) {
            pXVar5 = a->algor;
            goto LAB_0810a0fc;
          }
          iVar7 = 0xfb;
          iVar3 = 0x68;
          goto LAB_08109f75;
        }
LAB_0810a0fc:
        iVar3 = OBJ_obj2nid(pXVar5->algorithm);
        if (param_1 != iVar3) {
          if (((param_1 != 4) || (iVar3 != 8)) && ((param_1 != 3 || (iVar3 != 7)))) {
            iVar7 = 0x111;
            iVar3 = 100;
            goto LAB_08109f75;
          }
          fwrite("signature has problems, re-make with post SSLeay045\n",1,0x34,stderr);
        }
        if (param_4 == (undefined4 *)0x0) {
          if (param_3 == a->digest->length) {
            uVar4 = 1;
            iVar3 = memcmp(param_2,a->digest->data,param_3);
            if (iVar3 != 0) goto LAB_0810a27e;
          }
          else {
LAB_0810a27e:
            iVar7 = 0x121;
            iVar3 = 0x68;
LAB_0810a1b6:
            uVar4 = 0;
            ERR_put_error(4,0x91,iVar3,"rsa_sign.c",iVar7);
          }
        }
        else {
          name = OBJ_nid2sn(param_1);
          md = EVP_get_digestbyname(name);
          if (md == (EVP_MD *)0x0) {
            pAVar6 = a->digest;
          }
          else {
            iVar3 = EVP_MD_size(md);
            pAVar6 = a->digest;
            if (iVar3 != pAVar6->length) {
              iVar7 = 0x119;
              iVar3 = 0x8f;
              goto LAB_0810a1b6;
            }
          }
          uVar4 = 1;
          memcpy(param_4,pAVar6->data,pAVar6->length);
          *param_5 = a->digest->length;
        }
      }
      else {
LAB_08109f62:
        iVar7 = 0xf1;
        iVar3 = 0x68;
LAB_08109f75:
        uVar4 = 0;
        ERR_put_error(4,0x91,iVar3,"rsa_sign.c",iVar7);
      }
      X509_SIG_free(a);
    }
  }
  else {
    iVar3 = 0xcd;
    iVar7 = 0x83;
LAB_08109e90:
    ERR_put_error(4,0x91,iVar7,"rsa_sign.c",iVar3);
LAB_08109e9f:
    uVar4 = 0;
  }
LAB_08109ea1:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
LAB_08109e28:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

