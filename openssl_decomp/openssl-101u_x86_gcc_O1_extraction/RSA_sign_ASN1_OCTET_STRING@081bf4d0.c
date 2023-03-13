
int RSA_sign_ASN1_OCTET_STRING(int type,uchar *m,uint m_length,uchar *sigret,uint *siglen,RSA *rsa)

{
  int iVar1;
  int iVar2;
  uchar *from;
  uint uVar3;
  int in_GS_OFFSET;
  uchar *local_34;
  ASN1_OCTET_STRING local_30;
  int local_20;
  
  local_30.type = 4;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30.length = m_length;
  local_30.data = m;
  iVar1 = i2d_ASN1_OCTET_STRING(&local_30,(uchar **)0x0);
  iVar2 = RSA_size(rsa);
  if (iVar1 < iVar2 + -10) {
    from = (uchar *)CRYPTO_malloc(iVar2 + 1U,"rsa_saos.c",0x56);
    if (from != (uchar *)0x0) {
      local_34 = from;
      i2d_ASN1_OCTET_STRING(&local_30,&local_34);
      uVar3 = RSA_private_encrypt(iVar1,from,sigret,rsa,1);
      if (0 < (int)uVar3) {
        *siglen = uVar3;
      }
      uVar3 = (uint)(0 < (int)uVar3);
      OPENSSL_cleanse(from,iVar2 + 1U);
      CRYPTO_free(from);
      goto LAB_081bf5aa;
    }
    iVar2 = 0x58;
    iVar1 = 0x41;
  }
  else {
    iVar2 = 0x53;
    iVar1 = 0x70;
  }
  ERR_put_error(4,0x76,iVar1,"rsa_saos.c",iVar2);
  uVar3 = 0;
LAB_081bf5aa:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

