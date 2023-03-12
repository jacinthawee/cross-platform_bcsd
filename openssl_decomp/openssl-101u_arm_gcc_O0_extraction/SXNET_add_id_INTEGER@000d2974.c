
int SXNET_add_id_INTEGER(SXNET **psx,ASN1_INTEGER *izone,char *user,int userlen)

{
  ASN1_STRING **ppAVar1;
  int iVar2;
  SXNET *val;
  int iVar3;
  SXNET *val_00;
  
  if ((izone == (ASN1_INTEGER *)0x0 || psx == (SXNET **)0x0) || (user == (char *)0x0)) {
    ERR_put_error(0x22,0x7e,0x6b,"v3_sxnet.c",0xbe);
    return 0;
  }
  if (userlen == -1) {
    userlen = strlen(user);
    if (0x40 < userlen) goto LAB_000d2a96;
  }
  else if (0x40 < userlen) {
LAB_000d2a96:
    ERR_put_error(0x22,0x7e,0x84,"v3_sxnet.c",0xc4);
    return 0;
  }
  val_00 = *psx;
  if (val_00 == (SXNET *)0x0) {
    val_00 = (SXNET *)ASN1_item_new((ASN1_ITEM *)PTR_SXNET_it_000d2ae0);
    val = val_00;
    if ((val_00 == (SXNET *)0x0) ||
       (val = (SXNET *)ASN1_INTEGER_set(val_00->version,0), val == (SXNET *)0x0)) goto LAB_000d29f0;
    *psx = val_00;
  }
  iVar3 = 0;
  do {
    iVar2 = sk_num((_STACK *)val_00->ids);
    if (iVar2 <= iVar3) goto LAB_000d29cc;
    ppAVar1 = (ASN1_STRING **)sk_value((_STACK *)val_00->ids,iVar3);
    iVar2 = ASN1_STRING_cmp(*ppAVar1,izone);
    iVar3 = iVar3 + 1;
  } while (iVar2 != 0);
  if (ppAVar1[1] != (ASN1_STRING *)0x0) {
    ERR_put_error(0x22,0x7e,0x85,"v3_sxnet.c",0xd0);
    return 0;
  }
LAB_000d29cc:
  val = (SXNET *)ASN1_item_new((ASN1_ITEM *)&SXNETID_it);
  if (val != (SXNET *)0x0) {
    if (userlen == 0xffffffff) {
      userlen = strlen(user);
    }
    iVar3 = ASN1_STRING_set((ASN1_STRING *)val->ids,user,userlen);
    if ((iVar3 != 0) && (iVar3 = sk_push((_STACK *)val_00->ids,val), iVar3 != 0)) {
      val->version = izone;
      return 1;
    }
  }
LAB_000d29f0:
  ERR_put_error(0x22,0x7e,0x41,"v3_sxnet.c",0xe1);
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&SXNETID_it);
  ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)PTR_SXNET_it_000d2ae0);
  *psx = (SXNET *)0x0;
  return 0;
}

