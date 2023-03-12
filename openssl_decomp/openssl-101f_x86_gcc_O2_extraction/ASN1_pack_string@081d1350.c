
ASN1_STRING * ASN1_pack_string(void *obj,undefined1 *i2d,ASN1_OCTET_STRING **oct)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  int in_GS_OFFSET;
  int line;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    pAVar2 = ASN1_STRING_new();
    if (pAVar2 != (ASN1_STRING *)0x0) goto LAB_081d137e;
LAB_081d141f:
    line = 0x81;
    iVar1 = 0x41;
  }
  else {
    pAVar2 = *oct;
    if (pAVar2 == (ASN1_STRING *)0x0) {
      pAVar2 = ASN1_STRING_new();
      if (pAVar2 == (ASN1_STRING *)0x0) goto LAB_081d141f;
      *oct = pAVar2;
    }
LAB_081d137e:
    iVar1 = (*(code *)i2d)(obj,0);
    pAVar2->length = iVar1;
    if (iVar1 == 0) {
      line = 0x88;
      iVar1 = 0x70;
    }
    else {
      local_24 = (uchar *)CRYPTO_malloc(iVar1,"asn_pack.c",0x8b);
      if (local_24 != (uchar *)0x0) {
        pAVar2->data = local_24;
        (*(code *)i2d)(obj,&local_24);
        goto LAB_081d13c4;
      }
      line = 0x8c;
      iVar1 = 0x41;
    }
  }
  ERR_put_error(0xd,0x7c,iVar1,"asn_pack.c",line);
  pAVar2 = (ASN1_STRING *)0x0;
LAB_081d13c4:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

