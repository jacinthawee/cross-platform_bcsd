
uint dsa_sig_print(BIO *param_1,undefined4 param_2,ASN1_STRING *param_3,int param_4)

{
  DSA_SIG *a;
  int iVar1;
  uchar *buf;
  int iVar2;
  uint uVar3;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3 == (ASN1_STRING *)0x0) {
    iVar2 = BIO_puts(param_1,"\n");
    uVar3 = (uint)(0 < iVar2);
    goto LAB_081c3143;
  }
  local_24 = param_3->data;
  a = d2i_DSA_SIG((DSA_SIG **)0x0,&local_24,param_3->length);
  if (a == (DSA_SIG *)0x0) {
    uVar3 = X509_signature_dump(param_1,param_3,param_4);
    goto LAB_081c3143;
  }
  uVar3 = 0;
  if (a->r != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a->r);
    iVar2 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar2 = iVar1 + 7;
    }
    uVar3 = iVar2 >> 3;
  }
  if (a->s != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a->s);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar3 < (uint)(iVar2 >> 3)) {
      uVar3 = iVar2 >> 3;
    }
  }
  buf = (uchar *)CRYPTO_malloc(uVar3 + 10,"dsa_ameth.c",0x237);
  if (buf == (uchar *)0x0) {
    uVar3 = 0;
    ERR_put_error(10,0x7d,0x41,"dsa_ameth.c",0x23a);
  }
  else {
    iVar2 = BIO_write(param_1,&DAT_081f11d3,1);
    if (iVar2 == 1) {
      iVar2 = ASN1_bn_print(param_1,"r:   ",a->r,buf,param_4);
      if (iVar2 == 0) goto LAB_081c3127;
      iVar2 = ASN1_bn_print(param_1,"s:   ",a->s,buf,param_4);
      uVar3 = (uint)(iVar2 != 0);
    }
    else {
LAB_081c3127:
      uVar3 = 0;
    }
    CRYPTO_free(buf);
  }
  DSA_SIG_free(a);
LAB_081c3143:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

