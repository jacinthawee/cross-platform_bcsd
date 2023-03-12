
X509_SIG *
int_rsa_verify(int param_1,void *param_2,size_t param_3,undefined4 *param_4,int *param_5,
              uchar *param_6,size_t param_7,RSA *param_8)

{
  uchar *ptr;
  size_t len;
  int iVar1;
  X509_SIG *to;
  size_t __n;
  undefined4 uVar2;
  size_t len_00;
  char *name;
  EVP_MD *md;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  X509_ALGOR *pXVar6;
  ASN1_OCTET_STRING *pAVar7;
  undefined4 *puVar8;
  X509_SIG *pXVar9;
  uint uVar10;
  X509_SIG *a;
  X509_SIG *local_30;
  uchar *local_2c [2];
  
  len = RSA_size(param_8);
  if (len != param_7) {
    ERR_put_error(4,0x91,0x77,"rsa_sign.c",0xba);
    return (X509_SIG *)0x0;
  }
  uVar10 = count_leading_zeroes(param_1 + -0x72);
  puVar8 = param_4;
  if (param_4 != (undefined4 *)0x0) {
    puVar8 = (undefined4 *)0x1;
  }
  uVar10 = uVar10 >> 5;
  if ((X509_SIG *)(uVar10 & (uint)puVar8) != (X509_SIG *)0x0) {
    iVar1 = RSA_public_decrypt(len,param_6,(uchar *)param_4,param_8,1);
    if (0 < iVar1) {
      *param_5 = iVar1;
    }
    return (X509_SIG *)(uint)(0 < iVar1);
  }
  to = (X509_SIG *)CRYPTO_malloc(len,"rsa_sign.c",199);
  if (to == (X509_SIG *)0x0) {
    ERR_put_error(4,0x91,0x41,"rsa_sign.c",0xc9);
    return (X509_SIG *)0x0;
  }
  if (param_3 == 0x24) {
    a = (X509_SIG *)0x0;
  }
  else {
    a = (X509_SIG *)(uVar10 & 1);
  }
  if (a != (X509_SIG *)0x0) {
    ERR_put_error(4,0x91,0x83,"rsa_sign.c",0xcd);
    a = (X509_SIG *)(uVar10 & (uint)puVar8);
    goto LAB_00095986;
  }
  __n = RSA_public_decrypt(len,param_6,(uchar *)to,param_8,1);
  if ((int)__n < 1) goto LAB_00095986;
  if (__n == 0x12 && param_1 == 0x5f) {
    if ((*(uchar *)&to->algor == '\x04') && (*(uchar *)((int)&to->algor + 1) == '\x10')) {
      if (puVar8 != (undefined4 *)0x0) {
        uVar2 = *(undefined4 *)((int)&to->digest + 2);
        uVar4 = *(undefined4 *)((int)&to[1].algor + 2);
        uVar5 = *(undefined4 *)((int)&to[1].digest + 2);
        *param_4 = *(undefined4 *)((int)&to->algor + 2);
        param_4[1] = uVar2;
        param_4[3] = uVar5;
        param_4[2] = uVar4;
        *param_5 = 0x10;
        a = (X509_SIG *)0x1;
        goto LAB_00095986;
      }
      iVar3 = memcmp(param_2,(uchar *)((int)&to->algor + 2),0x10);
      iVar1 = 0xde;
      if (iVar3 == 0) goto LAB_000959b0;
LAB_000959e8:
      ERR_put_error(4,0x91,0x68,"rsa_sign.c",iVar1);
      a = (X509_SIG *)0x0;
      goto LAB_00095986;
    }
  }
  else if (uVar10 != 0) {
    if ((__n == 0x24) && (iVar1 = memcmp(to,param_2,0x24), iVar1 == 0)) {
LAB_000959b0:
      a = (X509_SIG *)0x1;
      goto LAB_00095986;
    }
    iVar1 = 0xe5;
    goto LAB_000959e8;
  }
  local_30 = to;
  a = d2i_X509_SIG((X509_SIG **)0x0,(uchar **)&local_30,__n);
  if (a == (X509_SIG *)0x0) goto LAB_00095986;
  if (local_30 == (X509_SIG *)((int)&to->algor + __n)) {
    local_2c[0] = (uchar *)0x0;
    len_00 = i2d_X509_SIG(a,local_2c);
    ptr = local_2c[0];
    if ((int)len_00 < 1) goto LAB_00095930;
    if (__n != len_00) {
      OPENSSL_cleanse(local_2c[0],len_00);
      CRYPTO_free(local_2c[0]);
      goto LAB_00095930;
    }
    iVar1 = memcmp(to,local_2c[0],__n);
    OPENSSL_cleanse(ptr,__n);
    CRYPTO_free(local_2c[0]);
    if (iVar1 != 0) goto LAB_00095930;
    pXVar6 = a->algor;
    if (pXVar6->parameter != (ASN1_TYPE *)0x0) {
      iVar1 = ASN1_TYPE_get(pXVar6->parameter);
      if (iVar1 == 5) {
        pXVar6 = a->algor;
        goto LAB_00095a88;
      }
      iVar1 = 0xfb;
      goto LAB_00095936;
    }
LAB_00095a88:
    iVar1 = OBJ_obj2nid(pXVar6->algorithm);
    if (iVar1 != param_1) {
      if ((iVar1 == 8 && param_1 == 4) || ((iVar1 == 7 && (param_1 == 3)))) {
        fwrite("signature has problems, re-make with post SSLeay045\n",1,0x34,stderr);
        goto LAB_00095ac0;
      }
      ERR_put_error(4,0x91,100,"rsa_sign.c",0x111);
      goto LAB_00095946;
    }
LAB_00095ac0:
    if (puVar8 == (undefined4 *)0x0) {
      if ((a->digest->length == param_3) &&
         (iVar1 = memcmp(param_2,a->digest->data,param_3), iVar1 == 0)) {
        pXVar9 = (X509_SIG *)0x1;
      }
      else {
        pXVar9 = (X509_SIG *)0x0;
        ERR_put_error(4,0x91,0x68,"rsa_sign.c",0x121);
      }
    }
    else {
      name = OBJ_nid2sn(param_1);
      md = EVP_get_digestbyname(name);
      if (md == (EVP_MD *)0x0) {
        pAVar7 = a->digest;
      }
      else {
        iVar1 = EVP_MD_size(md);
        pAVar7 = a->digest;
        if (iVar1 != pAVar7->length) {
          pXVar9 = (X509_SIG *)0x0;
          ERR_put_error(4,0x91,0x8f,"rsa_sign.c",0x119);
          goto LAB_00095948;
        }
      }
      pXVar9 = (X509_SIG *)0x1;
      memcpy(param_4,pAVar7->data,pAVar7->length);
      *param_5 = a->digest->length;
    }
  }
  else {
LAB_00095930:
    iVar1 = 0xf1;
LAB_00095936:
    ERR_put_error(4,0x91,0x68,"rsa_sign.c",iVar1);
LAB_00095946:
    pXVar9 = (X509_SIG *)0x0;
  }
LAB_00095948:
  X509_SIG_free(a);
  a = pXVar9;
LAB_00095986:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return a;
}

