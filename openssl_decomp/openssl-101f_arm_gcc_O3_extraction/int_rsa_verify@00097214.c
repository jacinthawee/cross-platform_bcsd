
uint int_rsa_verify(int param_1,void *param_2,size_t param_3,undefined4 *param_4,int *param_5,
                   uchar *param_6,size_t param_7,RSA *param_8)

{
  size_t len;
  int iVar1;
  uchar *to;
  X509_SIG *a;
  undefined4 uVar2;
  char *name;
  EVP_MD *md;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  size_t __n;
  uint uVar6;
  undefined4 uVar7;
  X509_ALGOR *pXVar8;
  ASN1_OCTET_STRING *pAVar9;
  uint uVar10;
  undefined4 *puVar11;
  uchar *local_2c [2];
  
  len = RSA_size(param_8);
  if (len != param_7) {
    ERR_put_error(4,0x91,0x77,"rsa_sign.c",0xaf);
    return 0;
  }
  uVar10 = count_leading_zeroes(param_1 + -0x72);
  puVar11 = param_4;
  if (param_4 != (undefined4 *)0x0) {
    puVar11 = (undefined4 *)0x1;
  }
  uVar10 = uVar10 >> 5;
  if ((uVar10 & (uint)puVar11) != 0) {
    iVar1 = RSA_public_decrypt(len,param_6,(uchar *)param_4,param_8,1);
    if (0 < iVar1) {
      *param_5 = iVar1;
    }
    return (uint)(0 < iVar1);
  }
  to = (uchar *)CRYPTO_malloc(len,"rsa_sign.c",0xbd);
  if (to == (uchar *)0x0) {
    ERR_put_error(4,0x91,0x41,"rsa_sign.c",0xc0);
    return 0;
  }
  if (param_3 == 0x24) {
    uVar6 = 0;
  }
  else {
    uVar6 = uVar10 & 1;
  }
  if (uVar6 != 0) {
    ERR_put_error(4,0x91,0x83,"rsa_sign.c",0xc4);
    uVar6 = uVar10 & (uint)puVar11;
    goto LAB_00097336;
  }
  iVar1 = RSA_public_decrypt(len,param_6,to,param_8,1);
  if (iVar1 < 1) goto LAB_00097336;
  if (iVar1 == 0x12 && param_1 == 0x5f) {
    if ((*to == '\x04') && (to[1] == '\x10')) {
      if (puVar11 == (undefined4 *)0x0) {
        iVar4 = memcmp(param_2,to + 2,0x10);
        uVar6 = 1;
        if (iVar4 != 0) {
          ERR_put_error(4,0x91,0x68,"rsa_sign.c",0xd6);
          uVar6 = 0;
        }
      }
      else {
        uVar2 = *(undefined4 *)(to + 6);
        uVar5 = *(undefined4 *)(to + 10);
        uVar7 = *(undefined4 *)(to + 0xe);
        *param_4 = *(undefined4 *)(to + 2);
        param_4[1] = uVar2;
        param_4[2] = uVar5;
        param_4[3] = uVar7;
        *param_5 = 0x10;
        uVar6 = 1;
      }
    }
  }
  else {
    uVar6 = uVar10;
    if (uVar10 != 0) {
      if ((iVar1 != 0x24) || (iVar1 = memcmp(to,param_2,0x24), uVar6 = 1, iVar1 != 0)) {
        ERR_put_error(4,0x91,0x68,"rsa_sign.c",0xde);
        uVar6 = 0;
      }
      goto LAB_00097336;
    }
  }
  local_2c[0] = to;
  a = d2i_X509_SIG((X509_SIG **)0x0,local_2c,iVar1);
  if (a == (X509_SIG *)0x0) goto LAB_00097336;
  if (local_2c[0] == to + iVar1) {
    pXVar8 = a->algor;
    if (pXVar8->parameter != (ASN1_TYPE *)0x0) {
      iVar1 = ASN1_TYPE_get(pXVar8->parameter);
      if (iVar1 != 5) {
        iVar1 = 0xf2;
        goto LAB_000972e8;
      }
      pXVar8 = a->algor;
    }
    iVar1 = OBJ_obj2nid(pXVar8->algorithm);
    if (iVar1 == param_1) {
LAB_00097418:
      if (puVar11 == (undefined4 *)0x0) {
        if ((a->digest->length != param_3) ||
           (iVar1 = memcmp(param_2,a->digest->data,param_3), iVar1 != 0)) {
          iVar1 = 0x123;
          goto LAB_000972e8;
        }
        uVar6 = 1;
      }
      else {
        name = OBJ_nid2sn(param_1);
        md = EVP_get_digestbyname(name);
        if (md == (EVP_MD *)0x0) {
          pAVar9 = a->digest;
          __n = pAVar9->length;
        }
        else {
          sVar3 = EVP_MD_size(md);
          pAVar9 = a->digest;
          __n = pAVar9->length;
          if (sVar3 != __n) {
            ERR_put_error(4,0x91,0x8f,"rsa_sign.c",0x117);
            goto LAB_000972f8;
          }
        }
        memcpy(param_4,pAVar9->data,__n);
        uVar6 = 1;
        *param_5 = a->digest->length;
      }
    }
    else {
      if ((iVar1 == 8 && param_1 == 4) || (iVar1 == 7 && param_1 == 3)) {
        fwrite("signature has problems, re-make with post SSLeay045\n",1,0x34,stderr);
        goto LAB_00097418;
      }
      ERR_put_error(4,0x91,100,"rsa_sign.c",0x10d);
    }
  }
  else {
    iVar1 = 0xe9;
LAB_000972e8:
    ERR_put_error(4,0x91,0x68,"rsa_sign.c",iVar1);
  }
LAB_000972f8:
  X509_SIG_free(a);
LAB_00097336:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return uVar6;
}

