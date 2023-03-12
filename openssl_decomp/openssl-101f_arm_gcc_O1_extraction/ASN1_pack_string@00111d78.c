
ASN1_STRING * ASN1_pack_string(void *obj,undefined1 *i2d,ASN1_OCTET_STRING **oct)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  ASN1_STRING *local_1c [2];
  
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    pAVar2 = ASN1_STRING_new();
    if (pAVar2 == (ASN1_STRING *)0x0) {
LAB_00111dde:
      iVar1 = 0x81;
      goto LAB_00111de4;
    }
  }
  else {
    pAVar2 = *oct;
    if (pAVar2 == (ASN1_STRING *)0x0) {
      pAVar2 = ASN1_STRING_new();
      if (pAVar2 == (ASN1_STRING *)0x0) goto LAB_00111dde;
      *oct = pAVar2;
    }
  }
  iVar1 = (*(code *)i2d)(obj,0);
  pAVar2->length = iVar1;
  if (iVar1 == 0) {
    ERR_put_error(0xd,0x7c,0x70,"asn_pack.c",0x88);
    return (ASN1_STRING *)0x0;
  }
  local_1c[0] = (ASN1_STRING *)CRYPTO_malloc(iVar1,"asn_pack.c",0x8b);
  iVar1 = 0x8c;
  if (local_1c[0] != (ASN1_STRING *)0x0) {
    pAVar2->data = (uchar *)local_1c[0];
    (*(code *)i2d)(obj,local_1c);
    return pAVar2;
  }
LAB_00111de4:
  ERR_put_error(0xd,0x7c,0x41,"asn_pack.c",iVar1);
  return (ASN1_STRING *)0x0;
}

