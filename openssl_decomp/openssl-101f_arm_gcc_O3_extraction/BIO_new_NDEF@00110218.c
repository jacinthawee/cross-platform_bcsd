
BIO * BIO_new_NDEF(BIO *out,ASN1_VALUE *val,ASN1_ITEM *it)

{
  BIO *parg;
  BIO_METHOD *type;
  BIO *b;
  BIO *pBVar1;
  int iVar2;
  void *pvVar3;
  BIO *larg;
  BIO_METHOD *local_34 [2];
  BIO *local_2c;
  BIO *local_28;
  BIO *local_24;
  
  pvVar3 = it->funcs;
  local_34[0] = (BIO_METHOD *)val;
  if ((pvVar3 == (void *)0x0) || (*(int *)((int)pvVar3 + 0x10) == 0)) {
    ERR_put_error(0xd,0xd0,0xca,"bio_ndef.c",0x6e);
    return (BIO *)0x0;
  }
  parg = (BIO *)CRYPTO_malloc(0x18,"bio_ndef.c",0x71);
  type = BIO_f_asn1();
  b = BIO_new(type);
  pBVar1 = BIO_push(b,out);
  larg = (BIO *)(uint)(parg == (BIO *)0x0 || b == (BIO *)0x0);
  if (parg != (BIO *)0x0 && b != (BIO *)0x0) {
    if (pBVar1 != (BIO *)0x0) {
      BIO_asn1_set_prefix(b,ndef_prefix + 1,ndef_prefix_free + 1);
      BIO_asn1_set_suffix(b,ndef_suffix + 1,ndef_suffix_free + 1);
      local_2c = pBVar1;
      local_28 = larg;
      local_24 = larg;
      iVar2 = (**(code **)((int)pvVar3 + 0x10))(10,local_34,it,&local_2c);
      if (0 < iVar2) {
        parg->cb_arg = (char *)local_28;
        parg->callback = (_func_603 *)it;
        parg->init = (int)pBVar1;
        parg->method = local_34[0];
        parg->shutdown = (int)local_24;
        BIO_ctrl(b,0x99,(long)larg,parg);
        return local_28;
      }
    }
  }
  else if (b == (BIO *)0x0) goto LAB_0011026e;
  BIO_free(b);
LAB_0011026e:
  if (parg != (BIO *)0x0) {
    CRYPTO_free(parg);
    parg = (BIO *)0x0;
  }
  return parg;
}

