
int RSA_sign(int type,uchar *m,uint m_length,uchar *sigret,uint *siglen,RSA *rsa)

{
  int iVar1;
  ASN1_OBJECT *ptr;
  uint uVar2;
  _func_1626 *p_Var3;
  ASN1_OBJECT *local_4c;
  X509_SIG local_48;
  ASN1_TYPE local_40;
  X509_ALGOR local_38;
  ASN1_OCTET_STRING local_30;
  
  if ((rsa->flags << 0x19 < 0) && (p_Var3 = rsa->meth->rsa_sign, p_Var3 != (_func_1626 *)0x0)) {
    iVar1 = (*p_Var3)(type,m,m_length,sigret,siglen,rsa);
    return iVar1;
  }
  if (type == 0x72) {
    if (m_length != 0x24) {
      ERR_put_error(4,0x75,0x83,"rsa_sign.c",0x5d);
      return 0;
    }
    iVar1 = RSA_size(rsa);
    if (iVar1 < 0x2f) goto LAB_00095812;
    ptr = (ASN1_OBJECT *)0x0;
  }
  else {
    local_48.algor = &local_38;
    local_38.algorithm = OBJ_nid2obj(type);
    if ((local_48.algor)->algorithm == (ASN1_OBJECT *)0x0) {
      ERR_put_error(4,0x75,0x75,"rsa_sign.c",0x66);
      return 0;
    }
    if ((local_48.algor)->algorithm->length == 0) {
      ERR_put_error(4,0x75,0x74,"rsa_sign.c",0x6b);
      return 0;
    }
    local_40.value.ptr = (char *)0x0;
    (local_48.algor)->parameter = &local_40;
    local_48.digest = &local_30;
    local_40.type = 5;
    local_30.length = m_length;
    local_30.data = m;
    m_length = i2d_X509_SIG(&local_48,(uchar **)0x0);
    iVar1 = RSA_size(rsa);
    if (iVar1 + -10 <= (int)m_length) {
LAB_00095812:
      ERR_put_error(4,0x75,0x70,"rsa_sign.c",0x7a);
      return 0;
    }
    ptr = (ASN1_OBJECT *)CRYPTO_malloc(iVar1 + 1,"rsa_sign.c",0x7e);
    if (ptr == (ASN1_OBJECT *)0x0) {
      ERR_put_error(4,0x75,0x41,"rsa_sign.c",0x80);
      return 0;
    }
    local_4c = ptr;
    i2d_X509_SIG(&local_48,(uchar **)&local_4c);
    m = (uchar *)ptr;
  }
  uVar2 = RSA_private_encrypt(m_length,m,sigret,rsa,1);
  if (0 < (int)uVar2) {
    rsa = (RSA *)siglen;
  }
  if (0 < (int)uVar2) {
    rsa->pad = uVar2;
  }
  if (type == 0x72) {
    return (uint)(0 < (int)uVar2);
  }
  OPENSSL_cleanse(ptr,iVar1 + 1);
  CRYPTO_free(ptr);
  return (uint)(0 < (int)uVar2);
}

