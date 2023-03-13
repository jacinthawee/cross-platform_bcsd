
int RSA_sign(int type,uchar *m,uint m_length,uchar *sigret,uint *siglen,RSA *rsa)

{
  _func_1626 *p_Var1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uchar *from;
  uint uVar5;
  int in_GS_OFFSET;
  uchar *local_4c;
  X509_SIG local_48;
  ASN1_TYPE local_40;
  X509_ALGOR local_38;
  ASN1_OCTET_STRING local_30;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((*(byte *)&rsa->flags & 0x40) != 0) &&
     (p_Var1 = rsa->meth->rsa_sign, p_Var1 != (_func_1626 *)0x0)) {
    uVar2 = (*p_Var1)(type,m,m_length,sigret,siglen,rsa);
    goto LAB_08109b89;
  }
  if (type == 0x72) {
    if (m_length == 0x24) {
      iVar3 = RSA_size(rsa);
      if (0x2e < iVar3) {
        uVar5 = RSA_private_encrypt(0x24,m,sigret,rsa,1);
        uVar2 = 0;
        if (0 < (int)uVar5) {
          *siglen = uVar5;
          uVar2 = 1;
        }
        goto LAB_08109b89;
      }
LAB_08109d08:
      iVar4 = 0x7a;
      iVar3 = 0x70;
    }
    else {
      iVar4 = 0x5d;
      iVar3 = 0x83;
    }
  }
  else {
    local_48.algor = &local_38;
    local_38.algorithm = OBJ_nid2obj(type);
    if ((local_48.algor)->algorithm == (ASN1_OBJECT *)0x0) {
      iVar4 = 0x66;
      iVar3 = 0x75;
    }
    else {
      uVar2 = (local_48.algor)->algorithm->length;
      if (uVar2 == 0) {
        ERR_put_error(4,0x75,0x74,"rsa_sign.c",0x6b);
        goto LAB_08109b89;
      }
      local_40.value.ptr = (char *)0x0;
      local_40.type = 5;
      (local_48.algor)->parameter = &local_40;
      local_48.digest = &local_30;
      local_30.data = m;
      local_30.length = m_length;
      iVar3 = i2d_X509_SIG(&local_48,(uchar **)0x0);
      iVar4 = RSA_size(rsa);
      if (iVar4 + -10 <= iVar3) goto LAB_08109d08;
      from = (uchar *)CRYPTO_malloc(iVar4 + 1U,"rsa_sign.c",0x7e);
      if (from != (uchar *)0x0) {
        local_4c = from;
        i2d_X509_SIG(&local_48,&local_4c);
        uVar2 = RSA_private_encrypt(iVar3,from,sigret,rsa,1);
        if (0 < (int)uVar2) {
          *siglen = uVar2;
        }
        uVar2 = (uint)(0 < (int)uVar2);
        OPENSSL_cleanse(from,iVar4 + 1U);
        CRYPTO_free(from);
        goto LAB_08109b89;
      }
      iVar4 = 0x80;
      iVar3 = 0x41;
    }
  }
  ERR_put_error(4,0x75,iVar3,"rsa_sign.c",iVar4);
  uVar2 = 0;
LAB_08109b89:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

