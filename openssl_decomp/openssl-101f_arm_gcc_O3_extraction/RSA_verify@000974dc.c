
int RSA_verify(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  int iVar1;
  uint uVar2;
  uchar *to;
  X509_SIG *a;
  int iVar3;
  X509_ALGOR *pXVar4;
  _func_1627 *p_Var5;
  uint uVar6;
  uchar *local_2c [2];
  
  if ((rsa->flags << 0x19 < 0) && (p_Var5 = rsa->meth->rsa_verify, p_Var5 != (_func_1627 *)0x0)) {
    iVar1 = (*p_Var5)(type,m,m_length,sigbuf,siglen,rsa);
    return iVar1;
  }
  uVar2 = RSA_size(rsa);
  if (siglen != uVar2) {
    ERR_put_error(4,0x91,0x77,"rsa_sign.c",0xaf);
    return 0;
  }
  to = (uchar *)CRYPTO_malloc(uVar2,"rsa_sign.c",0xbd);
  if (to == (uchar *)0x0) {
    ERR_put_error(4,0x91,0x41,"rsa_sign.c",0xc0);
    return 0;
  }
  uVar2 = count_leading_zeroes(type + -0x72);
  uVar2 = uVar2 >> 5;
  if (m_length == 0x24) {
    uVar6 = 0;
  }
  else {
    uVar6 = uVar2 & 1;
  }
  if (uVar6 != 0) {
    ERR_put_error(4,0x91,0x83,"rsa_sign.c",0xc4);
    uVar6 = 0;
    goto LAB_00097560;
  }
  iVar1 = RSA_public_decrypt(siglen,sigbuf,to,rsa,1);
  if (iVar1 < 1) goto LAB_00097560;
  if (iVar1 == 0x12 && type == 0x5f) {
    uVar2 = uVar6;
    if (((*to == '\x04') && (to[1] == '\x10')) &&
       (iVar3 = memcmp(m,to + 2,0x10), uVar2 = 1, iVar3 != 0)) {
      ERR_put_error(4,0x91,0x68,"rsa_sign.c",0xd6);
      uVar2 = uVar6;
    }
  }
  else if (uVar2 != 0) {
    if ((iVar1 != 0x24) || (iVar1 = memcmp(to,m,0x24), uVar6 = 1, iVar1 != 0)) {
      uVar6 = 0;
      ERR_put_error(4,0x91,0x68,"rsa_sign.c",0xde);
    }
    goto LAB_00097560;
  }
  local_2c[0] = to;
  a = d2i_X509_SIG((X509_SIG **)0x0,local_2c,iVar1);
  uVar6 = uVar2;
  if (a == (X509_SIG *)0x0) goto LAB_00097560;
  if (local_2c[0] == to + iVar1) {
    pXVar4 = a->algor;
    if (pXVar4->parameter != (ASN1_TYPE *)0x0) {
      iVar1 = ASN1_TYPE_get(pXVar4->parameter);
      if (iVar1 != 5) {
        iVar1 = 0xf2;
        goto LAB_000975e8;
      }
      pXVar4 = a->algor;
    }
    iVar1 = OBJ_obj2nid(pXVar4->algorithm);
    if (type == iVar1) {
LAB_000976bc:
      if ((m_length != a->digest->length) ||
         (iVar1 = memcmp(m,a->digest->data,m_length), iVar1 != 0)) {
        iVar1 = 0x123;
        goto LAB_000975e8;
      }
      uVar2 = 1;
    }
    else {
      if ((iVar1 == 8 && type == 4) || (iVar1 == 7 && type == 3)) {
        fwrite("signature has problems, re-make with post SSLeay045\n",1,0x34,stderr);
        goto LAB_000976bc;
      }
      ERR_put_error(4,0x91,100,"rsa_sign.c",0x10d);
    }
  }
  else {
    iVar1 = 0xe9;
LAB_000975e8:
    ERR_put_error(4,0x91,0x68,"rsa_sign.c",iVar1);
  }
  X509_SIG_free(a);
  uVar6 = uVar2;
LAB_00097560:
  OPENSSL_cleanse(to,siglen);
  CRYPTO_free(to);
  return uVar6;
}

