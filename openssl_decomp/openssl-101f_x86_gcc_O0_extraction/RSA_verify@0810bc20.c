
int RSA_verify(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  _func_1627 *p_Var1;
  int iVar2;
  uint uVar3;
  uchar *to;
  X509_SIG *a;
  X509_ALGOR *pXVar4;
  int in_GS_OFFSET;
  int iVar5;
  int iVar6;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((*(byte *)&rsa->flags & 0x40) != 0) &&
     (p_Var1 = rsa->meth->rsa_verify, p_Var1 != (_func_1627 *)0x0)) {
    iVar2 = (*p_Var1)(type,m,m_length,sigbuf,siglen,rsa);
    goto LAB_0810bc66;
  }
  uVar3 = RSA_size(rsa);
  if (siglen == uVar3) {
    to = (uchar *)CRYPTO_malloc(siglen,"rsa_sign.c",0xbd);
    if (to != (uchar *)0x0) {
      if ((type == 0x72) && (m_length != 0x24)) {
        iVar6 = 0xc4;
        iVar5 = 0x83;
LAB_0810bcd5:
        iVar2 = 0;
        ERR_put_error(4,0x91,iVar5,"rsa_sign.c",iVar6);
      }
      else {
        iVar2 = 0;
        iVar5 = RSA_public_decrypt(siglen,sigbuf,to,rsa,1);
        if (0 < iVar5) {
          if ((type == 0x5f) && (iVar5 == 0x12)) {
            if ((*to == '\x04') && (to[1] == '\x10')) {
              iVar2 = 1;
              iVar6 = memcmp(m,to + 2,0x10);
              if (iVar6 != 0) {
                iVar2 = 0;
                ERR_put_error(4,0x91,0x68,"rsa_sign.c",0xd6);
              }
            }
          }
          else {
            if (type == 0x72) {
              if (iVar5 == 0x24) {
                iVar2 = 1;
                iVar5 = memcmp(to,m,0x24);
                if (iVar5 == 0) goto LAB_0810bce6;
              }
              iVar6 = 0xde;
              iVar5 = 0x68;
              goto LAB_0810bcd5;
            }
            iVar2 = 0;
          }
          local_24 = to;
          a = d2i_X509_SIG((X509_SIG **)0x0,&local_24,iVar5);
          if (a != (X509_SIG *)0x0) {
            if (local_24 == to + iVar5) {
              pXVar4 = a->algor;
              if (pXVar4->parameter != (ASN1_TYPE *)0x0) {
                iVar5 = ASN1_TYPE_get(pXVar4->parameter);
                if (iVar5 != 5) {
                  iVar5 = 0xf2;
                  goto LAB_0810bd9a;
                }
                pXVar4 = a->algor;
              }
              iVar5 = OBJ_obj2nid(pXVar4->algorithm);
              if (type != iVar5) {
                if (((type == 4) && (iVar5 == 8)) || ((type == 3 && (iVar5 == 7)))) {
                  fwrite("signature has problems, re-make with post SSLeay045\n",1,0x34,stderr);
                  goto LAB_0810bef6;
                }
                iVar5 = 0x10d;
                iVar6 = 100;
                goto LAB_0810bda1;
              }
LAB_0810bef6:
              if (m_length != a->digest->length) {
LAB_0810bf3b:
                iVar5 = 0x123;
                goto LAB_0810bd9a;
              }
              iVar5 = memcmp(m,a->digest->data,m_length);
              if (iVar5 != 0) goto LAB_0810bf3b;
              iVar2 = 1;
            }
            else {
              iVar5 = 0xe9;
LAB_0810bd9a:
              iVar6 = 0x68;
LAB_0810bda1:
              ERR_put_error(4,0x91,iVar6,"rsa_sign.c",iVar5);
            }
            X509_SIG_free(a);
          }
        }
      }
LAB_0810bce6:
      OPENSSL_cleanse(to,siglen);
      CRYPTO_free(to);
      goto LAB_0810bc66;
    }
    iVar5 = 0xc0;
    iVar2 = 0x41;
  }
  else {
    iVar5 = 0xaf;
    iVar2 = 0x77;
  }
  ERR_put_error(4,0x91,iVar2,"rsa_sign.c",iVar5);
  iVar2 = 0;
LAB_0810bc66:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

