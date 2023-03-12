
undefined4 dsa_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  DSA *a;
  uchar *penc;
  ASN1_STRING *a_00;
  int iVar1;
  ASN1_OBJECT *aobj;
  undefined4 uVar2;
  int iVar3;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (uchar *)0x0;
  a = *(DSA **)(param_2 + 0x14);
  if ((((*(int *)(param_2 + 0x18) == 0) || (a->p == (BIGNUM *)0x0)) || (a->q == (BIGNUM *)0x0)) ||
     (a->g == (BIGNUM *)0x0)) {
    iVar3 = -1;
    a_00 = (ASN1_STRING *)0x0;
LAB_081c3b47:
    a->write_params = 0;
    iVar1 = i2d_DSAPublicKey(a,&local_24);
    penc = local_24;
    if (iVar1 < 1) {
      ERR_put_error(10,0x76,0x41,"dsa_ameth.c",0xa9);
    }
    else {
      aobj = OBJ_nid2obj(0x74);
      iVar3 = X509_PUBKEY_set0_param(param_1,aobj,iVar3,a_00,penc,iVar1);
      uVar2 = 1;
      if (iVar3 != 0) goto LAB_081c3b1e;
    }
    if (local_24 != (uchar *)0x0) {
LAB_081c3b00:
      CRYPTO_free(local_24);
    }
    if (a_00 != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(a_00);
    }
  }
  else {
    a_00 = ASN1_STRING_new();
    iVar3 = 0x10;
    iVar1 = i2d_DSAparams(a,&a_00->data);
    a_00->length = iVar1;
    if (0 < iVar1) goto LAB_081c3b47;
    ERR_put_error(10,0x76,0x41,"dsa_ameth.c",0x9a);
    if (local_24 != (uchar *)0x0) {
      a_00 = (ASN1_STRING *)0x0;
      goto LAB_081c3b00;
    }
  }
  uVar2 = 0;
LAB_081c3b1e:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

