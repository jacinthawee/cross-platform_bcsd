
int SXNET_add_id_INTEGER(SXNET **psx,ASN1_INTEGER *izone,char *user,int userlen)

{
  ASN1_STRING **ppAVar1;
  int iVar2;
  ASN1_INTEGER **val;
  SXNET *val_00;
  int iVar3;
  
  if ((izone == (ASN1_INTEGER *)0x0 || user == (char *)0x0) || (psx == (SXNET **)0x0)) {
    iVar2 = 0xbe;
    iVar3 = 0x6b;
    goto LAB_0816f21f;
  }
  if (userlen == -1) {
    userlen = strlen(user);
    if (0x40 < userlen) goto LAB_0816f2ce;
  }
  else if (0x40 < userlen) {
LAB_0816f2ce:
    iVar2 = 0xc4;
    iVar3 = 0x84;
LAB_0816f21f:
    ERR_put_error(0x22,0x7e,iVar3,"v3_sxnet.c",iVar2);
    return 0;
  }
  val_00 = *psx;
  if (val_00 == (SXNET *)0x0) {
    val_00 = (SXNET *)ASN1_item_new((ASN1_ITEM *)SXNET_it);
    if ((val_00 == (SXNET *)0x0) || (iVar3 = ASN1_INTEGER_set(val_00->version,0), iVar3 == 0)) {
      val = (ASN1_INTEGER **)0x0;
      goto LAB_0816f1c0;
    }
    *psx = val_00;
  }
  for (iVar3 = 0; iVar2 = sk_num((_STACK *)val_00->ids), iVar3 < iVar2; iVar3 = iVar3 + 1) {
    ppAVar1 = (ASN1_STRING **)sk_value((_STACK *)val_00->ids,iVar3);
    iVar2 = ASN1_STRING_cmp(*ppAVar1,izone);
    if (iVar2 == 0) {
      if (ppAVar1[1] != (ASN1_STRING *)0x0) {
        ERR_put_error(0x22,0x7e,0x85,"v3_sxnet.c",0xd0);
        return 0;
      }
      break;
    }
  }
  val = (ASN1_INTEGER **)ASN1_item_new((ASN1_ITEM *)SXNETID_it);
  if (val != (ASN1_INTEGER **)0x0) {
    if (userlen == -1) {
      userlen = strlen(user);
    }
    iVar3 = ASN1_STRING_set(val[1],user,userlen);
    if ((iVar3 != 0) && (iVar3 = sk_push((_STACK *)val_00->ids,val), iVar3 != 0)) {
      *val = izone;
      return 1;
    }
  }
LAB_0816f1c0:
  ERR_put_error(0x22,0x7e,0x41,"v3_sxnet.c",0xe1);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)SXNETID_it);
  ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)SXNET_it);
  *psx = (SXNET *)0x0;
  return 0;
}

