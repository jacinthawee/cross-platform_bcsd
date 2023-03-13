
int RSA_verify(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  _func_1627 *p_Var1;
  uchar *ptr;
  int iVar2;
  uint uVar3;
  uchar *to;
  size_t __n;
  X509_SIG *a;
  size_t len;
  X509_ALGOR *pXVar4;
  int in_GS_OFFSET;
  int iVar5;
  int line;
  uchar *local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((*(byte *)&rsa->flags & 0x40) != 0) &&
     (p_Var1 = rsa->meth->rsa_verify, p_Var1 != (_func_1627 *)0x0)) {
    iVar2 = (*p_Var1)(type,m,m_length,sigbuf,siglen,rsa);
    goto LAB_0810a306;
  }
  uVar3 = RSA_size(rsa);
  if (siglen == uVar3) {
    to = (uchar *)CRYPTO_malloc(siglen,"rsa_sign.c",199);
    if (to != (uchar *)0x0) {
      if ((type == 0x72) && (m_length != 0x24)) {
        iVar2 = 0xcd;
        iVar5 = 0x83;
LAB_0810a375:
        ERR_put_error(4,0x91,iVar5,"rsa_sign.c",iVar2);
LAB_0810a384:
        iVar2 = 0;
      }
      else {
        iVar2 = 0;
        __n = RSA_public_decrypt(siglen,sigbuf,to,rsa,1);
        if (0 < (int)__n) {
          if ((type == 0x5f) && (__n == 0x12)) {
            if ((*to == '\x04') && (to[1] == '\x10')) {
              iVar2 = 1;
              iVar5 = memcmp(m,to + 2,0x10);
              if (iVar5 != 0) {
                iVar2 = 0xde;
                goto LAB_0810a4a0;
              }
              goto LAB_0810a386;
            }
          }
          else if (type == 0x72) {
            if (__n == 0x24) {
              iVar2 = 1;
              iVar5 = memcmp(to,m,0x24);
              if (iVar5 == 0) goto LAB_0810a386;
            }
            iVar2 = 0xe5;
LAB_0810a4a0:
            iVar5 = 0x68;
            goto LAB_0810a375;
          }
          local_28 = to;
          a = d2i_X509_SIG((X509_SIG **)0x0,&local_28,__n);
          if (a == (X509_SIG *)0x0) goto LAB_0810a384;
          if (local_28 == to + __n) {
            local_24 = (uchar *)0x0;
            len = i2d_X509_SIG(a,&local_24);
            ptr = local_24;
            if ((int)len < 1) goto LAB_0810a42f;
            if (__n != len) {
              OPENSSL_cleanse(local_24,len);
              CRYPTO_free(local_24);
              goto LAB_0810a42f;
            }
            iVar2 = memcmp(to,local_24,__n);
            OPENSSL_cleanse(ptr,__n);
            CRYPTO_free(local_24);
            if (iVar2 != 0) goto LAB_0810a42f;
            pXVar4 = a->algor;
            if (pXVar4->parameter != (ASN1_TYPE *)0x0) {
              iVar2 = ASN1_TYPE_get(pXVar4->parameter);
              if (iVar2 == 5) {
                pXVar4 = a->algor;
                goto LAB_0810a5ae;
              }
              line = 0xfb;
              iVar5 = 0x68;
              goto LAB_0810a442;
            }
LAB_0810a5ae:
            iVar2 = OBJ_obj2nid(pXVar4->algorithm);
            if (type != iVar2) {
              if (((type != 4) || (iVar2 != 8)) && ((type != 3 || (iVar2 != 7)))) {
                line = 0x111;
                iVar5 = 100;
                goto LAB_0810a442;
              }
              fwrite("signature has problems, re-make with post SSLeay045\n",1,0x34,stderr);
            }
            if (m_length == a->digest->length) {
              iVar2 = 1;
              iVar5 = memcmp(m,a->digest->data,m_length);
              if (iVar5 != 0) goto LAB_0810a639;
            }
            else {
LAB_0810a639:
              iVar2 = 0;
              ERR_put_error(4,0x91,0x68,"rsa_sign.c",0x121);
            }
          }
          else {
LAB_0810a42f:
            line = 0xf1;
            iVar5 = 0x68;
LAB_0810a442:
            iVar2 = 0;
            ERR_put_error(4,0x91,iVar5,"rsa_sign.c",line);
          }
          X509_SIG_free(a);
        }
      }
LAB_0810a386:
      OPENSSL_cleanse(to,siglen);
      CRYPTO_free(to);
      goto LAB_0810a306;
    }
    iVar5 = 0xc9;
    iVar2 = 0x41;
  }
  else {
    iVar5 = 0xba;
    iVar2 = 0x77;
  }
  ERR_put_error(4,0x91,iVar2,"rsa_sign.c",iVar5);
  iVar2 = 0;
LAB_0810a306:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

