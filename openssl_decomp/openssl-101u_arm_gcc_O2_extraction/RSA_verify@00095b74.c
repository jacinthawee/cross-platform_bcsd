
int RSA_verify(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  uchar *ptr;
  int iVar1;
  uint uVar2;
  uchar *to;
  size_t __n;
  X509_SIG *pXVar3;
  size_t len;
  X509_ALGOR *pXVar4;
  _func_1627 *p_Var5;
  X509_SIG *pXVar6;
  uchar *local_30;
  uchar *local_2c [2];
  
  if ((rsa->flags << 0x19 < 0) && (p_Var5 = rsa->meth->rsa_verify, p_Var5 != (_func_1627 *)0x0)) {
    iVar1 = (*p_Var5)(type,m,m_length,sigbuf,siglen,rsa);
    return iVar1;
  }
  uVar2 = RSA_size(rsa);
  if (siglen != uVar2) {
    ERR_put_error(4,0x91,0x77,"rsa_sign.c",0xba);
    return 0;
  }
  to = (uchar *)CRYPTO_malloc(uVar2,"rsa_sign.c",199);
  if (to == (uchar *)0x0) {
    ERR_put_error(4,0x91,0x41,"rsa_sign.c",0xc9);
    return 0;
  }
  uVar2 = count_leading_zeroes(type + -0x72);
  if (m_length == 0x24) {
    pXVar6 = (X509_SIG *)0x0;
  }
  else {
    pXVar6 = (X509_SIG *)(uVar2 >> 5 & 1);
  }
  if (pXVar6 != (X509_SIG *)0x0) {
    ERR_put_error(4,0x91,0x83,"rsa_sign.c",0xcd);
    pXVar3 = (X509_SIG *)0x0;
    goto LAB_00095bf6;
  }
  __n = RSA_public_decrypt(siglen,sigbuf,to,rsa,1);
  pXVar3 = pXVar6;
  if ((int)__n < 1) goto LAB_00095bf6;
  pXVar3 = (X509_SIG *)0x1;
  if (__n == 0x12 && type == 0x5f) {
    if ((*to == '\x04') && (to[1] == '\x10')) {
      iVar1 = memcmp(m,to + 2,0x10);
      if (iVar1 != 0) {
        ERR_put_error(4,0x91,0x68,"rsa_sign.c",0xde);
        pXVar3 = pXVar6;
      }
      goto LAB_00095bf6;
    }
  }
  else if (uVar2 >> 5 != 0) {
    if ((__n != 0x24) || (iVar1 = memcmp(to,m,0x24), iVar1 != 0)) {
      ERR_put_error(4,0x91,0x68,"rsa_sign.c",0xe5);
      pXVar3 = (X509_SIG *)0x0;
    }
    goto LAB_00095bf6;
  }
  local_30 = to;
  pXVar3 = d2i_X509_SIG((X509_SIG **)0x0,&local_30,__n);
  if (pXVar3 == (X509_SIG *)0x0) goto LAB_00095bf6;
  if (local_30 == to + __n) {
    local_2c[0] = (uchar *)0x0;
    len = i2d_X509_SIG(pXVar3,local_2c);
    ptr = local_2c[0];
    if ((int)len < 1) goto LAB_00095c80;
    if (__n != len) {
      OPENSSL_cleanse(local_2c[0],len);
      CRYPTO_free(local_2c[0]);
      goto LAB_00095c80;
    }
    iVar1 = memcmp(to,local_2c[0],__n);
    OPENSSL_cleanse(ptr,__n);
    CRYPTO_free(local_2c[0]);
    if (iVar1 != 0) goto LAB_00095c80;
    pXVar4 = pXVar3->algor;
    if (pXVar4->parameter != (ASN1_TYPE *)0x0) {
      iVar1 = ASN1_TYPE_get(pXVar4->parameter);
      if (iVar1 == 5) {
        pXVar4 = pXVar3->algor;
        goto LAB_00095d84;
      }
      iVar1 = 0xfb;
      goto LAB_00095c86;
    }
LAB_00095d84:
    iVar1 = OBJ_obj2nid(pXVar4->algorithm);
    if (type != iVar1) {
      if (((iVar1 == 8) && (type == 4)) || ((iVar1 == 7 && (type == 3)))) {
        fwrite("signature has problems, re-make with post SSLeay045\n",1,0x34,stderr);
        goto LAB_00095db4;
      }
      ERR_put_error(4,0x91,100,"rsa_sign.c",0x111);
      goto LAB_00095c96;
    }
LAB_00095db4:
    if ((m_length == pXVar3->digest->length) &&
       (iVar1 = memcmp(m,pXVar3->digest->data,m_length), iVar1 == 0)) {
      pXVar6 = (X509_SIG *)0x1;
    }
    else {
      pXVar6 = (X509_SIG *)0x0;
      ERR_put_error(4,0x91,0x68,"rsa_sign.c",0x121);
    }
  }
  else {
LAB_00095c80:
    iVar1 = 0xf1;
LAB_00095c86:
    ERR_put_error(4,0x91,0x68,"rsa_sign.c",iVar1);
LAB_00095c96:
    pXVar6 = (X509_SIG *)0x0;
  }
  X509_SIG_free(pXVar3);
  pXVar3 = pXVar6;
LAB_00095bf6:
  OPENSSL_cleanse(to,siglen);
  CRYPTO_free(to);
  return (int)pXVar3;
}

