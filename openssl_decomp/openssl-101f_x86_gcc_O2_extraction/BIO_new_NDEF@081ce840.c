
BIO * BIO_new_NDEF(BIO *out,ASN1_VALUE *val,ASN1_ITEM *it)

{
  void *pvVar1;
  ASN1_VALUE **ptr;
  BIO_METHOD *type;
  BIO *pBVar2;
  BIO *pBVar3;
  int iVar4;
  int in_GS_OFFSET;
  ASN1_VALUE *local_30;
  BIO *local_2c;
  BIO *local_28;
  ASN1_VALUE *local_24;
  int local_20;
  
  pvVar1 = it->funcs;
  local_30 = val;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((pvVar1 == (void *)0x0) || (*(int *)((int)pvVar1 + 0x10) == 0)) {
    pBVar2 = (BIO *)0x0;
    ERR_put_error(0xd,0xd0,0xca,"bio_ndef.c",0x6e);
    goto LAB_081ce97a;
  }
  ptr = (ASN1_VALUE **)CRYPTO_malloc(0x18,"bio_ndef.c",0x71);
  type = BIO_f_asn1();
  pBVar2 = BIO_new(type);
  pBVar3 = BIO_push(pBVar2,out);
  if ((ptr == (ASN1_VALUE **)0x0) || (pBVar2 == (BIO *)0x0)) {
    if (pBVar2 != (BIO *)0x0) goto LAB_081ce95c;
  }
  else {
    if (pBVar3 != (BIO *)0x0) {
      BIO_asn1_set_prefix(pBVar2,ndef_prefix,ndef_prefix_free);
      BIO_asn1_set_suffix(pBVar2,ndef_suffix,ndef_suffix_free);
      local_28 = (BIO *)0x0;
      local_24 = (ASN1_VALUE *)0x0;
      local_2c = pBVar3;
      iVar4 = (**(code **)((int)pvVar1 + 0x10))(10,&local_30,it,&local_2c);
      if (0 < iVar4) {
        ptr[1] = (ASN1_VALUE *)it;
        *ptr = local_30;
        ptr[3] = (ASN1_VALUE *)pBVar3;
        ptr[2] = (ASN1_VALUE *)local_28;
        ptr[4] = local_24;
        BIO_ctrl(pBVar2,0x99,0,ptr);
        pBVar2 = local_28;
        goto LAB_081ce97a;
      }
    }
LAB_081ce95c:
    BIO_free(pBVar2);
  }
  pBVar2 = (BIO *)0x0;
  if (ptr != (ASN1_VALUE **)0x0) {
    CRYPTO_free(ptr);
  }
LAB_081ce97a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pBVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

